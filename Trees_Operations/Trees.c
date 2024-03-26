#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

// creating nodes of a binary tree
struct node* createnode(int data){
    struct node* n;
    n = (struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

// Preorder traversal in binary tree (root -> left node -> right node)
void preOrder(struct node* root){
    if (root != NULL){
        printf("%d  ",root->data);
        preOrder(root->left);
        preOrder(root->right);

    }
}

// Postorder traversal in binary tree (left node -> right node -> root)
void postOrder(struct node* root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d  ",root->data);
    }
}

// Inorder traversal in binary tree (left node -> root -> right node)
void inOrder(struct node*root){
    if(root != NULL){
        inOrder(root->left);
        printf("%d  ",root->data);
        inOrder(root->right);
    }
}
/*  This is our binary tree.
            5
           / \
         15   25
        / \    \
      35  45    65
     /
   55
*/

int main(){
    // Placing root data into respective nodes
    struct node* p = createnode(5);
    struct node* p1 = createnode(15);
    struct node* p2 = createnode(25);
    struct node* p3 = createnode(35);
    struct node* p4 = createnode(45);
    struct node* p5 = createnode(55);
    struct node* p6 = createnode(65);

    // Linking parent node with respective child node
    p->left =p1;
    p->right=p2;
    p1->left =p3;
    p1->right=p4;
    p2->right=p6;
    p3->left =p5;
    
    printf("Preorder display of tree elements : ");
    preOrder(p);
    printf("\n");
    printf("Postorder display of tree elements : ");
    postOrder(p);
    printf("\n");
    printf("Inorder display of tree elements : ");
    inOrder(p);

    return 0;
}