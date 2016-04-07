#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int checkFile(FILE *f){
	if(f==NULL){
        return 0;
	}
	return 1;
}

int exactlySameFiles(FILE* file1,FILE* file2){

	int retVal = 1;
	char letter1,letter2;

	// Check if files are exactly same
	letter1 = getc(file1);
	letter2 = getc(file2);

	while((letter1 != EOF) && (letter2!= EOF) && (letter1==letter2)){
		letter1 = getc(file1);
		letter2 = getc(file2);
	}

	if(letter1 == letter2){
		retVal = 2;
	}
	return retVal;
}

int similarFiles(FILE* file1,FILE* file2){

	int retVal = 3;
	char letter1,letter2;

	while(1){

		letter1 = getc(file1);
		letter2 = getc(file2);
		// skip not so important characters for file1 if any
		while((letter1 == '\n') ||
				(letter1 == '\r') ||
				(letter1 == ' ') ||
				(letter1 == '\t'))
		{
			letter1 = getc(file1);
		}

		// skip not so important character for file2 if any
		while((letter2 == '\n') ||
				(letter2 == '\r') ||
				(letter2 == ' ') ||
				(letter2 == '\t'))
		{
			letter2 = getc(file2);
		}

		// files reached till end and everything was simuilar
		if(letter1 == EOF && letter2 == EOF){
			//printf("Files similar\n");
			break;
		}
		else if(letter1 == EOF || letter2 == EOF){
			retVal = 1;
			break;
		}
		// else check next characters in both file
		else if((letter1 == letter2) || (tolower(letter1) == tolower(letter2))){
			// everything is good. keep going
		}else{
			retVal = 1;
			break;
		}
	}

	return retVal;
}

int main(int argc,char **argv){

	int retVal = 1;
	FILE *file1,*file2;

	file1 = fopen(argv[1],"r");
	file2 = fopen(argv[2],"r");

	if(file1 == NULL || file2 == NULL){
        write(2, "Input Args Error\n", 17);
		exit(0);
	}

	// check if files are exactly same
	retVal = exactlySameFiles(file1,file2);
	if(retVal == 2){
		return retVal;
	}

	rewind(file1);
	rewind(file2);

	// else check if files are similar - ignore capital\small letters, spaces, and enters
	retVal = similarFiles(file1,file2);

	return retVal;

}
