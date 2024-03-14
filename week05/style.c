#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

static struct node *listAppend(struct node *list, int data);
static void printList(struct node *node);
static void freeList(struct node *head);

int main() {
    struct node *head = NULL;
    head = listAppend(head, 1);
    head = listAppend(head, 2);
    head = listAppend(head, 3);
    head = listAppend(head, 4);
    printList(head);
    freeList(head);
    return 0;
}

// appends an item to the list
static struct node *listAppend(struct node *list, int data) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (list == NULL) {
        return newNode;
    }

    // go to the end of the list and append
    struct node *lastNode = list;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
    return list;
}

// prints every node in the list
static void printList(struct node *node) {
    while (node->next != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("%d\n", node->data);
}

// frees the given list
static void freeList(struct node *head) {
    if (head == NULL) {
        return;
    }

    struct node *temp = head;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
