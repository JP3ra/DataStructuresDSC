#include<stdio.h>
#include<malloc.h>
#include<conio.h>


struct node{
    int data;
    struct node *next;
};

struct node *createNode(int data){
    struct node *p;
    p = (struct node*)malloc(sizeof(struct node));
    p->data = data;
    p->next = NULL;
}

//traversing    
void traverseLinked(struct node *head){
    struct node *temp = head;

    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}


//insert front

struct node *insertFront(struct node *head, int data){
    //if the linkedList if empty

    if(head==NULL){
        printf("The linked list is empty\n");

    }
    else{
        struct node *sample = createNode(data);
        sample->next = head;
        head = sample;
    }

    return head;
}

//inserting at last

struct node *insertEnd(struct node *head, int data){
    if(head==NULL){
        printf("The linked list is empty \n");
        return head;
    }
    //if there is only one element

    struct node *sample = createNode(data);

    if(head->next == NULL){
        head->next = sample;
    }
    else{
        struct node *temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }

        temp->next = sample;
    }

    return head;
}

//inserting before a given node

struct node *insertBefore(struct node *head, int key, int data){
    if(head==NULL){
        printf("the linked list is empty \n");
    }
}
int main(){
    struct node *c1 = createNode(5);
    struct node *c2 = createNode(6);
    struct node *c3 = createNode(7);

    c1->next = c2;
    c2->next = c3;

    c1 = insertFront(c1, 8);

    c1 = insertEnd(c1, 10);

    traverseLinked(c1);
}