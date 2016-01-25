/*
 * Test16.cpp
 *
 *  Created on: Jan 21, 2016
 *      Author: chintan
 */

#include <vector>
#include <iostream>

using namespace std;

typedef long long INT64;

vector<INT64> sums;

void preCalcSum(vector<int>& arr) {
    int i;

    if (arr.size() == 0) return;
    sums.clear();
    sums.assign(arr.size() + 1, 0);
    for (i = 0; i < arr.size(); i++) {
        sums[i + 1] = sums[i] + arr[i];
    }
}

int subSum(vector<int>& arr, int x1, int x2) {
    if (x1 > x2 || x1 < 0 || x2 >= arr.size()) return 0;
    return sums[x2 + 1] - sums[x1];
}

int main() {
	int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<int> arr(data, data + 10);

	preCalcSum(arr);
	cout << subSum(arr, 0, 9) << "\n"; // 55
	cout << subSum(arr, 0, 0) << "\n"; // 1
	cout << subSum(arr, 9, 9) << "\n"; // 10
	cout << subSum(arr, 2, 7) << "\n"; // 33
	cout << subSum(arr, -1, 9) << "\n"; // 0
	cout << subSum(arr, 0, 10) << "\n"; // 0
	cout << subSum(arr, 9, 0) << "\n"; // 0

    return 0;
}


