#include <stdio.h>
#include <string.h>
#define MAXLEN 512

void print_k_times(char symbol,int k);
void fill_with_zeros(int* array,int length);

int main() {
    char separators[MAXLEN];
    char string[MAXLEN];
    char vowels[MAXLEN];

    puts("Enter string of text: ");
    fgets(string,MAXLEN,stdin);

    puts("Enter string of separators: ");
    fgets(separators,MAXLEN,stdin);
    
    puts("Enter string of vowels: ");
    fgets(vowels,MAXLEN,stdin);

    int vowels_length = strlen(vowels)-1;
    int vowel_count[vowels_length];
    fill_with_zeros(vowel_count,vowels_length);
    
    for (int i = 0;i < strlen(vowels)-1;i++) {
        for (int j = 0;j < strlen(string)-1;j++) {
            if (string[j] == vowels[i]) {
                vowel_count[i]++;
            }
        }
    }
    for (int i = 0;i < strlen(vowels)-1;i++) {
        printf("%c: ",vowels[i]);
        print_k_times('*',vowel_count[i]);
        puts("\n");
    }

    return 0;
}

void print_k_times(char symbol,int k) {
    for (int i = 0; i < k; i++) {
        printf("%c",symbol);
    }
}

void fill_with_zeros(int* array,int length) {
    for (int i = 0;i < length;i++) {
        array[i] = 0;
    }
}