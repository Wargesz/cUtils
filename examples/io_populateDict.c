#include "../cutils.h"
#include <stdio.h>

int main() {
    StringBuilder *key = stringBuilderNew();
    StringBuilder *value = stringBuilderNew();
    Dict *d = newDict();
    FILE *f = fopen("config.txt", "r");
    while (!feof(f)) {
        readNext(f, key);
        readNext(f, value);
        addDict(d, key->content, value->content);
    }
    fclose(f);
    freeStringBuilder(key);
    freeStringBuilder(value);
    int i;
    for (i = 0; i < nodeLength(d->keys); i++) {
        char *c = nodeValueAt(d->keys, i);
        printf("%s: %s\n", c, dictValue(d, c));
    }
    freeDict(d);
    return 0;
}
