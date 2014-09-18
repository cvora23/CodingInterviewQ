/*
 * BinaryRepresentationOfNumber.cpp
 *
 *  Created on: Aug 27, 2013
 *      Author: cvora
 */
#include<iostream>
#include<string.h>
#include<math.h>
#include<stdio.h>
using namespace std;




void binaryRep1(unsigned n)
{
    unsigned i;
    for (i = 1 << 31; i > 0; i = i / 2)
        (n & i)? printf("1"): printf("0");
}

// Recursive solution
void binaryRep2(unsigned n)
{
    /* step 1 */
    if (n > 1)
    	binaryRep2(n/2);

    /* step 2 */
    printf("%d", n % 2);
}

void binaryRep3(int a)
{
     int rem;
     int i=1;
     while(a>pow(2,i))
     {
                 i++;
     }
    // i--;
   //  cout<<i<<endl;
     int *arr = new int[i];
     cout<<"Binary representation of "<<a<<" is : ";
     int j=0;
     while(a!=1)
     {
      rem = a%2;
      a=a/2;
      arr[j] = rem;
      j++;
     }
     if(a==1)
     {
             rem=1;
             arr[j] = rem;
     }

     for(int i=j;i>=0;i--)
     {
     cout<<arr[i];
     }
     delete arr;
     cout<<endl;
}


int main(void)
{
	binaryRep1(7);
	cout<<endl;
	binaryRep2(7);
	cout<<endl;
	binaryRep3(7);
	cout<<endl;

    printf("\n");
	binaryRep1(4);
	cout<<endl;
	binaryRep2(4);
	cout<<endl;
	binaryRep3(4);
}
