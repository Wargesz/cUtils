#ifndef CUTILS_LIST
#define CUTILS_LIST

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
void floatNode(Node*, int);
#endif
