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
                4
               / \
              /   \
             2     6
            / \   / \
           1   3 5   7

5 2 3 4 6 1 7
                5
               / \
              2   6
             / \   \
            1   3   7
                 \
                  4
7 6 5 4 3 2 1
                7
               /
              6
             /
            5
           /
          4
         /
        3
       /
      2
     /
    1

Assume new values are always inserted as new leaf nodes.
*/

// Question 2
/*
Consider the following tree and its values 
displayed in different output orderings:

            5    val == 2
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

What kind of trees have the property that 
their in-order traversal is the same as their 
pre-order traversal? -- right deep (degenerate) tree

Are there any kinds of trees for which all 
output orders will be the same? empty tree or just one node
*/

// Question 3: counts the number of odd values in a tree
int bstCountOdds(struct node *t) {
    if (!t) return 0;

    if (t->value % 2 == 0) { // even
        return bstCountOdds(t->left) + bstCountOdds(t->right);
    } else { // odd
        return 1 + bstCountOdds(t->left) + bstCountOdds(t->right);
    }
}

// Question 4: count number of internal nodes in a given tree
// An internal node is a node with at least one child node
int bstCountInternal(struct node *t) {
    if (!t) return 0;
    if (!t->left && !t->right) return 0; 

    return 1 + bstCountInternal(t->left) + bstCountInternal(t->right);
}

// returns the level of the node containing a 
// given key if such a node exists,
// otherwise the function returns -1 
// (when a given key is not in the bst).
// The level of the root node is zero.
int bstNodeLevel(struct node *t, int key) {
    if (!t) return -1;
    if (t->value == key) return 0;

    if (t->value > key) {
        // just recurse left
        int leftLevel = bstNodeLevel(t->left, key);
        if (leftLevel == -1) return -1;
        return leftLevel + 1;
    } else { // t->value < key
        // just recurse right
        int rightLevel = bstNodeLevel(t->right, key);
        if (rightLevel == -1) return -1;
        return rightLevel + 1;
    }
}

// counts the number of values that are greater 
// than a given value.
// This function should avoid visiting nodes 
// that it doesn't have to visit.
int bstCountGreater(struct node *t, int val) {
    if (!t) return 0;

    if (t->value <= val) {
        return bstCountGreater(t->right, val);
    } else { // t->value > val
        return 1 + bstCountGreater(t->right, val) +
                    bstCountGreater(t->left, val);
    }
}

// empty main to check compilation
int main(void) {}
