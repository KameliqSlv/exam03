#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COUNT 40

typedef struct Product
{
     double old_price; //8
     double new_price; //8
     unsigned int id;  //4
     char product_type; //1 = 21 == 24
     char product_name[20];  //20??
}Product;

Product product[COUNT];

void printProduct() {
    printf("ID: %u, Type: %c, Name: %s, Old Price: %.2f, New Price: %.2f\n",
           product->id, product->product_type, product->product_name,
           product->old_price, product->new_price);
}

int gen_id(){
    int i;
    return i++;
}

int sort(const void *a,const void *b){
    Product *prodA = (Product*)a;
    Product *prodB = (Product*)b;
}



int main(){
    

    for (size_t i = 0; i < COUNT; i++) {
        //[4.99 - 100.45]
        product[i].old_price = 4.99 + (rand() % 9547) / 100.0;
        product[i].new_price = 4.99 + (rand() % 9547) / 100.0;

        char type[] = {'A','B','C','D'};
        int size = sizeof(type)/sizeof(type[0]);
        int index = rand() %size;
        product[i].product_type = index ;
        
        char *names[] = {"ProductA", "ProductB", "ProductC", "ProductD"};
        int n = sizeof(names) / sizeof(names[0]);
        int index1 = rand() % n;
        strcpy(product[i].product_name, names[index1]);
        
        product[i].id = gen_id();


    }


    printProduct();
}