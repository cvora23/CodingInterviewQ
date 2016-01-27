/*
 * Test33.cpp
 *
 *  Created on: Jan 26, 2016
 *      Author: chintan
 */

/*
 * A string contains a-z, A-Z and spaces. Sort the string so that all
 * lower cases are at the beginning, spaces in the middle and upper cases at the end.
 * Original order among lower and upper cases needs to remain the same.
 * For example: a cBd LkmY becomes ackm BLY. Is there a way in O(n) without extra space?
 *
 * Its a variation of Dutch National Flag problem but with 3 way partitioning.
 * O(n) time complexity and not extrat space.
 * lower letter are first partition , space second and upper case third partition
 *
 */

// https://www.youtube.com/watch?v=CNVN76UWpBo

#include <iostream>
#include "require.h"

using namespace std;

/* UTILITY FUNCTIONS */
void swap(char *a, char *b)
{
	char temp = *a;
    *a = *b;
    *b = temp;
}

int charType(char c){
	int ret = 0;
	if(c == ' '){
		ret = 1;
	}else if(islower(c)){
		ret = 0;
	}else if(isupper(c)){
		ret = 2;
	}
	return ret;
}

// Sort the input array, the array is assumed to
// have values in {0, 1, 2}
void sort012(char a[], int arr_size)
{
    int lo = 0;
    int hi = arr_size - 1;
    int mid = 0;
    int ret = -1;
    while (mid <= hi)
    {
    	ret = charType(a[mid]);
        switch (ret)
        {
        case 0: // lower case
            swap(&a[lo++], &a[mid++]);
            break;
        case 1: // space
            mid++;
            break;
        case 2: // upper case
            swap(&a[mid], &a[hi--]);
            break;
        }
    }
}

/* driver program to test */
int main()
{
    char arr[] = {'a',' ','c', 'B','d',' ','L','k','m','Y'};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, arr_size);

    sort012(arr, arr_size);

    cout<<"array after segregation "<<endl;
    printArray(arr, arr_size);

    getchar();
    return 0;
}
