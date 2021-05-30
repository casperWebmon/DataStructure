#include <stdio.h>

typedef struct _arrayList {
    int arr[5];
    int numOfData;
    int curPos;
} List;

void ListInit(List * list)
{
    list->numOfData = 0;
    list->curPos = -1;
}

int IsEmpty(List * list)
{
    if(list->numOfData <= 0) return 1;
    else return 0;
}

int SetPos(List * list, int pos)
{
    if(pos < 1 || pos > list->numOfData){
        printf("Incorrect access to array index!\n");
        return 0;
    }else{
        list->curPos = pos-1;
        return 1;
    }
}

void Remove(List * list)
{
    int newPos;
    printf("Enter poss. of element to delete: ");
    scanf("%d", &newPos);
    if(SetPos(list, newPos)){
        for(int i=list->curPos; i<list->numOfData-1; i++){
            list->arr[i] = list->arr[i+1];
        }
        list->numOfData--;
        printf("After deletion elements in array: ");
        for(int i=0; i<list->numOfData; i++){
            printf("%d ", list->arr[i]);
        }
        printf("\n");
    }
}

int main()
{
    List list;
    ListInit(&list); // set list
    printf("Enter 5 elements in array: ");
    for(int i=0; i<5; i++){
        list.curPos++;
        scanf("%d", &list.arr[list.curPos]); // first 5 elements insert
        list.numOfData++;
    }
    printf("Stored element in array: ");
    for(int i=0; i<5; i++){
        printf("%d ", list.arr[i]); // first 5elements puts
    }
    printf("\n");

    while(!IsEmpty(&list)){
        Remove(&list);
    }
    printf("Array is empty\n");

    return 0;
}
