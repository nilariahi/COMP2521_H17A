// Using an AVL tree, design an algorithm to determine if an array contains
// two elements that sum to a given value.

// Write the algorithm in pseudocode.
// Analyse the time complexity of your algorithm.

// brute force solution from week 2
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

// improved AVL tree solution
bool twoSum(int *arr, int size, int x) {
	// TODO
	return false;
}
