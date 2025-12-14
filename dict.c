#include "cutils.h"
#include <stdio.h>
#include <stdlib.h>

Dict* newDict() {
    Dict *d = (Dict*) malloc(sizeof(Dict));
    d->keys = NULL;
    d->values = NULL;
    return d;
}

void addDict(Dict *d, char *key, char *value) {
    if (d->keys == NULL) {
        d->keys = newNode(key);
        d->values = newNode(value);
        return;
    }
    addNode(d->keys, key);
    addNode(d->values, value);
}

void freeDict(Dict *d) {
    freeNodes(d->keys);
    freeNodes(d->values);
    free(d);
}

char* dictValue(Dict *d, char* key) {
    Node *keys = d->keys;
    Node *values = d->values;
    while (keys != NULL && !equals(keys->value, key)) {
        keys = keys->next;
        values = values->next;
    }
    return values->value;
}

int hasKey(Dict *d, char* key) {
    Node *keys = d->keys;
    while (keys != NULL) {
        if (equals(keys->value, key)) {
            return 1;
        }
        keys = keys->next;
    }
    return 0;
}
