#ifndef CUTILS_STRINGBUILDER
#define CUTILS_STRINGBUILDER
#define SIZE 64

typedef struct StringBuilder {
    int length;
    int head;
    char *content;
} StringBuilder;

StringBuilder stringBuilderNew();
void stringBuilderAppend(StringBuilder *sb, char *content);

#endif
