#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <time.h>
#include <sys/wait.h>
#define BILLION 1000000000L

#define MAX_CHARS 256

void flushResultToResultsFile(char* name,char* retCode,int score)
{
	FILE *file=fopen("results.csv","a");
	if(file == NULL)
	{
		write(2,"File Open Error\n",16);
		exit(0);
	}
	fprintf(file,"%s,%d,%s\n",name,score,retCode);
	fclose(file);
}

int calculatePenalty(int depth)
{
	int penalty = 100 - (10 *(depth-1));
	if(penalty < 0)
	{
		penalty = 0;
	}
	return penalty;
}


void checkRetValAndflushResultToResultsFile(char* name,int retVal,int depth)
{
	if(retVal==1)
	{
		// Wrong result
		flushResultToResultsFile(name,"BAD_OUTPUT",0);
	}
	else if(retVal==3)
	{ //Similar Output
		if(depth==1)
		{
			flushResultToResultsFile(name,"SIMILAR_OUTPUT",80);
		}
		else
		{
			// Similar Output but wrong directory
			flushResultToResultsFile(name,"WRONG_DIRECTORY",calculatePenalty(depth));
		}
	}
	else if(retVal==2)
	{
		//Correct output
		if(depth==1)
		{
			flushResultToResultsFile(name,"GREAT_JOB",100);
		}
		else
		{
			// Correct Output but wrong directory
			flushResultToResultsFile(name,"WRONG_DIRECTORY",calculatePenalty(depth));
		}
	}

}

char outputFile[256];
char inputFile[256];
char outputExe[256];

void executeSourcePart2(char *fileName, char *curFol,char *name,char *ipFile,char *opFile,int depth)
{

	pid_t c_pid,pid;
	int status1,status2,status3;
	char execString[1500];
	struct timespec start,end;
	int diff;

	printf("Student name = %s\n",name);

	// Step 1 Fork
	c_pid = fork();

	if(c_pid == 0)
	{
		// Child Process created

		// Step 1: Call GCC Compiler after properly building the string
		// E.g: command -  gcc -o objectFileName sourceFileName

		char* my_args[4];
		my_args[0] = "gcc";
		my_args[1] = "-o";
		strcpy(outputFile,curFol);
		strcat(outputFile,"/test");
		my_args[2]  = outputFile;
		my_args[3]  = fileName;

		FILE *file1;
		file1 = fopen("gccErrorResult","a");
		if(file1 == NULL)
		{
			write(2,"File Open Error\n",16);
			exit(0);
		}
		dup2(fileno(file1),STDOUT_FILENO);
		dup2(fileno(file1),STDERR_FILENO);
		fclose(file1);

		execvp(my_args[0],my_args);
		printf("If here that means GCC Compiler failure \n");
	}
	else if(c_pid > 0)
	{
		// Parent Process is here

		if((pid = wait(&status1)) < 0)
		{
			printf("Wait error parent \n");
		}
	    //printf("Parent: finished\n");
	}
	// capture return value from child process
    if ( WIFEXITED(status1) )
    {
        const int es = WEXITSTATUS(status1);
        if(es == 1)
        {
    		flushResultToResultsFile(name,"COMPILATION_ERROR",0);
    		return;
        }
        printf("GCC Compilation exit status was %d\n", es);
    }
	//printf("First step is done\n");

	// Step 2 Fork
	c_pid = fork();
	clock_gettime(CLOCK_MONOTONIC,&start); // start time
	if(c_pid == 0)
	{
		// Child Process created

		//  Step 2: Running the generated outputExe given input file
		// E.g: command -  ./outputExe <inputFile >outputFile
		char* my_args[1];
		strcpy(outputFile,curFol);
		strcat(outputFile,"/test");
		//printf("outputFile = %s\n",outputFile);
		my_args[0] = outputFile;

		FILE *file1,*file2;
		file1 = fopen(ipFile,"r");
		file2 = fopen("studsTestOut","w");
		if(file1 == NULL || file2 == NULL)
		{
			write(2,"File Open Error\n",16);
			exit(0);
		}
		dup2(fileno(file1),STDIN_FILENO);
		dup2(fileno(file2),STDOUT_FILENO);
		fclose(file1);
		fclose(file2);

		execvp(my_args[0],my_args);
		printf("If here that means Running the generated outputExe failure \n");
	}
	else if(c_pid > 0)
	{
		// parent process is here
		if((pid = wait(&status2)) < 0)
		{
			printf("Wait error parent \n");
		}
	    //printf("Parent: finished\n");
	}
	clock_gettime(CLOCK_MONOTONIC,&end); // end time
	diff = (end.tv_sec-start.tv_sec) + (end.tv_nsec - start.tv_nsec)/BILLION;
	if(diff > 5)
	{
		flushResultToResultsFile(name,"TIMEOUT",0);
		return;
	}

	// capture return value from child process
    if ( WIFEXITED(status2) )
    {
        const int es = WEXITSTATUS(status2);
        printf("Running the compiled output exit status was %d\n", es);
    }
	//printf("Second step is done\n");

	// Step 3 Fork
	c_pid = fork();
	if(c_pid == 0)
	{
		// Child Process created
		// Step 3: Finally use the previous parts to check if files are identical/similar/different

		char* my_args[3];
		my_args[0] = "./comp.out";
		my_args[1] = "studsTestOut";
		my_args[2] = opFile;

		execvp(my_args[0],my_args);
		printf("If here that means Running the File Comparison result failure \n");
	}
	else if(c_pid > 0)
	{
		// parent process is here
		if((pid = wait(&status3)) < 0)
		{
			printf("Wait error parent \n");
		}
	    //printf("Parent: finished\n");
	}

	// capture return value from child process
    if ( WIFEXITED(status3) )
    {
        const int es = WEXITSTATUS(status3);
    	checkRetValAndflushResultToResultsFile(name,es,depth);
        printf("File Comparison result was %d\n", es);
    }

}

