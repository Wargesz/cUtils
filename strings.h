#ifndef CUTILS_STRINGS
#define CUTILS_STRINGS

int compareChars(char*, char*);
int charLength(char*);
char* toLower(char *);
int isLetter(char);
int posInAlphabet(char);
void addToCharArray(char[], char*);
int endsWith(char *str, char *substr);
int equals(char*, char*);
void setTo(char *target, char *str);

#endif
