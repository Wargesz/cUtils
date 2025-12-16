#include "cutils.h"
#include <stdio.h>

void readNext(FILE *f, StringBuilder *sb) {
    sb->head = 0;
    char ch;
    while ((ch = fgetc(f)) != EOF) {
        if (ch == ' ' || ch == '\n') {
            return;
        }
        stringBuilderAppend(sb, &ch);
    }
}

void readAll(FILE *f, StringBuilder *sb) {
    char ch;
    while ((ch = fgetc(f)) != EOF) {
        stringBuilderAppend(sb, &ch);
    }
}

void readLine(FILE *f, StringBuilder *sb) {
    sb->head = 0;
    char ch;
    while ((ch = fgetc(f)) != EOF) {
        if (ch == '\n') {
            return;
        }
        stringBuilderAppend(sb, &ch);
    }
}
