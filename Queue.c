// 4번 문제 Queue 구현
#include <stdio.h>
#define MAX 3
int front = 0;
int rear = -1;
int queue[MAX];

int IsFull(void)
{
    if(rear >= MAX-1){
        printf("Queue is full!\n");
        return 1;
    }else {
        return 0;
    }
}

int IsEmpty(void)
{
    if(rear < 0){
        printf("Queue is empty!\n");
        return 1;
    }else{
        return 0;
    }
}

void Insert(void)
{
    int elem;
    printf("Element : ");
    scanf("%d", &elem);
    if(!IsFull()){
        queue[++rear] = elem;
        printf("Successfully Insert\n");
    }
}

void Delete(void)
{
    if(!IsEmpty()){
        printf("Deleted item : %d\n", queue[front++]);
        for(int i=0; i<rear; i++){
            queue[i] = queue[i+1];
        }
        front--;
        rear--;
    }
}

void Display(void)
{
    if(!IsEmpty()){
        printf("Items : ");
        for(int i=front; i<=rear; i++){
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int opt;
    while(1){
        printf("1.Insertion\n2.Deletion\n3.Display\n0.Exit\n\n");
        printf("Select Option : ");
        scanf("%d", &opt);
        if(opt == 1){
            Insert();
        }else if(opt == 2){
            Delete();
        }else if(opt == 3){
            Display();
        }else if(opt == 0){
            break;
        }else{
            printf("Wrong option!\n");
        }
    }

    return 0;
}