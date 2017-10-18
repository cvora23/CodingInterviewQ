/*
 * FlipBitToWin.cpp
 *
 *  Created on: Sep 9, 2017
 *      Author: chivora
 */
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

/*
 * Flip Bit to Win: You have an integer and you can flip exactly one bit from a 13 to a 1.
 * Write code to find the length of the longest sequence of ls you could create.
 * EXAMPLE
 * Input: 1775 ( or : 11011101111)
 * Output: 8
 * Hints: #159, #226, #314, #352
 */

/*
 * Solution 1
 */

/*
 * Given lengths of alternating sequences of 0s and 1s, find the longest one we can build
 */
int findLongestSequence(vector<int> seq){

	int maxSeq = 1;
	for(int i=0;i<seq.size();i+=2){

		int zeroSeq = seq[i];
		int onesSeqRight = ((i-1) >= 0) ? seq[i-1] : 0;
		int onesSeqLeft = ((i+1) < seq.size()) ? seq[i+1] : 0;

		int thisSeq = 0;

		if(zeroSeq == 1){
			thisSeq = onesSeqLeft + 1 + onesSeqRight;
		}else if(zeroSeq > 1){
			thisSeq = 1 + max(onesSeqLeft,onesSeqRight);
		}else if(zeroSeq == 0){
			thisSeq = max(onesSeqLeft,onesSeqRight);
		}
		maxSeq = max(thisSeq,maxSeq);
	}

	return maxSeq;
}

/*
 * Return list of sizes of sequences. The sequence starts off with the number of 0s (which might be 0) and then alternates
 * with counts of each value.
 */
vector<int> getAlternatingSequences(int n){

	vector<int>sequences;

	int searchingFor = 0;
	int counter = 0;

	for(int i=0;i<sizeof(int)*8;i++){

		if((n & 1) != searchingFor){
			sequences.push_back(counter);
			searchingFor = n & 1; // Flip 1 to 0 or 0 to 1
			counter = 0;
		}
		counter++;
		n >>= 1;
	}
	sequences.push_back(counter);

	return sequences;
}


int longestSequence(int n){
	if(n == 1){
		return sizeof(int) * 8;
	}
	vector<int>sequences = getAlternatingSequences(n);
	return findLongestSequence(sequences);
}


/*
 * Solution 2
 */

/*
 * Optimal Algorithm
 * To reduce the space usage, note that we don't need to hang on to the length of each sequence the entire time.
 * We only need it long enough to compare each 1s sequence to the immediately preceding 1ssequence.
 * Therefore, we can just walk through the integer doing this, tracking the current 1s sequence length
 * and the previous 1s sequence length. When we see a zero, update previousLength:
 * • If the next bit is a 1,previousLength should be set to currentLength.
 * • If the next bit is a 0,then we can't merge these sequences together.So,set previousLength to 0.
 */
int longestSequence2(int n){


	/*
	 * If all 1s, this is already the longest sequence.
	 */

	if(~n == 0){
		return sizeof(int) * 8;
	}

	int currentLen = 0;
	int prevLen = 0;
	int maxLen = 1; // We can always have a sequence of at least one 1

	while(n != 0){
		/*
		 * if current bit is 1
		 */
		if((n & 1) == 1){
			currentLen++;
			cout<<"current bit is 1"<<endl;
			cout<< "current len = "<<currentLen<<endl;
		}
		/*
		 * else if current bit is 0
		 */
		else if((n & 1) == 0){

			/*
			 * Update to 0 (if next bit is 0)  or currentLength (if next bit is 1)
			 */
			prevLen = (n & 2) == 0 ? 0 : currentLen;
			currentLen = 0;
			cout<<"current bit is 0"<<endl;
			cout<< "previous len = "<<prevLen<<endl;
			cout<< "current len = "<<currentLen<<endl;
		}

		maxLen = max(prevLen + currentLen + 1,maxLen);

		n >>= 1;

	}

	return maxLen;



}

int main(){
	//cout<<longestSequence(1775)<<endl;
	cout<<longestSequence2(1775)<<endl;

	return 0;

}




