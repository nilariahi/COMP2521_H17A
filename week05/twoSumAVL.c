// Using an AVL tree, design an algorithm to determine if an array contains
// two elements that sum to a given value.

// Write the algorithm in pseudocode.
// Analyse the time complexity of your algorithm.

// brute force solution from week 2
// O(n^2)
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
// O(n log n)
bool twoSum(int *arr, int size, int x) {
	AVL t = AVLNew();					// 1
	for (int i = 0; i < size; i++) {	// n
		int diff = x - arr[i];			// 1 * n
		if (AVLSearch(t, diff) == true) {	// (log n) * n
			return true;				// 1 * n
		}
		AVLInsert(t, arr[i]);			// (log n) * n
	}
	return false;						// 1
}
