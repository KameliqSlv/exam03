#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_hex_dump(FILE *f){
    unsigned char buf[16];
     while(fread(buf, sizeof(buf), sizeof(buf), f)){
        
        printf("%s", buf);

        
        
        size_t n = sizeof(buf)/sizeof(buf[0]);

        

         for (int i = 0; i < n; i++) {
             if (buf[i] >= 32 && buf[i] <= 126) {
                 printf("%c", buf[i]);
             } else {
                 printf(".");
             }
         }

         printf("|\n");
    
    
    
    }


    




}


void print_binary_dump(FILE *f){
     unsigned char buff[1];
    while(fread(buff, sizeof(buff), sizeof(buff), f)){
    int n = sizeof(buff) / sizeof(buff[0]);
     for (int i = 0; i < n; i++) {
            for (int j = 7; j >= 0; j--) {
                printf("%d", (buff[i] >> j) & 1);
            }
            printf(" ");
        }

        
    }
}


int main(int argc, char *argv[]){
     if(argc != 3){
        fprintf(stderr, "Invalid \n");
    }

    FILE *f = fopen(argv[1], "r");

    if(strcmp(argv[2], "-H")){
        print_hex_dump(f);
    } else if (strcmp(argv[2], "-B")){
        print_binary_dump(f);
    }
}