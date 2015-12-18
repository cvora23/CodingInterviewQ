#include<iostream>
#include<string.h>
#include<stdio.h>
#include<limits.h>
#include <algorithm>

using namespace std;

#define NO_OF_CHARS 256


bool wordplay(char *letters, char *word)
{
     int array1[256] = {0};
     int array2[256] = {0};
     for(unsigned int i=0;i<strlen(letters);i++)
     array1[letters[i]]++;
     for(unsigned int i=0;i<strlen(word);i++)
     array2[word[i]]++;
     for(int i=0;i<256;i++)
     {
    	 array2[i]-=array1[i];
     }
     for(int i=0;i<256;i++)
     {
             if(array2[i]>0)
             return 0;
     }
     return 1;
}


bool CheckAnagram(char *str1, char *str2)
{
	 int temp = 0;
     int array[256] = {0};
     for(unsigned int i=0;i<strlen(str1);i++)
     array[str1[i]]++;
     for(unsigned int i=0;i<strlen(str2);i++)
     array[str2[i]]--;
     for(int i=0;i<256;i++)
     {
             if(array[i]!=0)
             return 0;
     }
     return 1;
}

// \TODO: Wrong method
bool CheckAnagram1(char *str1,char *str2)
{
     int sum = 0;
     while(*str1!='\0')
     sum^=*str1++;
     cout<<sum<<endl;
     while(*str2!='\0')
     sum^=*str2++;
     cout<<sum<<endl;
     //cout<<sum<<endl;
     return sum;
}

bool CheckAnagram2(char* str1,char* str2)
{    // Create two count arrays and initialize all values as 0
    int count[NO_OF_CHARS] = {0};
    int i;

    // For each character in input strings, increment count in
    // the corresponding count array
    for (i = 0; str1[i] && str2[i];  i++)
    {
        count[str1[i]]++;
        count[str2[i]]--;
    }

    // If both strings are of different length. Removing this condition
    // will make the program fail for strings like "aaca" and "aca"
    if (str1[i] || str2[i])
      return false;

    // See if there is any non-zero value in count array
    for (i = 0; i < NO_OF_CHARS; i++)
        if (count[i])
            return false;
     return true;


}

bool isAnagramSol1(string s1,string s2){
	if(s1.length() != s2.length()){
		return false;
	}
	std::sort(s1.begin(),s1.end());
	std::sort(s2.begin(),s2.end());

	return s1 == s2;
}

bool isAnagramSol2(string s1,string s2){
	if(s1.length() != s2.length()){
		return false;
	}
	int *letters = new int[256];
	for(unsigned int i=0;i<s1.length();i++){
		letters[s1.at(i)]++;
	}
	for(unsigned int i=0;i<s2.length();i++){
		if(--letters[s2.at(i)]){
			return false;
		}
	}
	return true;
}


int main()
{
    char *str1 = new char[100];
    cout<<"Enter the first String"<<endl;
    gets(str1);
    char *str2 = new char[100];
    cout<<"Enter the second String"<<endl;
    gets(str2);
    
    int i = CheckAnagram(str1,str2);
    if(i==1)
    cout<<"The given two strings are Anagrams "<<endl;
    else
    cout<<"The given two strings are not Anagrams"<<endl;

    int j;
     j = CheckAnagram2(str1,str2);
    if(j==0)
    cout<<"The given two strings are not Anagrams "<<endl;
    else
    cout<<"The given two strings are Anagrams"<<endl;


    return 0;
} 
