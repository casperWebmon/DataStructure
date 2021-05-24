// 5번 문제 Stack 구현  
#include <stdio.h>
#include <string.h>
#define MAX 3
int stack[MAX];
int topIndex = -1;

int IsFull(void)
{
    if(topIndex >= MAX){
        printf("Stack is full!\n");
        return 1;
    }else {
        return 0;
    }
}

int IsEmpty(void)
{
    if(topIndex == -1){
        printf("Stack is empty!\n");
        return 1;
    }else{
        return 0;
    }
}

int WantContinue(void){
    char req[2];
    printf("Pushed an element (Y/N): ");
    scanf("%s", req);
    printf("\n");
    if(!strcmpi(req, "Y")) return 1;
    else return 0;
}

void Push(void)
{
    int num;
    while(!IsFull()){
        printf("Enter element in stack: ");
        scanf("%d", &num);
        printf("\n");
        stack[++topIndex] = num;
        if(!WantContinue()){
            break;
        }
    }
}

void Pop(void)
{
    if(!IsEmpty()){
        printf("deleted data is : %d\n", stack[topIndex--]);
        printf("\n");
        if(WantContinue()){
            Push();
        }
    }
}

void Display(void)
{
    int temp[50];
    for(int i=topIndex; i>=0; i--){
        printf("%d\n", stack[i]);
    }
    printf("\n");
    if(WantContinue()){
        Push();
    }
}

int main()
{
    int opt = 0, num;
    while(1){
        printf("1: push\n2: pop\n3: display\n4: exit\n");
        printf("enter your choice: ");
        scanf("%d", &opt);
        printf("\n");
        if(opt == 1){
            Push();
        }else if(opt == 2){
            Pop();
        }else if(opt == 3){
            Display();
        }else if(opt == 4){
            break;
        }else{
            printf("Wrong option!\n");
        }
    }

    return 0;
}