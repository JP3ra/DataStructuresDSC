
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

void insert(struct node *root, int key){
    struct node *prev;

    while(root!=NULL){
        prev = root;
        if(root->data == key){
            return;
        }
        else if(root->data > key){
            root = root->left;
        }
        else{
            root = root->right;
        }

        
    }

    struct node *new = createNode(key);

    if(key < prev->data){
        prev->left = new;
    }
    else{
        prev->right = new;
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

    insert(p1, 7);

     printf("%d lul", p1->left->right->left->data);
 
   return 0;
}