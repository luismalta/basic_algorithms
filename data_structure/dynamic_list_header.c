#include <stdlib.h>
#include <stdio.h>

struct Node {
    int info;
    struct Node * next;
};

struct Node *initList(struct Node *list){
    //Init List with aux header
    list->info = -1;
    list->next = NULL;
    return list;
}

int insertValue(struct Node *list, int value){

    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->info = value;

    if(list->next == NULL){
        newNode->next = NULL;
        list->next = newNode;
    } else {
        struct Node *pointer =  list;
        struct Node *pointerPrev = NULL;

        while(pointer->next != NULL && pointer->info < value){
            pointerPrev = pointer;
            pointer = pointer->next;
        }
    
        if(pointerPrev==NULL){
            list = newNode;
        } else {
            if(pointer->next == NULL && pointer->info < value){
                pointer->next = newNode;
            } else {
                pointerPrev->next = newNode;
                newNode->next = pointer;
            }
            
        }
    }
}

int printList(struct Node *list){

    struct Node *pointer = list;
    int index = 0;
    while(pointer != NULL){
        printf("List [%d]: %d\n", index, pointer->info);
        pointer = pointer->next;
        index++;
    }
}

int main(){
    struct Node list;
    initList(&list);
    insertValue(&list, 10);
    insertValue(&list, 3);
    insertValue(&list, 15);
    insertValue(&list, 1);
    printList(&list);    
}