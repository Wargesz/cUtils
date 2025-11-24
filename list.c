#include <stdio.h>
#include <stdlib.h>
#include "strings.c"

#define LENGTH 256

typedef struct Node {
    char value[LENGTH];
    struct Node *next;
} Node;

Node* newNode(char*);
void addNode(Node*, char*);
void freeNodes(Node*);
Node* nodeAt(Node*, int);
char* nodeValueAt(Node*, int);
int nodeLength(Node*);
void sortNodes(Node*);
void swapValues(Node*, Node*);

Node* newNode(char *content) {
    Node *node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        return NULL;
    }
    int i = 0;
    while (*content != '\0') {
        node->value[i] = *content;
        content++;
        i++;
    }
    while (i < LENGTH-1)  {
        node->value[i] = '\0';
        i++;
    }
    node->next = NULL;
    return node;
}

void addNode(Node *node, char *content) {
    Node *before = node;
    while (before->next != NULL) {
        before = before->next;
    }
    Node *new = newNode(content);
    if (new == NULL) {
        return;
    }
    before->next = new;
}

void freeNodes(Node *node) {
    if (node == NULL) {
        return;
    }
    Node *head = node->next;
    Node *tmp;
    node->next = NULL;
    while (head != NULL) {
        tmp = head->next;
        free(head);
        head = tmp;
    }
    free(node);
    node = NULL;
}

Node* nodeAt(Node *node, int index) {
    Node *target = node;
    int i = 0;
    while (i < index) {
        if (target == NULL) {
            return NULL;
        }
        target = target->next;
        i++;
    }
    return target;
}

char* nodeValueAt(Node *node, int index) {
    return nodeAt(node, index)->value;
}

int nodeLength(Node *node) {
    if (node == NULL) {
        return 0;
    }
    int i = 0;
    while (node != NULL) {
        node = node->next;
        i++;
    }
    return i;
}

void sortNodes(Node *n) {
    int i, o;
    int swapped;
    for (i = 0; i < nodeLength(n) - 1 ; i++) {
        swapped = 0;
        for (o = 0; o < nodeLength(n) - (i + 1); o++) {
            if (compareChars(
                        nodeValueAt(n, o),
                        nodeValueAt(n, o + 1)
                        ) > 0) {
                swapValues(nodeAt(n, o), nodeAt(n, o + 1));
                swapped = 1;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

void swapValues(Node *n1, Node *n2) {
    char value[LENGTH];
    int i;
    for (i = 0; i < LENGTH; i++) {
        value[i] = n1->value[i];
    }
    for (i = 0; i < LENGTH; i++) {
        n1->value[i] = n2->value[i];
    }
    for (i = 0; i < LENGTH; i++) {
        n2->value[i] = value[i];
    }
}
