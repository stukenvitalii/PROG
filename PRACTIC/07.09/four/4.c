#include <stdio.h>
#include <string.h>

int word_count(char* string) {
    char *sep_str;
    int count = 0;
    int cur_len = 0;
    sep_str = strtok(string," ");
    while (sep_str != NULL) {
        cur_len = strlen(sep_str);
        if (sep_str[0] == sep_str[cur_len-1]) {
            count++;
        }
        sep_str = strtok(NULL," ");
    }
    return count;
}

int main() {
    char string[] = "properlydjdp ksdjfsdfk ksjfskdfj ksjdfhksdjfs";
    int res = word_count(string);
    printf("%d",res);
    return 0;
}