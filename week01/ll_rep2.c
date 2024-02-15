#include <stdio.h>
#include <stdlib.h>

// Representation 2
struct node {
    int value;
    struct node *next;
};

struct list {
    struct node *head;
};

// helper functions to do tut demos with, don't worry about these
void listInsert(struct list *list, int val);
void listPrint(struct list *list);

// returns the length of the list
int listLength(struct list *list) {
    int length = 0;
    for (struct node *curr = list->head; curr != NULL; curr = curr->next) {
        length++;
    }
    return length;
}

// returns the sum of all elements in the list
int sumList(struct list *list) {
    int sum = 0;
    for (struct node *curr = list->head; curr != NULL; curr = curr->next) {
        sum += curr->value;
    }
    return sum;
}

// deletes the first instance of the given value in the list
void listDelete(struct list *list, int value) {
    // list is empty, nothing to delete
    if (list->head == NULL) return;

    // the value we wanna delete is at the head
    else if (list->head->value == value) {
        struct node *newHead = list->head->next;
        free(list->head);
        list->head = newHead;
        return;
    }

    // value isn't at the head, let's check the rest of the list
    struct node *prev = list->head;
    for (struct node *curr = list->head->next; curr != NULL; curr = curr->next) {
        // found it! let's delete it
        if (curr->value == value) {
            prev->next = curr->next;
            free(curr);
            return;
        }
        prev = curr;
    }

    // checked the whole list and the value wasn't in it
    // so nothing changes
}

// small driver to test that our functions are ok
int main(void) {
    struct list *list = malloc(sizeof(struct list));
    list->head = NULL;
    for (int i = 0; i < 5; i++) {
        listInsert(list, i);
    }

    listPrint(list);
    printf("listLength(list) == %d\n", listLength(list));
    printf("listSum(list) == %d\n", sumList(list));
    
    listDelete(list, 2);
    printf("list after deleting 2: ");
    listPrint(list);
    
    listDelete(list, 42);
    printf("list after deleting 42: ");
    listPrint(list);

    listDelete(list, 0);
    printf("list after deleting 0: ");
    listPrint(list);
    
    listDelete(list, 4);
    printf("list after deleting 4: ");
    listPrint(list);
}

struct node *doListInsert(struct node *node, int val) {
    if (!node) {
        node = malloc(sizeof(struct node));
        node->value = val;
        node->next = NULL;
    } else {
        node->next = doListInsert(node->next, val);
    }
    return node;
}

// inserts value at the tail of the list
void listInsert(struct list *list, int val) {
    list->head = doListInsert(list->head, val);
}

void doListPrint(struct node *node) {
    if (!node) {
        printf("NULL\n");
    } else {
        printf("%d -> ", node->value);
        doListPrint(node->next);
    }
}

// prints the list
void listPrint(struct list *list) {
    doListPrint(list->head);
}
