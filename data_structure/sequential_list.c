#include<stdio.h>
#include<stdlib.h>

#define DEFAULT_SIZE 10

struct Node {
    char key;
    int value;
};

struct SequentialList {
    struct Node data[DEFAULT_SIZE];
    int size;
};

int insertValue(struct SequentialList *list, int value){
    if (list->size == 10){
        return 0;
    } else {
        int index = 0, point;
        while (index < list->size && list->data[index].value < value){
            index++;
        }
        point = index;

        index = list->size - 1;
        
        while(index >= point){
            list->data[index + 1].value = list->data[index].value;
            index--;
        }

        list->data[index + 1].value = value;
        list->size++;
        return 0;
    }
}

int removeValue(struct SequentialList *list, int value){
    for(int index=0; index < list->size; index++){
        if (list->data[index].value == value){
            int index2 = index;
            while(index2 < list->size - 1){
                list->data[index2].value = list->data[index2 + 1].value;
                index2++;
            }
            list->size--;
            index--;
        }
    }
}

int searchValue(struct SequentialList *list, int value){
    for(int index=0; index < list->size; index++){
        if (list->data[index].value == value){
            printf("Value found in index %d\n", index);
        }
    }
}

int printList(struct SequentialList *list){
    int index = 0;

    printf("----- List -------\n");
    while(index < list->size){
        printf("List [%d]: %d \n", index, list->data[index].value);
        index++;
    }
    printf("\n");
}

struct SequentialList createList(){
    struct SequentialList list;
    list.size = 0;
    return list;
}

int main(){

    struct SequentialList list = createList();

    insertValue(&list, 10);
    insertValue(&list, 20);
    insertValue(&list, 30);
    printList(&list);

    removeValue(&list, 30);
    printList(&list);

}