#include <string.h>
#include <stdio.h>

int longest_word_len(char* string) {
    char *str;
    char sep[] = " ";
    int mxlen = 0;
    char *sep_str;
    int cur_len = 0;
    
    fgets(str,256,stdin);
    sep_str = strtok(str,sep);
    while (strtok(str,sep)!=NULL) {
        printf("%s",sep_str);
        cur_len = strlen(strtok(NULL,sep));
        if (cur_len > mxlen) {
            mxlen = cur_len;
        } 
    }
    printf("%d",mxlen);
    
}
