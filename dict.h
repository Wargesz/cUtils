#ifndef CUTILS_DICT
#define CUTILS_DICT
#include "list.h"

typedef struct Dict {
    Node *keys;
    Node *values;
} Dict;

Dict* newDict();
void addDict(Dict*, char *key, char *value);
void freeDict(Dict*);
char* dictValue(Dict*, char *key);
int hasKey(Dict*, char *key);

#endif
