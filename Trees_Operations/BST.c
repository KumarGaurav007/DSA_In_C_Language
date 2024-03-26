#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

// Function to create nodes of BST
struct node* createnode(int data){
    struct  node *root;
    root=(struct node*)malloc(sizeof(struct node));
    root->data=data;
    root->left=NULL;
    root->right=NULL;
    return root;
}

// Function for in order traversal of BST
void inOrderDisplay(struct node*root){
    if(root != NULL){
        inOrderDisplay(root->left);
        printf("%d  ",root->data);
        inOrderDisplay(root->right);
    }
}

// Function to check whether given binary tree is BST or not.
int isBST(struct node*root){
    static struct node*prev = NULL;
    if(root != NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev != NULL && root->data <= prev->data){
            return 0;
        }
        prev=root;
        return isBST(root->right);
    }
    else{
        return 1;
    }
}

// searching an element in a BST
struct node *search(struct node*root, int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }
    else if(root->data > key){
        search(root->left, key);
    }
    else{
        search(root->right, key);
    }
    
}

int main(){
    // Inserting  values in respective nodes
    struct node*r = createnode(9);
    struct node*r1 = createnode(4);
    struct node*r2 = createnode(11);
    struct node*r3 = createnode(2);
    struct node*r4 = createnode(7);
    struct node*r5 = createnode(5);
    struct node*r6 = createnode(8);
    struct node*r7 = createnode(15);
    struct node*r8 = createnode(14);

    // Linking nodes with their respective child node
    r->left=r1;
    r->right=r2;
    r1->left=r3;
    r1->right=r4;
    r2->right=r7;
    r4->left=r5;
    r4->right=r6;
    r7->left=r8;

    // Function call to check tree is BST
    if(isBST(r)==1){
        printf("This is a BST");
    }else{
        printf("This is not a BST");
    }

    // Function calling to display elements of BST 
    printf("\nElements in BST : ");
    inOrderDisplay(r);
    printf("\n");

    // Function call for searchig element in BST
    struct node* i =  search(r, 7);
    if(i != NULL){
        printf("\nElement %d found in this BST.",i->data);

    }
    else{
        printf("\nElement %d is  not found in this BST.");
    }

    return 0;
}