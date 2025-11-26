#include <stdio.h>
#include <stdlib.h>
#include "strings.h"

const char *alphabet = ".-_0123456789aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";

int compareChars(char *a, char* b) {
    char *aStart = a;
    char *bStart = b;
    while (*a == *b) {
        if ( *a == '\0' || *b == '\0') {
            return charLength(bStart) - charLength(aStart);
        }
        a++;
        b++;
    }
    return posInAlphabet(*a) - posInAlphabet(*b);
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
    if (l == NULL) {
        return NULL;
    }
    char* begin = l;
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

int posInAlphabet(char c) {
    int i = 0;
    while (c != alphabet[i]) {
        i++;
        if (alphabet[i] == '\0') {
            return 100;
        }
    }
    return i;
}
