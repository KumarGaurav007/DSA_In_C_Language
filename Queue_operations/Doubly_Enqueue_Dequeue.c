# include<stdio.h>
# define max 10

void insertfront(int *arr, int num, int *front, int *rear){
    if((*rear == max-1 &&  *front==0) || (*front == *rear+1)) {
        printf("DeQueue is full\n"); 
        return;
    }
    if(*front == -1){
        *front = 0;
        *rear = 0;
    }
    else if(*front==0){
        *front=max-1;
    }
    else{
        *front=(*front)-1;
    }
    arr[*front] = num;
}

void insertrear(int *arr, int num, int *front, int *rear){
    if((*rear == max-1 && *front == 0) || (*rear+1 == *front-1)) {
        printf("DeQueue is full \n"); 
        return ; 
    }
    if(*front == -1){
        *front = *rear = 0;
    }
    else if(*rear == max-1)
        *rear = 0;
    else
        *rear = (*rear + 1);
    arr[*rear] = num;
}

int deletefront(int *arr, int *front, int *rear) {
    int data;
    if(*front == -1) {
        printf("The DeQueue is empty\n" );  
        return NULL;  
    }
    data = arr[*front];
    arr[*front] = 0;
    (*front)++;

    if(*front == *rear)
        *front = *rear = -1;
    else if(*front == max-1)
        *front = 0;
    else
        *front = (*front + 1);

    return data;
}

int deleterear(int *arr, int *front, int *rear) {
    int data;
    if(*front == -1){
        printf( "The DeQueue is empty.\n" ) ;    
        return NULL;  
    }
    data=arr[*rear];
    arr[*rear]=0;
    (*rear)--;

    if(*front==*rear)
        *front=*rear=-1;
    else if(*rear = 0)
        *rear=max-1;
    else
    (*rear)--;

    return data;
}

void display(int *arr, int front, int rear) {
    int i;
    for(i=0; i<=rear; i++) {
        printf("%d ", arr[i]);
    }
}

int main(){
    int arr[max], i, front=-1, rear=-1;
    for(i=0; i<max; i++){
        arr[i]=0;
    }
    insertfront(arr, 25, &front, &rear);
    insertfront(arr, 36, &front, &rear);
    insertrear(arr, 12, &front, &rear);
    insertrear(arr, 47, &front, &rear);

    printf("Displaying the elements of the DeQueue:\n");
    display(arr, front, rear);

    i = deletefront(arr, &front, &rear);
    printf("\nDeleted element from the front: %d", i);
    i = deleterear(arr, &front, &rear);
    printf("\nDeleted element from the rear: %d\n", i);

    printf("After deleting an element from both ends, the DeQueue looks like this:\n");
    display(arr, front, rear);

    return 0;
}