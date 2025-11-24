#include <stdio.h>
#include "../list.c"
#include <dirent.h>

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
    Node *n = newNode(di->d_name);
    di = readdir(d);
    while (di != NULL) {
        addNode(n, di->d_name);
        di = readdir(d);
    }
    closedir(d);
    int i;
    for (i = 0; i < nodeLength(n); i++) {
        printf("Node %d. %s\n", i + 1, nodeValueAt(n, i));
    }
    printf("%d nodes\n", nodeLength(n));
    freeNodes(n);
    return 0;
}
