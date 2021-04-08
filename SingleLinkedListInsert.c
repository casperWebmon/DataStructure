//Single linked list 로 구현한 1번 문제 
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

void Insert(List * list)
{
    Node * newNode = NULL;
    int newPos, newElem;
    printf("Enter position for enter element: ");
    scanf("%d", &newPos);
    if(IsPossiblePos(list, newPos)){
        newNode = (Node*)malloc(sizeof(Node));
        printf("Enter new element: ");
        scanf("%d", &newElem);
        newNode->data = newElem;
        newNode->next = NULL;
        list->cur = list->head;
        if(newPos == 1){
            newNode->next = list->head;
            list->head = newNode;
            list->numOfData++;
        }else if(newPos == 2){
            newNode->next = list->head->next;
            list->head->next = newNode;
            list->numOfData++;
        }else{
            for(int i=0; i<newPos-2; i++){
               list->cur = list->cur->next; 
            }
            newNode->next = list->cur->next;
            list->cur->next = newNode;
            list->numOfData++;
        }
        // Stored data print
        printf("Stored data in list: ");
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

    while(list.numOfData <= 50){
        Insert(&list);
    }
    printf("List is full\n");

    return 0;
}