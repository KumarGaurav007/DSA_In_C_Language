#include<stdio.h>
#define max 10

void enqueue(int *arr, int num, int *front, int *rear){
    if (*rear == max - 1) {
        printf("Queue is Full\n");
        return;
    }
    (*rear)++;
    arr[*rear] = num;
    if(*front==-1){
        *front=0;
    }
}

int dequeue(int *arr, int* front, int *rear){
    int data;
    if (*front == -1 ){
        printf("Queue is Empty \n");
        return -1;
    }
    data = arr[*front];
    arr[*front]= 0;
    if( *front == *rear ) {
        *front = *rear = -1;
    } 
    else {
        (*front)++ ;
        return data;
    }
}

void display(int *arr, int* front, int *rear) {
  if (front == rear) {
    printf("Queue is empty.\n");
    return;
  }

  for (int i = *front ; i <= *rear; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");
}

    


int main(){
    int arr[max];
    int front = -1, rear = -1, val;

    enqueue(arr,23,&front, &rear);
    enqueue(arr,12,&front, &rear);
    enqueue(arr,86,&front, &rear);
    enqueue(arr,41,&front, &rear);
    printf("The Queue elements are : ");
    display(arr,&front, &rear);
    val=dequeue(arr,&front, &rear);
    printf("%d is Deleted from Queue\n",val);
    printf("Queue elements after dequeue : ");
    display(arr,&front, &rear);
    
    return 0;
}