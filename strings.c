#include <stdio.h>
#include <stdlib.h>

int compareChars(char*, char*);
int charLength(char*);
char* toLower(char *);
int isLetter(char);

int compareChars(char *first, char* second) {
    char *aBegin = toLower(first);
    char *bBegin = toLower(second);
    char *a = aBegin;
    char *b = bBegin;
    int result = 0;
    while (*a == *b) {
        if (*a == '\0' && *b == '\0') {
            free(aBegin);
            free(bBegin);
            return 0;
        }
        if (*a == '\0' && *b != '\0') {
            free(aBegin);
            free(bBegin);
            return 1;
        }
        if (*a != '\0' && *b == '\0') {
            free(aBegin);
            free(bBegin);
            return -1;
        }
        a++;
        b++;
    }
    if (isLetter(*a) && isLetter(*b)) {
        if (*a < *b) {
            result = 1;
        }
        if (*a > *b) {
            result = -1;
        }
    }
    if (isLetter(*a) && !isLetter(*b)) {
        result = -1;
    }
    if (!isLetter(*a) && isLetter(*b)) {
        result = 1;
    }
    free(aBegin);
    free(bBegin);
    return result;
}

int charLength(char *c) {
    int i = 0;
    while (*c != '\0') {
        i++;
        c++;
    }
    return i;
}

char* toLower(char *c) {
    char* l = (char*)malloc(sizeof(char)*charLength(c) + 1);
    char* begin = l;
    if (l == NULL) {
        return NULL;
    }
    while (*c != '\0') {
        /* is capital letter */
        if (*c < 91 && *c > 64) {
            *l = *c+32;
        } else {
            *l = *c;
        }
        c++;
        l++;
    }
    *l = '\0';
    return begin;
}

int isLetter(char c) {
    return c > 96 && c < 123;
}
