#include <stdio.h>
#include <stdlib.h>

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
