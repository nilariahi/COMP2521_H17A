#include <stdio.h>
#include <stdlib.h>

// Representation 1
struct node {
    int value;
    struct node *next;
};

// helper functions to do tut demos with, don't worry about these
struct node *listInsert(struct node *list, int val);
void listPrint(struct node *list);

// returns the length of the list
int listLength(struct node *list) {
    int length = 0;
    for (struct node *curr = list; curr != NULL; curr = curr->next) {
        length++;
    }
    return length;
}

// returns the sum of all elements in the list
int sumList(struct node *list) {
    int sum = 0;
    for (struct node *curr = list; curr != NULL; curr = curr->next) {
        sum += curr->value;
    }
    return sum;
}

// deletes the first instance of the given value in the list
struct node *listDelete(struct node *list, int value) {
    // list is empty, nothing to delete
    if (list == NULL) return NULL;

    // the value we wanna delete is at the head
    else if (list->value == value) {
        struct node *newHead = list->next;
        free(list);
        return newHead;
    }

    // value isn't at the head, let's check the rest of the list
    struct node *prev = list;
    for (struct node *curr = list->next; curr != NULL; curr = curr->next) {
        // found it! let's delete it
        if (curr->value == value) {
            prev->next = curr->next;
            free(curr);
            return list;
        }
        prev = curr;
    }

    // checked the whole list and the value wasn't in it
    // so nothing changes
    return list;
}

// small driver to test that our functions are ok
int main(void) {
    struct node *list = NULL;
    for (int i = 0; i < 5; i++) {
        list = listInsert(list, i);
    }
    listPrint(list);
    printf("listLength(list) == %d\n", listLength(list));
    printf("listSum(list) == %d\n", sumList(list));

    list = listDelete(list, 2);
    printf("list after deleting 2: ");
    listPrint(list);

    list = listDelete(list, 42);
    printf("list after deleting 42: ");
    listPrint(list);

    list = listDelete(list, 0);
    printf("list after deleting 0: ");
    listPrint(list);

    list = listDelete(list, 4);
    printf("list after deleting 4: ");
    listPrint(list);
}

// inserts value at the tail of the list
struct node *listInsert(struct node *list, int val) {
    if (!list) {
        list = malloc(sizeof(*list));
        list->value = val;
        list->next = NULL;
    } else {
        list->next = listInsert(list->next, val);
    }
    return list;
}

// prints the list
void listPrint(struct node *list) {
    if (!list) {
        printf("NULL\n");
    } else {
        printf("%d -> ", list->value);
        listPrint(list->next);
    }
}
