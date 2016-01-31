/*
 * Test38.cpp
 *
 *  Created on: Jan 30, 2016
 *      Author: chintan
 */

/*
 * find sum of longest increasing subsequence ?
Not the maximum sum,sum of longest subsequence.
Eg. 1, 8,2, 3
ans-> 6
 *
 */
#include <stddef.h>
#include <vector>
#include <iostream>

using namespace std;

typedef struct _SumData//Helper class that will store largest sum and its length
{
	int sum;
	int length;
}SumData;

class LisSumFinder{

public:
	static int findLisSum(std::vector<int> ipVec){
		std::vector<SumData> allSums;
		findLisAndSums(allSums,0,ipVec);
		SumData max=allSums[0];
		for(unsigned int i=0;i<allSums.size();i++)
		{
			max = allSums[i].length>=max.length?allSums[i]:max;
			//cout<<max.sum<<endl;
		}
		return max.sum;
	}

	static void findLisAndSums(std::vector<SumData> &allSums,unsigned int idx,std::vector<int> ipVec)
		{
			SumData curr;
			curr.length = 0;
			curr.sum = 0;
			if(idx==ipVec.size())
			{
				return;
			}
			if(idx==0)
			{

			}else
			{
				for(unsigned int i=0; i<idx;i++)
				{
					if(ipVec[i]<ipVec[idx])
					{
						curr = findLongestSum(curr,allSums[i]);
					}
				}
			}
			curr.length++;
			curr.sum+=ipVec[idx];
			allSums.push_back(curr);
			findLisAndSums(allSums,idx+1,ipVec);

			}

	static SumData findLongestSum(SumData x,SumData y)
	{
		if(x.length>y.length)
		{
			return x;
		}
		return y;
	}

};

int main(){

	std::vector<int>ipVec;
	ipVec.push_back(1);
	ipVec.push_back(8);
	ipVec.push_back(2);
	ipVec.push_back(3);

	std::cout<<LisSumFinder::findLisSum(ipVec)<<std::endl;
}
