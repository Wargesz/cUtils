#include "../cutils.h"
#include <dirent.h>
#include <stdio.h>

int main(void) {
    DIR *d = opendir("..");
    if (d == NULL) {
        printf("failed to open dir");
        return 1;
    }
    struct dirent *di = readdir(d);
    if (di == NULL) {
        printf("failed to read dir");
        return 1;
    }
    StringBuilder *sb = stringBuilderNew();
    while (di != NULL) {
        stringBuilderAppend(sb, di->d_name);
        stringBuilderAppend(sb, "\n");
        di = readdir(d);
    }
    closedir(d);
    printf("%s", sb->content);
    freeStringBuilder(sb);
    return 0;
}
