#include<stdio.h>
#include<conio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node *next;
};

void traversal(struct node *head){
    if(head==NULL){
        printf("The linked list is empty \n");
    }
    else{
        struct node *temp = head;
        while(temp!=NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");


    }
}

struct node *insertFront(struct node *head, int info){
    struct node *p;
    p = (struct node*)malloc(sizeof(struct node));
    p->data = info;
    p->next = NULL;


    if(head==NULL){
        head = p;
    }
    else{
        p->next = head;
        head = p;
        
    }

    return head;

}

struct node *insertBefore(struct node *head, int item, int key){
    if(head==NULL){
        printf("The linked list is empty");
        return head;
    }

    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = item;
    p->next = NULL;

    if(head->data == item){
        p->next = head;
        head = p;
        return head;
    }
    else{
        struct node *preptr = head;
        struct node *ptr = head;

        while(ptr!=NULL && ptr->data !=key){
            preptr = ptr;
            ptr = ptr->next;
        }

        preptr->next = p;
        p->next = ptr;
        return head;
    }

}

struct node *insertSorted(struct node *head, int item){
    struct node *temp;
    temp = (struct node *)sizeof(struct node);
    temp->data = item;
    temp->next = NULL;

    // Linked list is empty
    if(head==NULL){
        head = temp;
        return head;
    }

    if(head->data > item){
        temp->next = head;
        head = temp;
        return head;
    }
    else{
        
        struct node *p = head;

        while(p->next->data < item && p->next!=NULL){
            temp = temp->next;
        }

        temp->next = p->next;
        p->next = temp;
        return head;    
    }
    
}

int main(){
    struct node *head = NULL;
    head = (struct node*)sizeof(struct node);
    head = insertFront(head, 10);
    head = insertFront(head, 20);
    head = insertFront(head, 30);
    head = insertFront(head, 40);
    head = insertFront(head, 50);

    // Have to insert 35



    traversal(head);

    head = insertSorted(head, 45);
    traversal(head);
}