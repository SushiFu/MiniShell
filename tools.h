#ifndef _TOOLS_H_
#define _TOOLS_H_

#define BUFF_SIZE 8192

void* xmalloc(int size);
void puterr(char *c);
void putstr(char *c);
int my_strlen(char *c);
int count_words(char* str, char delim);
char** str_to_words(char* str, char delim);
char* str_concat(char* str1, char* str2);
int str_equals(char* str1, char* str2);
char* str_tri_concat(char* str1, char* str2, char* str3);

#endif
