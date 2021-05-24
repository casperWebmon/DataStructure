//Single linked list 로 구현한 2번 문제
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node * next;
} Node;

typedef struct _list {
    Node * head;
    Node * cur;
    Node * tail;
    int numOfData;
} List;

void ListInit(List * list)
{
    list->head = NULL;
    list->cur = NULL;
    list->tail = NULL;
    list->numOfData = 0;
}

void FirstInsert(List * list)
{
    Node * newNode = NULL;
    int data;
    printf("Enter 5 elements in list: ");
    for(int i=0; i<5; i++){
        newNode = (Node*)malloc(sizeof(Node));
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;
        // first 5 elements insert
        if(list->head == NULL){
            list->head = newNode;
            list->tail = newNode;
        }else{
            list->tail->next = newNode;
            list->tail = newNode;
        }
        list->numOfData++;
    }
    // first 5 elements print
    printf("Stored element in list: ");
    list->cur = list->head;
    for(int i=0; i<list->numOfData; i++){
        printf("%d ", list->cur->data);
        list->cur = list->cur->next;
    }
    printf("\n");
}

int IsPossiblePos(List * list, int pos)
{
    if(pos < 1 || pos > list->numOfData){
        printf("Incorrect access to list poss!\n");
        return 0;
    }else{
        return 1;
        }
}

void Remove(List * list)
{
    Node * temp = NULL;
    int newPos = -1;
    printf("Enter poss. of element to delete: ");
    scanf("%d", &newPos);
    if(IsPossiblePos(list, newPos)){
        temp = (Node*)malloc(sizeof(Node));
        list->cur = list->head;
        if(newPos == 1){
            if(list->numOfData == 1){
                temp = list->cur;
                free(list);
            }else{
                temp = list->cur;
                list->cur = list->head->next;
                list->head = list->cur;
            }
        }else if(newPos == 2){
            list->cur = list->head->next;
            temp = list->cur;
            list->head->next = list->cur->next;
        }else{
            for(int i=0; i<newPos-2; i++){
                list->cur = list->cur->next;
            }
            temp = list->cur->next;
            list->cur->next = temp->next;
            list->cur = list->cur->next;
        }
        free(temp);
        list->numOfData--;
        // Stored data print
        printf("After deletion elements in list: ");
        list->cur = list->head;
        for(int i=0; i<list->numOfData; i++){
            printf("%d ", list->cur->data);
            list->cur = list->cur->next;
        }
        printf("\n");
    }
}

int main()
{
    List list;
    ListInit(&list); // set list
    FirstInsert(&list);

    while(list.numOfData > 0){
        Remove(&list);
    }
    printf("List is empty\n");

    return 0;
}