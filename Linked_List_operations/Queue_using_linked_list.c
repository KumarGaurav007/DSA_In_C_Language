#include <stdio.h>
#include <malloc.h>
struct node{
    int data;
    struct node*next;
};

// Global declaration of front and rear.
struct node*front=NULL;
struct node*rear=NULL;

// Function to print elements in  queue
void  dispaly(){
    struct node*temp;
    temp=front;
    while (temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    
}

// Function for adding elements in queue.
int Enqueue(int data){
    struct node*n=(struct node*)malloc(sizeof(struct node));
    if(n == NULL){
        printf("Queue Overflow\n");
    }
    else{
        n->data = data;
        n->next = NULL;
        if(front == NULL){
            front = rear = n;
        }
        else{
            rear->next = n;
            rear = n;
        }
    }
}

// Function to delete elements from queue.
int Dequeue(){
    int val = -1;
    if(front == NULL){
        printf("Queue is Empty\n");
        return 0;
    }
    struct node*n = (struct node*)malloc(sizeof(struct node));
    n = front;
    front = front->next;
    printf("\nDeleted element : %d\n",n->data);
    free(n);
}

// Main function where other functions are called.
int main(){
    
    Enqueue(51);
    Enqueue(10);
    Enqueue(20);
    Enqueue(35);
    Enqueue(94);
    printf("\nElements in Queue : ");
    dispaly();
    Dequeue();
    printf("\nElements in Queue afte deletion : ");
    dispaly();
    return 0;
}