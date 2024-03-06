#include<stdio.h>
#include "stdlib.h"

// creating  a node structure  for linked list
struct node{
    int data;
    struct node *link;  //point to next node in the list
};

//function to append  nodes at end of the list
void append(struct node **q, int num){
    struct node *temp, *r;
    if(*q==NULL){
        temp= (struct node*)malloc(sizeof(struct node)); //dynammic memory allocation 
        temp->data =num;
        temp->link= NULL;
        *q=temp;
    }else{
        temp=*q;
        while(temp->link != NULL)  //traversing  through the list till we reach the last element
             temp=temp->link;

    // add a node at the end
        r=(struct node*) malloc(sizeof(struct node));
        r->data=num;
        r->link=NULL;
        temp->link=r;
    }
}

//function to add node at the begning  of the list
void addatbeg(struct node **q, int num){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = num;
    temp->link = (*q);
    (*q)=temp;
}

//function to add a node  after a given position found in the list
void addafter(struct node *q, int  pos, int num){ 
    struct node *temp, *r;
    int i;
    temp=q;
    for(i=0;i<pos-1;i++){
        temp = temp->link;
    }
	if(temp == NULL) 
    printf("\nthere are less than %d elements in list.",pos);
	else { 
        r=(struct node*)malloc(sizeof(struct node)) ;
        r->data=num;
        r->link=temp->link;
        temp->link=r;
    }
}

   //function to delete a node                                 
void delete(struct node **q, int num){
    struct node*temp, *old;
    temp= *q;
    while (temp != NULL)
    {
        if(temp->data==num){
            if (temp == *q)
                *q = (*q)->link;
            else
                old->link = temp->link;
            free(temp);
            return;
        }
        else{
        old = temp;
        temp = temp->link;
        }
    }
    printf("\nElement %d is not present in the list",num);
}

//function to display list elements.	
void display(struct node *q){
    while(q!=NULL){
        printf("%d\t", q->data);
        q=q->link;
    }
}

//function to count  number of nodes with given list.
int count(struct node *q){
    int c=0;
    while (q != NULL)
    {
        q=q->link;
        c++;
    }
    return c;
}


int main(){
    struct node *p;
    p=NULL;

    append(&p, 12);
    append(&p, 345);
    append(&p, 34);
    append(&p, 45);
    printf( "Elements in Linked List:\n");
    display(p);
    addatbeg(&p, 6);
    addatbeg(&p, 51);
    addafter(p, 2, 27);
    printf("\nTotal elements in list = %d" ,count(p));
    printf("\n\nList after adding element at beginning and after a specified position: \n");
    display(p);
    delete(&p, 45);
    printf("\n\nList After Deleting an Element from it : \n");
    display(p);
    
}