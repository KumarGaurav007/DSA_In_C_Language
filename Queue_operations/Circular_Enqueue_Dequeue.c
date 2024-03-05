# include<stdio.h>
# define max 10

void addq(int *arr, int num, int *front, int*rear){
    if( (*rear + 1) % max == *front ) {
        printf("Queue is Full\n");
        return;
    }
    if(*rear==max-1){
        *rear=0;
    }
    else{   
        (*rear)++;
    }
    arr[*rear] = num;
    if (*front==-1){
        *front=0;
    }
}

int deleteq(int *arr, int *front, int *rear){
    int data;
    if(*front==-1){
        printf("\n Queue is Empty \n");
        return NULL;
    }
    data = arr[*front];
    arr[*front]= 0;
    if(*front==*rear) {
        *front=-1;
        *rear=-1;
    }   
    else{
        if(*front=max-1){
            *front=0;
        }
        else{
            (*front)++ ;
        }
    }
    return data;
}

void display(int *arr, int front, int rear) {
    int i;
    for ( i = front; i <= rear; i++)
    {
        printf("%d, ",arr[i]);
    }
    
}

int main(){
    int arr[max], i, front, rear;
    front=rear=-1;
    for(i=0;i<max;i++){
        arr[i]=0;
    }
    addq(arr,14,&front, &rear);
    addq(arr,23,&front, &rear);
    addq(arr,56,&front, &rear);
    addq(arr,91,&front, &rear);
    printf("Displaying the queue elements:\n");
    display(arr,front,rear);
    i=deleteq(arr,&front,&rear) ;
    printf("\n Deleted element %d",i);
    printf("\n Displaying the queue after dequeue : ") ;
    display(arr,front,rear);
    return 0;
}