void executeSource(char *fileName, char *curFol,char *name,
		char *ipFile,char *opFile,int depth){

	int retVal= -1;
	struct timeval startTime, endTime;
	int timeTaken;
	char execString[1500];

	// Step 1: Call GCC Compiler after properly building the string
	strcpy(execString,"gcc -o ");
	strcat(execString,"\"");
	strcat(execString,curFol);
	strcat(execString,"/test");
	strcat(execString,"\"");
	strcat(execString," ");
	strcat(execString,"\"");
	strcat(execString,fileName);
	strcat(execString,"\"");
	//printf("ExecString for compilation = %s\n",execString);

	retVal = system(execString)/256;

	if(retVal != 0)
	{
		flushResultToResultsFile(name,"COMPILATION_ERROR",0);
		return;
	}

	// Step 2: Running the generated outputExe given input file

	// running the compiled output with argument as input and storing the output result in tempo
	gettimeofday(&startTime, NULL);
	strcpy(execString,"\"");
	strcat(execString,curFol);
	strcat(execString,"/test");
	strcat(execString,"\"");
	strcat(execString,"< ");
	strcat(execString,ipFile);
	strcat(execString," > genOpFile");
	system(execString);
	gettimeofday(&endTime, NULL);
	//printf("ExecString for Running generated outputExe = %s\n",execString);

	timeTaken = ((endTime.tv_sec + endTime.tv_usec/1000000) - (startTime.tv_sec + startTime.tv_usec/1000000));
	if(timeTaken > 5)
	{
		flushResultToResultsFile(name,"TIMEOUT",0);
		return;
	}

	// Step 3: Finally use the previous parts to check if files are identical/similar/different
	strcpy(execString,"./comp.out genOpFile ");
	strcat(execString,opFile);
	retVal=system(execString)/256;

	checkRetValAndflushResultToResultsFile(name,retVal,depth);
}

int lookForSourceFilesAndExecute(char * folderLoc, char *input,char *output,int depth,char *studentName)
{
    DIR *directory;
	int retVal=0;
    struct dirent *entry;

    // opening the directory
    if((directory = opendir(folderLoc)) == NULL) {
        write(2,"cannot open directory\n",19);
        return -1;
    }
    // read the directory
    if((entry = readdir(directory)) == NULL){
        write(2,"reading directory error\n",24);
        return -1;
    }

    do {
        if (entry->d_type == DT_DIR)
        {
			char pathLoc[1000];
			if(depth==0)
			{
				strcpy(studentName,entry->d_name);
				retVal=0;
			}
            int len = snprintf(pathLoc, sizeof(pathLoc)-1, "%s/%s", folderLoc, entry->d_name);
            pathLoc[len] = 0;
            /* Found a directory, but ignore . and .. */
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            	continue;
            /* Recurse at a new depth level */
            retVal+=lookForSourceFilesAndExecute(pathLoc, input,output,depth + 1,studentName);
        }
        else
        {
			char pathLoc[1000];
			int len = snprintf(pathLoc, sizeof(pathLoc)-1, "%s/%s", folderLoc, entry->d_name);
			pathLoc[len] = 0;
			/* check to see if we found the source file*/
			if( !strcmp( pathLoc+ strlen(pathLoc) - 2, ".c"))
			{
				executeSourcePart2(pathLoc,folderLoc,studentName,input,output,depth);
				retVal++;
			}
		}
		if(depth==0 && retVal==0)
		{
			printf("Student name = %s\n",studentName);
			printf("NO_C_FILE\n");
			flushResultToResultsFile(studentName,"NO_C_FILE",0);
		}
    } while (entry = readdir(directory));

    closedir(directory);
	return retVal;
}

void removeNewLine(char *str)
{
	while(str[strlen(str)-1]=='\r'|| str[strlen(str)-1]=='\n')
		str[strlen(str)-1]=0;
}

int main(int argc,char* argv[]){


	FILE* file1;
	char folderLocation[MAX_CHARS],inputFile[MAX_CHARS],outputFile[MAX_CHARS];
	char tempString[MAX_CHARS];
	int bytesRead;

	if(argc<2){
		write(2,"Missing config file as argument\n",32);
		exit(0);
	}

	file1 = fopen(argv[1],"r");
	if(file1 == NULL){
		write(2,"File Open Error\n",16);
		exit(0);
	}
	// read the first 3 lines of the file
	if(fgets(folderLocation,sizeof(folderLocation),file1) == NULL){
		write(2,"Error reading folder location\n",30);
		exit(0);
	}
	removeNewLine(folderLocation);
	if(fgets(inputFile,sizeof(inputFile),file1) == NULL){
		write(2,"Error reading input file\n",25);
		exit(0);
	}
	removeNewLine(inputFile);
	if(fgets(outputFile,sizeof(outputFile),file1) == NULL){
		write(2,"Error reading output file\n",25);
		exit(0);
	}
	removeNewLine(outputFile);

	//printf("Folder location = %s , Input File = %s, Output File = %s \n",folderLocation,inputFile,outputFile);

	FILE *file=fopen("results.csv","w");
	fclose(file);

	return lookForSourceFilesAndExecute(folderLocation,inputFile,outputFile,0,tempString);


}
