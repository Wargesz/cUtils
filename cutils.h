#ifndef CUTILS
#define CUTILS

#include <stdio.h> /* for io  */

/* STRINGS */

int compareChars(char*, char*);
int charLength(char*);
char* toLower(char *);
int isLetter(char);
int posInAlphabet(char);
void addToCharArray(char[], char*);
int endsWith(char *str, char *substr);
int equals(char*, char*);
void setTo(char *target, char *str);

/* LIST */

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

/* STRINGBUILDER */

#define STRINGBUILDER_SIZE 64

typedef struct StringBuilder {
    int length;
    int head;
    char *content;
} StringBuilder;

StringBuilder* stringBuilderNew();
void stringBuilderAppend(StringBuilder*, char*);
void freeStringBuilder(StringBuilder*);
int stringBuilderSpace(StringBuilder*);

/* DICTIONARY */

typedef struct Dict {
    Node *keys;
    Node *values;
} Dict;

Dict* newDict();
void addDict(Dict*, char *key, char *value);
void freeDict(Dict*);
char* dictValue(Dict*, char *key);
int hasKey(Dict*, char *key);

/* IO */

void readNext(FILE*, StringBuilder*);
void readAll(FILE*, StringBuilder*);
void readLine(FILE*, StringBuilder*);

#endif
