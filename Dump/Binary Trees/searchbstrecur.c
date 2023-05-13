#include<stdio.h>
#include<malloc.h>

//create node

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data){
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->right = NULL;
    p->left = NULL;
}

struct node *search(struct node *root, int key){
    //if its an empty bst
    if(root==NULL){
        return NULL;
    }
    if(root->data == key){
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

    //      9
    //     / \
    //    5   11
    //   / \  
    //  4   8

    struct node *p1 = createNode(9);
    struct node *p2 = createNode(5);

    struct node *p3 = createNode(4);
    struct node *p4 = createNode(8);
    struct node *p5 = createNode(11);

    p1->left = p2;
    p1->right = p5;
    p2->left = p3;
    p2->right = p4;

    if(search(p1, 8) == NULL){
        printf("Element not found");
    }
    else{
        printf("Element found");
    }

 
   return 0;
}