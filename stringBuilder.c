#ifndef malloc
    #include <stdlib.h>
#endif
#define sbAppend stringBuilderAppend
#define sbNew stringBuilderNew
#define sbFree stringBuilderFree

const int SIZE = 64;

typedef struct StringBuilder {
    int length;
    int head;
    char *content;
} StringBuilder;

StringBuilder stringBuilderNew();
void stringBuilderAppend(StringBuilder *sb, char *content);

StringBuilder stringBuilderNew() {
    StringBuilder sb;
    sb.length = SIZE;
    sb.head = 0;
    sb.content = malloc(sizeof(char) * sb.length);
    return sb;
}

void stringBuilderAppend(StringBuilder *sb, char *content) {
   int contentLength = 0;
   while ('\0' != *content) {
       contentLength++;
       content++;
   }
   content-=contentLength;
   if (sb->head == 0) {
       char *sbContent = sb->content;
       for (int i = 0; i < contentLength; i++) {
           *sbContent = *content;
           sbContent++;
           content++;
       }
       *sbContent = '\0';
       sb->head += contentLength;
       return;
   }
   if (sb->head + contentLength < sb->length) {
       char *sbContent = sb->content + sb->head;
       for (int i = 0; i < contentLength; i++) {
           *sbContent = *content;
           sbContent++;
           content++;
       }
       *sbContent = '\0';
       sb->head += contentLength;
       return;
   }
   if (sb->head + contentLength >= sb->length) {
       int wholeParts = contentLength/SIZE;
       int overflow = 0;
       if (contentLength%SIZE!=0) {
           overflow = 1;
       }
       sb->length = sb->length + SIZE * (wholeParts + overflow);
       //create new content
       char *newContent = realloc(sb->content,sizeof(char) * sb->length);
       char *begin = newContent;
       newContent+=sb->head;
       for (int i = 0; i < contentLength; i++) {
           *newContent=*content;
           newContent++;
           content++;
       }
       *newContent = '\0';
       sb->content = begin;
       sb->head += contentLength;
       return;
   }
}

void stringBuilderFree(StringBuilder *sb) {
    free(sb->content);
}
