#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRUCT_SIZE 32
#define MAXLEN 128

struct computer {
    char* NAME;
    char* MANUFACTURER; /**/
    int RAM; /*number of ram*/
    int NUMBER_OF_CORES; /*number of cores in cpu*/
    float CPU_FREQUENCY; /**/
    int STORAGE_CAPACITY[2]; /*capacity for each element of memory*/
    float PRICE; /*price in thousands of rubles*/
    int WINDOWS_LICENSE_KEY[3];
};

typedef struct computer computers;

void add_new_el_to_struct(computers** new_computer, int index);
void struct_out(computers* struct_0);
void sort_by_storage(computers** str,int n);
void sort_by_WLK(computers** str,int n);

int main() {

    FILE *fp;
    char filename[] = "D:\\tanki\\University\\PROG\\LAB\\7\\data7.csv";
    char line[128];
    char sep[2] = ";";
    char* buffer1;
    char* buffer2;
    char value;
    int option1,option2;
    int i = 0;
    computers **my_computer = NULL;

    if ((fp = fopen("data7.csv","r")) != NULL) {
        int n = 0;
        while ((fgets(line,MAXLEN,fp))!=NULL) n++;
        rewind(fp);
        my_computer = (computers**)malloc(n*sizeof(computers*));
        if (my_computer != NULL) {
            for (i = 0;i < n;i++) {
                if (fgets(line,MAXLEN,fp) != NULL) {
                    my_computer[i] = (computers*)malloc(n*sizeof(computers));
                    buffer1 = strtok(line,sep);
                    buffer2 = strtok(NULL,sep);

                    int len1 = strlen(buffer1);
                    int len2 = strlen(buffer2);

                    my_computer[i]->NAME = (char*)malloc((len1+1)*sizeof(char));
                    my_computer[i]->MANUFACTURER = (char*)malloc((len2+1)*sizeof(char));

                    strcpy(my_computer[i]->NAME,buffer1);
                    strcpy(my_computer[i]->MANUFACTURER,buffer2);
                    my_computer[i]->RAM = atoi(buffer1 = strtok(NULL,sep));
                    my_computer[i]->NUMBER_OF_CORES = atoi(buffer1 = strtok(NULL,sep));
                    my_computer[i]->CPU_FREQUENCY = atof(buffer1 = strtok(NULL,sep));
                    my_computer[i]->STORAGE_CAPACITY[0] = atoi(buffer1 = strtok(NULL,sep));
                    my_computer[i]->STORAGE_CAPACITY[1] = atoi(buffer1 = strtok(NULL,sep));
                    my_computer[i]->PRICE = atof(buffer1 = strtok(NULL,sep));
                    my_computer[i]->WINDOWS_LICENSE_KEY[0] = atoi(buffer1 = strtok(NULL,sep));
                    my_computer[i]->WINDOWS_LICENSE_KEY[1] = atoi(buffer1 = strtok(NULL,sep));
                    my_computer[i]->WINDOWS_LICENSE_KEY[2] = atoi(buffer1 = strtok(NULL,sep));
                }
                else printf("Error!");
            }
        }
        else printf("Error at memory allocation!");
        fclose(fp);
    }
    else perror("Data error!");


    system("cls");
    printf("MENU\n\n");
    printf("Add new computer - 1\n");
    printf("Search for a value in arrays - 2\n");
    printf("Sort computers - 3\n");
    printf("Show all computers - 4\n");
    scanf("%d",&option1);

    if (option1 == 1) {
        my_computer = (computers**)realloc(my_computer,(i+1)*sizeof(computers*));
        add_new_el_to_struct(my_computer,i);
        getchar();
        printf("New computer succesfully added! Press Enter to continue...");
        getchar();
        i++;
    }
    else if (option1 == 2) {
        printf("Choose a filed with an array of integers: \n");
        printf("Press 1 to choose STORAGE_CAPACITY\n");
        printf("Press 2 to choose WINDOWS_LICENSE_KEY\n");
        scanf("%d",&option2);

        printf("Enter an value to search:\n");
        scanf("%d",&value);

        if (option2 == 1) {
            for (int j = 0;j < i;j++) {
                if ((my_computer[j]->STORAGE_CAPACITY[0] == value) || my_computer[j]->STORAGE_CAPACITY[1] == value) {
                    struct_out(my_computer[j]);
                    printf("\n");
                }
            }
        }
        else if (option2 == 2) {
            for (int j = 0;j < i;j++) {
                if ((my_computer[j]->WINDOWS_LICENSE_KEY[0] == value) || my_computer[j]->WINDOWS_LICENSE_KEY[1] == value || my_computer[j]->WINDOWS_LICENSE_KEY[2] == value) {
                    struct_out(my_computer[j]);
                    printf("\n");
                }
            }
        }
    }
    else if (option1 == 3) {
        printf("Choose option to sort: \n");
        printf("Sort by WINDOWS LICENSE KEY - 1\n");
        printf("Sort by STORAGE CAPACITY - 2\n");
        int option3;
        scanf("%d",&option3);

        if (option3 == 1) {
            sort_by_WLK(my_computer,i);
            for (int j = 0;j < i;j++) {
                struct_out(my_computer[j]);
        }
        }
        else {
            sort_by_storage(my_computer,i);
            for (int j = 0;j < i;j++) {
                struct_out(my_computer[j]);
        }
        }
    }
    else if (option1 == 4) {
        for (int j = 0;j < i;j++) {
            struct_out(my_computer[j]);
        }
    }
    return 0;
}
void sort_by_storage(computers** str,int n) {
    computers* tmp_struct;
    int i,j;
    for (i = 0;i < n;i++) {
        tmp_struct=str[i];
        for(j=i-1;(j>=0)&&((str[j]->STORAGE_CAPACITY[0])>(tmp_struct->STORAGE_CAPACITY[0]));j--)
            str[j+1]=str[j];
        str[j+1]=tmp_struct;
    }
}
void sort_by_WLK(computers** str,int n) {
    computers* tmp_struct;
    int i,j;
    for (i = 0;i < n;i++) {
        tmp_struct=str[i];
        for(j=i-1;(j>=0)&&((str[j]->WINDOWS_LICENSE_KEY[1])>(tmp_struct->WINDOWS_LICENSE_KEY[1]));j--)
            str[j+1]=str[j];
        str[j+1]=tmp_struct;
    }
}
void struct_out(computers* str0) {
    printf("|%20s |%7s |%2d |%2d |%4.5f |%d,%d | %2.2f |%d-%d-%d |\n",
        str0->NAME,str0->MANUFACTURER,str0->RAM,str0->NUMBER_OF_CORES,str0->CPU_FREQUENCY,str0->STORAGE_CAPACITY[0],str0->STORAGE_CAPACITY[1],str0->PRICE,str0->WINDOWS_LICENSE_KEY[0],str0->WINDOWS_LICENSE_KEY[1],str0->WINDOWS_LICENSE_KEY[2]);

}
void add_new_el_to_struct(computers **new_computer, int index) {
    char buffer[MAXLEN];

    new_computer[index] = (computers*)malloc(sizeof(computers));

    printf("Enter a name of a new computer:");
    getchar();
    fgets(buffer,MAXLEN,stdin);
    buffer[strlen(buffer)-1] = "\0";
    new_computer[index]->NAME = (char*)malloc((strlen(buffer)+1)*sizeof(char));
    strcpy(new_computer[index]->NAME,buffer);

    printf("Enter a manufacturer");
    fgets(buffer,MAXLEN,stdin);
    buffer[strlen(buffer)-1] = "\0";
    new_computer[index]->MANUFACTURER = (char*)malloc((strlen(buffer)+1)*sizeof(char));
    strcpy(new_computer[index]->MANUFACTURER,buffer);

    printf("Enter RAM: ");
    scanf("%d",&new_computer[index]->RAM);

    printf("Enter NUMBER OF CORES: ");
    scanf("%d",&new_computer[index]->NUMBER_OF_CORES);

    printf("Enter CORE FREQUENCY: ");
    scanf("%f",&new_computer[index]->CPU_FREQUENCY);

    printf("Enter STORAGE_CAPACITY: ");
    scanf("%d %d",&new_computer[index]->STORAGE_CAPACITY[0],&new_computer[index]->STORAGE_CAPACITY[1]);

    printf("Enter price in RUB(float): ");
    scanf("%f",&new_computer[index]->PRICE);

    printf("Enter WINDOWS_LICENSE_KEY: (*****;*****;*****)");
    scanf("%d-%d-%d",&new_computer[index]->WINDOWS_LICENSE_KEY[0],&new_computer[index]->WINDOWS_LICENSE_KEY[1],&new_computer[index]->WINDOWS_LICENSE_KEY[2]);
}