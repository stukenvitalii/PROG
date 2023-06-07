#include <stdio.h>

typedef struct IP {
    unsigned int first:8;
    unsigned int second:8;
    unsigned int third:8;
    unsigned int fourth:8;
} IPN;

int main() {
    int first,second,third,fourth;
    printf("Enter IP adress(Class C): \n");
    scanf("%d.%d.%d.%d",&first,&second,&third,&fourth);
    if (first < 256 && second < 256 && third < 256 && fourth < 256) {
        IPN ip = {first,second,third,fourth};
    
        printf("Your IP:\n");
        printf("%d.%d.%d.%d\n",ip.first,ip.second,ip.third,ip.fourth);
    
        ip.first = (ip.first & 192) | 192;
        ip.second = (ip.second & 168) | 168;
        printf("New IP:\n");
        printf("%d.%d.%d.%d",ip.first,ip.second,ip.third,ip.fourth);
    
    }
    else {
        puts("error");
    }
    
    return 0;
}