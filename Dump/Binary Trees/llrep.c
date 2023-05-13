#include<stdio.h>
#include<malloc.h>

//structure for defining a binary tree
struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data){
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node)); //Asssigning memory in the heap
    n->data = data;
    n->left = NULL; //Setting the left addrress to NULL
    n->right = NULL; //Setting the rigth addrress to NULL
}

void preOrder(struct node *root){
    if(root!=NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}


struct node *Inorder(struct node *root){
    struct node *s[40]; //declarting the stack
    int top = -1;

    if(root==NULL){
        return ;
    }


    top++;
    s[top] = root;


    while(top!=-1){

        if(root->right!=NULL){
            top = top+1; //top = 0
            stack[top] = root->right;
        }

        root = stack[top];
        top = top-1; //top = -1
        printf("%d", root->info);

        if(root->left!=NULL){
            top = top+1; //top = 1
            stack[top] = root->left;
        }
    }



}
void postOrder(struct  node *root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(struct node *root){
    if(root!=NULL){
        inOrder(root->left);

        printf("%d ", root->data);
        inOrder(root->right);
    }
}
int main(){
    struct node *p = createNode(2);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(4);


    p->left = p1;
    p->right = p2;

    preOrder(p);

    printf("\nPost order traversal of BT \n");

    postOrder(p);


    printf("\n Inorder traversal of BT\n");
    
    inOrder(p);

}