#include<stdio.h>
#include <stdlib.h>
#define max 10

struct stack{
    int arr[max];
    int top;
};
void initstack(struct stack*s){
    s->top = -1;
}
void pushstack(struct stack*s, int num){
    if(s->top == max-1) {
        printf("Stack is full\n");
        return ;
    }
    s->top++;
    s->arr[s->top] = num;
}

int popstack(struct stack*s){
    int  num;
    if (s->top==-1) {
        printf("Stack is empty \n");
        return -1;
    }
    num=s->arr[s->top];
    s->top--;
    return num;
}

void display(struct stack*s){
    int i;
    for(i=s->top; i>=-1; i--){
        printf( "%d ", s->arr[i]);
    }
    
}

int main(){
    struct stack s;
    int value;
    initstack(&s);
    pushstack(&s,23);
    pushstack(&s,45);
    pushstack(&s,67);
    pushstack(&s,17);
    pushstack(&s,6);
    printf("The elements in the stack are : ");
    display(&s);
    value = popstack( &s );
    printf("\npoped item : %d\n",value);
    printf("The elements in the stack after pop : ");
    display(&s);
    return 0;

}