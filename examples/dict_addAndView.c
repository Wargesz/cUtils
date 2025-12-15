#include "../cutils.h"
#include <stdio.h>

int main() {
    Dict *d = newDict();
    addDict(d, "one", "first value");
    addDict(d, "two", "second value");
    addDict(d, "three", "third value");
    addDict(d, "four", "fourth value");
    printf("%s\n", dictValue(d, "two"));
    printf("%s\n", dictValue(d, "four"));
    freeDict(d);
    return 0;
}
