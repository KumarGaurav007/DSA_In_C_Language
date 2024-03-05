// code for searching an element linearly.
#include<stdio.h>
int main(){
    int arr[10]={56,89,45,82,34,96,14,70,61};
    int target=14;
    int position=-1;
    //traversing elements index by index.
    for(int i=0; i<10; i++){
        if (arr[i]==target){  //checking for target element. 
            position=i;
            break;
        }
    }
    if (position!=-1){
        printf("%d found on %d position",target,position+1); 
    }
    else{
        printf("%d not found",target);
    }
    return 0;
}
