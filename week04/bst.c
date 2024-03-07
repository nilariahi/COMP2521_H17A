// our tree rep for these questions
struct node {
    int value;
    struct node *left;
    struct node *right;
};

// Question 1
/*
For each of the sequences below

start from an initially empty binary search tree
show the tree resulting from inserting values in the order given
4 6 5 2 1 3 7
5 2 3 4 6 1 7
7 6 5 4 3 2 1
Assume new values are always inserted as new leaf nodes.
*/

// Question 2
/*
Consider the following tree and its values displayed in different output orderings:

            5
           / \
          /   \
         /     \
        3       8
       / \     / \
      1   4   7   9

In order:       1 3 4 5 7 8 9
Pre-order:      5 3 1 4 8 7 9
Post-order:     1 4 3 7 9 8 5
Level-order:    5 3 8 1 4 7 9

What kind of trees have the property that their in-order traversal is the same as their pre-order traversal?

Are there any kinds of trees for which all output orders will be the same?
*/

// Question 3: counts the number of odd values in a tree
int bstCountOdds(struct node *t) {
    // TODO
    return 42;
}

// Question 4: count number of internal nodes in a given tree
// An internal node is a node with at least one child node
int bstCountInternal(struct node *t) {
    // TODO
    return 42;
}

// returns the level of the node containing a given key if such a node exists,
// otherwise the function returns -1 (when a given key is not in the bst).
// The level of the root node is zero.
int bstNodeLevel(struct node *t, int key) {
    // TODO
    return 42;
}

// counts the number of values that are greater than a given value.
// This function should avoid visiting nodes that it doesn't have to visit.
int bstCountGreater(struct node *t, int val) {
    // TODO
    return 42;
}

// empty main to check compilation
int main(void) {}
