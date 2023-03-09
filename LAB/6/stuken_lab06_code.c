#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_TELE_LEN 20
#define MAX_BLOCKNOTE_SIZE 9

struct NOTE1 {
    char Name[MAX_NAME_LEN];
    char TELE[MAX_TELE_LEN];
    int DATE[3];
};

int cmp(const void *p1, const void *p2) {
    const struct NOTE1 *note1 = p1;
    const struct NOTE1 *note2 = p2;
    return strcmp(note1->Name, note2->Name);
}

int main() {
    FILE *fp;
    char filename[] = "data.csv";
    char line[1024];
    char *token;
    int i = 0;
    struct NOTE1 BLOCKNOTE[MAX_BLOCKNOTE_SIZE];

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }
    while (fgets(line, sizeof(line), fp)) {
        token = strtok(line, ",");
        strcpy(BLOCKNOTE[i].Name, token);
        token = strtok(NULL, ",");
        strcpy(BLOCKNOTE[i].TELE, token);
        token = strtok(NULL, ",");
        BLOCKNOTE[i].DATE[0] = atoi(token);
        token = strtok(NULL, ",");
        BLOCKNOTE[i].DATE[1] = atoi(token);
        token = strtok(NULL, ",");
        BLOCKNOTE[i].DATE[2] = atoi(token);
        i++;
    }
    fclose(fp);

    qsort(BLOCKNOTE, MAX_BLOCKNOTE_SIZE, sizeof(struct NOTE1), cmp);

    int month;
    printf("Enter number of month(1-12): ");
    scanf("%d", &month);
    printf("Birthdays in %d month:\n", month);
    int found = 0;
    for (i = 0; i < MAX_BLOCKNOTE_SIZE; i++) {
        if (BLOCKNOTE[i].DATE[1] == month) {
            printf("%s, %s\n", BLOCKNOTE[i].Name, BLOCKNOTE[i].TELE);
            found = 1;
        }
    }
    if (!found) {
        printf("There are no people who was born in %d month\n", month);
    }

    return 0;
}
