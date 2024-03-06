# include <stdio.h>
# include <stdlib.h>

struct dnode
{
    struct dnode *prev;
    struct dnode *next;
    int data;
};

void d_append(struct dnode **s, int num){
    struct dnode *r, *q = *s;
    if(*s == NULL){
        *s= (struct dnode*)malloc(sizeof(struct dnode));
        (*s)->prev=NULL;
        (*s)->data=num;
        (*s)->next=NULL;
    } 
    else {
        while(q->next != NULL) q=q->next;
        r=(struct dnode*)malloc(sizeof(struct dnode));
        r->data=num;
        r->prev=q;
        r->next=NULL;
        q->next=r;
    }
}

void d_addatbeg(struct dnode **s,int num){
    struct dnode* q;
    q=(struct dnode*)malloc(sizeof(struct dnode)) ;
    q->data=num;
    q->prev=NULL;
    q->next=*s;
    (*s)->prev=q;
    *s=q;
}

void d_addafter(struct dnode **q, int pos, int num){
    struct dnode *temp;
    int i;
    for(i=0; i<pos-1; i++){
        *q=(*q)->next;
        if (q==NULL){
            printf("Error! The position is larger than the number of nodes.\n");
            return ;
        }
    }
    temp = (struct dnode *) malloc(sizeof(struct  dnode)) ;  
    temp->data = num ;             
    temp->prev = *q ;              
    temp->next = (*q)->next ;                        
    temp->next->prev = temp ;                        
    (*q)->next = temp ;               
}

void d_delete(struct dnode **s, int num){
    struct dnode *q;
    q = *s;
    while(q != NULL){
        if(q->data == num) {
            if(q==*s){
                *s=(*s)->next;
                (*s)->prev=NULL;
            }
            else{
                if(q->next==NULL)
                    q->prev->next=NULL;
                else{
                    q->prev->next=q->next;
                    q->next->prev=q->prev;
                }
            free(q);
            }
         return;
        }
        q=q->next;
    }
    printf("\nThe element %d is not in the list\n",num);
}

void d_display(struct dnode*q){
    while(q!=NULL){
        printf("%d\t",q->data);
        q=q->next;
    }
}

int d_count(struct dnode *q){
    int  count=0;
    while (q!=NULL){
        q=q->next;
        count++;
    }
    return count;
}

int main(){
    int num;
    struct dnode *p;
    p=NULL;
    d_append(&p,12);
    d_append(&p,14);
    d_append(&p,16);
    d_append(&p,17);
    printf("Displaying the doubly linked list:\n");
    d_display(p);
    d_addatbeg(&p,9);
    d_addafter(&p,2,15);
    printf("\nAfter adding an element at beginning and after a specific number: \n");
    d_display(p);
    printf("\nCount of elements in the doubly linked list = %d\n",d_count(p));
    printf("\nEnter a number to delete from list : ");
    scanf("%d",&num);
    printf("\nAfter deleting the given number from the list: \n");
    d_delete(&p,num);
    d_display(p);
}