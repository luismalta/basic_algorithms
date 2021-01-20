#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

struct Node {
    int value;
    Node * next;
};

typedef Node *list;

void insertValue(list &l, int value){

    list newNode = new Node;
    newNode->value = value;

    if(l == NULL){
        newNode->next = NULL;
        l = newNode;
    } else {
        list pointer = l;
        list prevPointer = NULL;
        while (pointer != NULL && pointer->value < value){
            prevPointer = pointer;
            pointer = pointer->next;
        }

        if(prevPointer == NULL){
            newNode->next = l;
            l = newNode;
        } else {
            prevPointer->next = newNode;
            newNode->next = pointer;
        }
        
    }
}

void printList(list &l){
    list aux = l;
    while(aux != NULL){
        printf("Valor: %d\n", aux->value);
        aux = aux->next;
    }

}

int main(){
    list l = NULL;

    insertValue(l, 5);
    insertValue(l, 10);
    insertValue(l, 15);
    insertValue(l, 4);
    insertValue(l, 40);

    printList(l);
}
