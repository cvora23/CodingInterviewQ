/*
 * MaxSubarraySharesDAndQAlgo.cpp
 *
 *  Created on: Nov 11, 2014
 *      Author: cvora
 */

#include <stdint.h>
#include <stddef.h>
#include <limits.h>
#include <iostream>

#include "require.h"

using namespace std;


/*-----------------------------max profit share problem-------------*/

struct res{
	int i;
	int j;
	int sum;
};


// A utility funtion to find maximum of two integers
struct res max(struct res a, struct res b) { return (a.sum > b.sum)? a : b; }

// A utility funtion to find maximum of three integers
struct res max(struct res a, struct res b, struct res c) { return max(max(a, b), c); }

struct res max_cross_sub(int arr[],int low,int mid,int high){

	struct res crossRes;
	crossRes.i = -1;
	crossRes.j = -1;
	crossRes.sum = 0;

	// Include elements on left of mid
	int sum = 0;
	int left_sum = INT_MIN;
    for (int i = mid; i >= low; i--)
    {
        sum = sum + arr[i];
        if (sum > left_sum){
          left_sum = sum;
          crossRes.i = i;
          crossRes.sum += arr[i];
        }
    }

    // Include elements on right of mid
    sum = 0;
    int right_sum = INT_MIN;
    for (int j = mid+1; j <= high; j++)
    {
        sum = sum + arr[j];
        if (sum > right_sum){
        	right_sum = sum;
            crossRes.j = j;
            crossRes.sum += arr[j];
        }
    }

    // Return sum of elements on left and right of mid
	return crossRes;
}

struct res max_sub(int a[],int low,int high){

	struct res leftRes,rightRes,crossRes;
	int mid;

	if(low == high){

		leftRes.i = low;
		leftRes.j = high;
		leftRes.sum = a[low];
		return leftRes;

	}else{

		mid = (low+high)/2;

		leftRes =  max_sub(a,low,mid);
		rightRes = max_sub(a,mid+1,high);
		crossRes = max_cross_sub(a,low,mid,high);

		return max(leftRes,rightRes,crossRes);

	}
}

void share(int a[],int low,int high){

	int aux[high-1],i;

	for(i=0;i<high-1;i++)
		aux[i]=a[i+1]-a[i];

	printArray(aux,high-1);

	if(low == high){
		return;
	}


	struct res result = max_sub(aux,low,high-2);
	cout<<"Maximum profit is buying on day "<<result.i <<" and selling on day "<<result.j+1<<
			" with maximum profit of "<<result.sum<<endl;
}

int  main(){

	int a[10]={30,12,15,5,40,30,60,130,2,110 };
	share(a,0,sizeof(a)/sizeof(a[0]));
	int a2[] = {30, 12, 15, 10, 40, 30, 60, 100};
	share(a2,0,sizeof(a2)/sizeof(a2[0]));
	int a3[] = {100, 180, 260, 310};
	share(a3,0,sizeof(a3)/sizeof(a3[0]));
}



