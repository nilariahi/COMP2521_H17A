#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	Inputs: string s of length n
	Output: print "Yes" if s is a palindrome, else "No"
	palindrome: O(n)
		for i from 0 up to n / 2:
			if s[i] != s[n - i - 1]:
				print "No"
				return
		print "Yes"
*/

// accepts 1 command-line arg and checks if it's a palindrome
int main(int argc, char **argv) {
	if (argc != 2) {
		fprintf(stderr, "correct usage: %s <arg>\n", argv[0]);
		return 1;
	}

	char *s = argv[1];
	int n = strlen(s);

	for (int i = 0; i < n / 2; i++) {
		if (s[i] != s[n - i - 1]) {
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
}
