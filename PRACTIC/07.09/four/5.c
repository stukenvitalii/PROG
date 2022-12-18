#include <stdio.h>
#include <string.h>
// #include <stdlib.h>

int is_in(char el, char* string) {
    int answer = 0;
    for (int i = 0;i < strlen(string) && answer == 0;i++) {
        if (string[i] == el) {
            answer = 1;
        }
    }
    return answer;
}

char* replace_consonants_with_1(char* string) {
    char* consonants = "BCDFGHJKLMNPQRSTVWXZbcdfghjklmnpqrstvwxz";
    for (int i = 0;i < strlen(string);i++) {
        if (is_in(string[i],consonants) == 1) {
            string[i] = 1;
        }
    }
}

int main() {
    char string[] = "Received the likewise law graceful his";
    replace_consonants_with_1(string);
    printf("%s",string);
    return 0;
}