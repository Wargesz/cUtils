#include <dirent.h>
#include <stdio.h>
#include "../stringBuilder.c"

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
    StringBuilder sb = sbNew();
    while (di != NULL) {
        sbAppend(&sb, di->d_name);
        sbAppend(&sb, "\n");
        di = readdir(d);
    }
    closedir(d);
    printf("%s", sb.content);
    sbFree(&sb);
    return 0;
}
