#include <stdio.h>
#include <stdbool.h>

/*
	Inputs: array A of size n, integer sum
	Outputs: true if 2 distinct values in A add up to sum
		else false

	twoSum: O(n^2)
		for i from 0 to n - 1:
			for j from i + 1 to n - 1:
				if A[i] + A[j] == sum:
					return true
		return false
*/

// returns true if 2 distinct elements in arr add up to x
//		false otherwise
bool twoSum(int *arr, int size, int x) {
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (arr[i] + arr[j] == x) {
				return true;
			}
		}
	}
	return false;
}

// empty main to check compilation
int main(void) {}
