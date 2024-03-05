#include<stdio.h>
#define MAX 100
int arr[MAX];
int n;

// function to take  input from user and store it in an array.
void input(){
    int i;
    printf("\nEnter size of array : ");
    scanf("%d",&n);
    printf("Enter array elements : \n");
    for (i=0;i<n;i++){
        printf("element %d : ",i+1);
        scanf("%d",&arr[i]);
    }
}

// function to insert an element in an array at specific position.
int insert(){
    int i, pos, num;
    printf("\n\nInsert an element  at specific position in the array : \n");
    printf("\nEnter element to be added : ");
    scanf("%d",&num);
    printf("Enter position : ");
    scanf("%d",&pos);
    n++;
    for(i=n-1;i>=pos; i--){
            arr[i]=arr[i-1];

        }
        arr[i]=num;
    return 0;
}

// function to dissplay  the array after inserting or deleting an element.
void display(){
    int i;
    printf("\nYour array is : ");
    for(i=0;i<n;i++){
        printf("%d,\t",arr[i]);
    }
}

// function to delete an element from an array from specific position.
void del(){
    int i,pos;
    printf("\n\nDelete an  element from the array : \n");
    printf("\nEnter position from which element is to be deleted : ");
    scanf("%d",&pos);
    pos--;
    int temp=arr[pos];
     for(i=pos; i<n; i++){
            arr[i]=arr[i+1];
        }
        n--;
        printf("\nThe deleted element is : %d\n",temp);

}

// main function where  we call our functions and control the program flow.
int main(){

    input();
    display();
    insert();
    display();
    del();
    display();

return 0;
}
