#include "cutils.h"
#include <stdio.h>
#include <stdlib.h>

StringBuilder* stringBuilderNew() {
    StringBuilder* sb = (StringBuilder*) malloc(sizeof(StringBuilder));
    sb->length = STRINGBUILDER_SIZE;
    sb->head = 0;
    sb->content = (char*) malloc(sizeof(char) * sb->length);
    return sb;
}

void stringBuilderAppend(StringBuilder *sb, char *content) {
    int length = charLength(content);
    char *s = sb->content;
    int freeSpace = stringBuilderSpace(sb);
    s += sb->head;
    if (freeSpace >= length) {
        sb->head += length;
        while (*content != '\0') {
            *s = *content;
            s++;
            content++;
        }
        *s = '\0';
        return;
    }
    length++;
    int sections = length/STRINGBUILDER_SIZE;
    if (length%STRINGBUILDER_SIZE) {
        sections++;
    }
    sb->length += sections * STRINGBUILDER_SIZE;
    sb->content = realloc(sb->content, sizeof(char) * sb->length);
    s = sb->content + sb->head;
    while (*content != '\0') {
        *s = *content;
        s++;
        content++;
    }
    *s = '\0';
    sb->head += length - 1;
}

void freeStringBuilder(StringBuilder *sb) {
    free(sb->content);
    free(sb);
}

int stringBuilderSpace(StringBuilder *sb) {
    return  sb->length - sb->head - 1;
}
