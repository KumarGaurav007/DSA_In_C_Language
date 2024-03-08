# include <stdio.h>
# include <stdlib.h>

struct  cnode{
    int data;
    struct cnode *link;
};

void addcirq(struct cnode **head,int num) {
    struct cnode *q, *temp;
    q = (struct cnode*)malloc(sizeof(struct cnode));
    q->data=num;
    if(*head==NULL){
        *head=q;
        q->link=*head;
    }
    else{
        temp=*head;
        while(temp->link!=*head)
            temp=temp->link;
        temp->link=q;
        q->link=*head;
    }
}

void delcirq(struct cnode **head, int num) {
    struct cnode *q, *temp;
    q=*head;
    if(*head == NULL){
        printf( "The list is empty\n" );
        return ;
    }
    if((*head)->link == *head && ( *head )->data == num) {     // condition for only one node in the list
        free( *head );
        *head = NULL;
        
    }
    else{
        if((*head)->data == num){
            temp=*head;
            while(q->link != *head){
                q = q -> link;
            }
            q->link=(*head)->link;
            *head=(*head)->link;
            free(temp);
        }
        while(q->link != *head){
            if(q->data == num) {
                temp->link = q->link;
                free( q );
                return;
            }
            else{
                temp=q;
                q=q->link;
            }
        }
        if(q->link==*head && q->data==num){  // condition for last node.
            temp->link=q->link;
            free(q);
        }
            
    }
}

void cirqdisplay(struct cnode *head) {
    struct cnode *ptr;
    ptr = head;
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    } while (ptr != head);
    
}

int main() {
    struct cnode *p ;
    p=NULL;  
    addcirq(&p,14 );
    addcirq(&p,15 );
    addcirq(&p,17 );
    addcirq(&p,18 );
    addcirq(&p,16 );
    printf("\nDisplaying Circular Linked List : \n");
    cirqdisplay(p);
    delcirq( &p , 15);
    printf("\nAfter deleting the circular linked list :\n");
    cirqdisplay(p);
}  