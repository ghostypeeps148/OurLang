#include "util.h"
char* trim_leading_spaces(char* str) {
    int i = 0;
    while (str[i] == ' ') {
        i++;
    }
    const int newlen = strlen(str) - i;
    char dest[newlen];
    strncpy(dest, str + i, newlen);
    dest[newlen+1] ='\0';
    return strdup(dest);
}
