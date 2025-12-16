#include "../cutils.h"
#include <stdio.h>

void readCompleteFile();
void readPerWhiteSpaceOrNewline();
void readPerLine();

void readCompleteFile() {
    FILE *f = fopen("config.txt", "r");
    StringBuilder *sb = stringBuilderNew();
    readAll(f, sb);
    printf("%s", sb->content);
    fclose(f);
    freeStringBuilder(sb);
}

void readPerWhiteSpaceOrNewline() {
    FILE *f = fopen("config.txt", "r");
    StringBuilder *sb = stringBuilderNew();
    while (!feof(f)) {
        readNext(f, sb);
        printf("%s\n", sb->content);
    }
    fclose(f);
    freeStringBuilder(sb);
}

void readPerLine() {
    FILE *f = fopen("config.txt", "r");
    StringBuilder *sb = stringBuilderNew();
    while (!feof(f)) {
        readLine(f, sb);
        printf("%s\n", sb->content);
    }
    fclose(f);
    freeStringBuilder(sb);
}

int main() {
    readCompleteFile();
    printf("-----------\n");
    readPerWhiteSpaceOrNewline();
    printf("-----------\n");
    readPerLine();
    return 0;
}
