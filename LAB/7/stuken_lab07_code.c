#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct computer {
    char* name;
    char* manufacturer;
    int ram;
    int number_of_cpus;
    int storage;
    int* max_core_frequency;
};

typedef struct computer computers;

int main() {

    computers my_computer;

    return 0;
}