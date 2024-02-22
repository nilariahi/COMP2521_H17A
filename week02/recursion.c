#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
	int value;
	struct node *next;
};

// Q1 computes the length of the list
int listLength(struct node *l) {
	// base case
	if (!l) { // l == NULL
		return 0;
	}

	// recursive case
	return 1 + listLength(l->next);
}

// Q2 counts the number of odd numbers in the list
int listCountOdds(struct node *l) {
	if (!l) {
		return 0;
	}

	if (l->value % 2 == 1) { // odd
		return 1 + listCountOdds(l->next);
	} else { // even
		return listCountOdds(l->next);
	}
}

// Q3 checks whether the list is sorted in asc order
bool listIsSorted(struct node *l) {
	if (!l || !l->next) {
		return true;
	}

	if (l->value > l->next->value) {
		return false;
	}

	return listIsSorted(l->next);
}

// Q4 deletes the first instance of a value from the list
struct node *listDelete(struct node *l, int value) {
	// base case
	if (!l) {
		return NULL;
	}

	if (l->value == value) {
		struct node *rest = l->next;
		free(l);
		return rest;
	}

	l->next = listDelete(l->next, value);
	return l;
}

// Q5 how would the delete function from Q4 change
//		if we had the following linked list rep instead
struct list {
	struct node *head;
};

int listLength2(struct list *l) {
	return listLength(l->head);
}

// empty main to check compilation
int main(void) {}
