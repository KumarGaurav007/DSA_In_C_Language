# include <stdio.h>
# include "stdlib.h"


struct node{
    int data;
    struct node *link;
};

void push(struct node **top, int num){
    struct node *temp;
    temp= (struct node*)malloc(sizeof(struct node));
    temp->data =num;
    temp->link=(*top);
    (*top) = temp;
}


int pop(struct node **top){
    struct node *temp;
    int item;
    if (*top == NULL){
        printf("Stack is empty\n");
       
    }else{

    temp = *top;
    item = temp->data;
    *top =(*top)->link;
    free(temp);
    return item; 
    }
}

void delstack(struct node ** top){
    struct node *temp;
    if  (*top==NULL){
        printf("The stack is already empty \n");
        return ;
    }
    while (*top != NULL ) {
        temp = *top;
        *top = (*top)->link;
        free(temp);
    }
    return ;
}

void display(struct node *top){
    struct node*i=top;
    if(i==NULL){
        printf("\n The Stack is Empty ");
    }
    while(i != NULL){
        printf( "%d\t", i->data );
        i = i -> link;
    }
    
        
}

int main(){
    struct node *s = NULL;
    int i;
    push(&s,10);
    push(&s,15);
    push(&s,37);
    push(&s,81);
    push(&s,29);
    printf("stack elements : ");
    display(s);
    i=pop(&s) ;
    printf("\n%d popped from the stack\n",i);
    printf("stack elements after pop : ");
    display(s);
    delstack(&s);
    display(s);
    return 0;
}