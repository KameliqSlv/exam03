#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data; 
    struct Node *next;
} Node;

Node* init_linked_list(int val){
    Node *cll= (Node*)malloc(sizeof(Node));
    if(!cll) exit(-1);
    cll->data = val;
    cll->next = NULL;
    return cll;
}


 void print(struct Node *cll){
   

    Node *head = cll; //
    while (head != cll){
        head = head -> next;
        printf("%d", head->data);
    } 
    
    printf("\n");
}


struct Node* insertAfter(struct Node *cll, int skipCount, int newElem){
    Node *head = cll;

    Node *new_last_node = malloc(sizeof(Node));

    for(size_t i = 0; i< skipCount; i++){
        head = head->next;
    }

    new_last_node->data = newElem;
    new_last_node->next = head ->next;
    head ->next = new_last_node;

    return cll;
}

void deinit_linked_list(Node *cll) {

    Node *head = cll;
    while (cll != head) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }


}


int main(){
    Node *cll;
    int N;
    printf("Enter a N: ");
    scanf("%d", &N);

    //Node *cll = init_linked_list(N);

    for(size_t i = 0; i < N; i++){
        int elem;
        scanf("%d", &elem);
        Node *cll = init_linked_list(elem);
        
    }

    int newElement, skip_elem ;
    printf("New elem and skip_elem : ");
    scanf("%d %d", &newElement, &skip_elem);

    insertAfter(cll, skip_elem, newElement);

    print(cll);

    


}