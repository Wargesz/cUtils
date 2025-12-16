#include "cutils.h"
#include <stdlib.h>

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

int endsWith(char *str, char *substr) {
    int length = charLength(str);
    int sublength = charLength(substr);
    if (sublength > length) {
        return 0;
    }
    str+=length-1;
    substr+=sublength-1;
    while (sublength != 0) {
        if (*str != *substr) {
            return 0;
        }
        sublength--;
    }
    return 1;
}

int startsWith(char *str, char *substr) {
    if (charLength(substr) > charLength(str)) {
        return 0;
    }
    while (*substr != '\0') {
        if (*str != *substr) {
            return 0;
        }
        str++;
        substr++;
    }
    return 1;
}

int equals(char *c1, char *c2) {
    if (charLength(c1) != charLength(c2)) {
        return 0;
    }
    while (*c1 != '\0') {
        if (*c1 != *c2) {
            return 0;
        }
        c1++;
        c2++;
    }
    return 1;
}

void setTo(char *target, char *c) {
    while (*c != '\0') {
        *target = *c;
        target++;
        c++;
    }
    *target = '\0';
}

int contains(char *target, char *sub) {
    int length = charLength(sub);
    while (charLength(target) >= length) {
        if (startsWith(target, sub)) {
            return 1;
        }
        target++;
    }
    return 0;
}

int strCount(char *target, char *sub) {
    int count = 0;
    int next = findChar(target, *sub);
    int length = charLength(target);
    target += next > 0 ? next : 1;
    length -= next > 0 ? next : 1;
    while (length >= 0 && contains(target, sub)) {
        target += next > 0 ? next : 1;
        length -= next > 0 ? next : 1;
        next = findChar(target, *sub);
        count++;
    }
    return count;
}

char *subStr(char *str, int begin, int end) {
    int strLength = charLength(str);
    if (end + 1 > strLength) {
        return NULL;
    }
    int substrLength = end-begin;
    char *sub = (char*) malloc(sizeof(char) * (strLength + 1));
    char *returnValue = sub;
    str += begin;
    while (substrLength != 0) {
        *sub = *str;
        sub++;
        str++;
        substrLength--;
    }
    *sub = '\0';
    return returnValue;
}

int findChar(char *str, char c) {
    int i = 0;
    while (*str != '\0') {
        if (*str == c) {
            return i;
        }
        i++;
        str++;
    }
    return -1;
}
