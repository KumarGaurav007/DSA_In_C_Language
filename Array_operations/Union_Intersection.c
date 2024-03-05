// This code will give required output only when both the arrays are sorted .

#include <stdio.h>
#define MAX 50
int arr1[MAX];
int arr2[MAX];
int m; //size of arr1
int n; //size of arr2

// Function to find union of two arrays.
void Union(int arr1[], int arr2[], int m, int n) {
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (arr1[i] < arr2[j]) {
            printf("%d ", arr1[i++]);
        } else if (arr2[j] < arr1[i]) {
            printf("%d ", arr2[j++]);
        } else {
            printf("%d ", arr2[j++]);
            i++;
        }
    }

    while (i < m)
        printf("%d ", arr1[i++]);
    while (j < n)
        printf("%d ", arr2[j++]);
}

//Function to find intersection of two arrays.
void Intersection(int arr1[], int arr2[], int m, int n) {
    int i = 0, j = 0;
    while (i < m && j < n) {
        if (arr1[i] < arr2[j])
            i++;
        else if (arr2[j] < arr1[i])
            j++;
        else {
            printf("%d ", arr2[j++]);
            i++;
        }
    }
}

int main() {
    int i;
    printf("NOTE :- Enter array elements  in ascending order.\n");
    //Input array elements  for first array.
    printf("\nEnter  the size of first array: ");
    scanf("%d", &m);
    printf("\nEnter elements of first array:\n");
    for (i=0; i<m; i++){
        printf("Element %d : ", i+1);
        scanf("%d", &arr1[i]);

    }

    //Input array elemets  for second array.
    printf("\nEnter  the size of second array: ");
    scanf("%d", &n);
    printf("\nEnter elements of second array:\n");
    for (i=0; i<n; i++){
        printf("Element %d : ", i+1);
        scanf("%d", &arr2[i]);

    }

    //Display elements of first array.
    printf("\nArray  1 is : ");
    for(i=0; i<m; i++){
        printf("%d, ", arr1[i]);
    }

    //Display elements of second array.
    printf("\nArray  2 is : ");
    for(i=0; i<n; i++){
        printf("%d, ", arr2[i]);
    }
    
    //Display union of two array.
    printf("\n\nUnion of two arrays is: ");
    Union(arr1, arr2, m, n);
    printf("\n");

    //Display intersection of two array.
    printf("\nIntersection of two arrays is: ");
    Intersection(arr1, arr2, m, n);
    printf("\n");

    return 0;
}
