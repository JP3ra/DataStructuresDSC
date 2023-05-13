#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};


void traverseCircular(struct node *head){
    struct node *temp = head;

    do{
        printf("%d ", temp->data);
        temp = temp->next;
    }
    while(temp!=head);
}

struct node *insertFront(struct node *head,int item){
    struct node *p;
    p = (struct node*)malloc(sizeof(struct node));
    p->data = item;
    p->next = NULL;

    if(head==NULL){
        head = p;
        p->next = head;
    }
    else{
        struct node *end = head;
        while(end->next!=head){
            end = end->next;
        }

        p->next = head;
        head = p;
        end->next = head;
    }

    return head;

}

struct node *deleteFront(struct node *head){
    if(head==NULL){
        printf("NO");
        return head;
    }
    else{  
        struct node *end = head;
        while(end->next!=head){
            end = end->next;
        }
        struct node *temp = head;
        head = head->next;
        end->next = head;
        free(temp);

    }

    return head;
}


struct node *deleteBack(struct node *head){
    if(head==NULL){
        printf("NO");
        return head;
    }
    else{
        struct node *prePtr = NULL;
        struct node *ptr = head;
        while(ptr->next!=head){
            prePtr = ptr;
            ptr = ptr->next;
        }

        prePtr->next = head;
        free(ptr);

    }

    return head;
}
struct node *insertBack(struct node *head, int item){
    struct node *p;
    p = (struct node*)malloc(sizeof(struct node));
    p->data = item;
    p->next = NULL;

    if(head==NULL){
        head = p;
        p->next = head;
    }

    else{
        struct node *end = head;
        while(end->next!=head){
            end = end->next;
        }

        end->next = p;
        p->next = head;
    }

    return head;
}
int main(){
    struct node *head = NULL;

    struct node *first;
    first = (struct node*)malloc(sizeof(struct node));
    first->data = 10;
    first->next = NULL;

    struct node *second;
    second = (struct node*)malloc(sizeof(struct node));
    second->data = 20;
    second->next = NULL;

    struct node *third;
    third = (struct node*)malloc(sizeof(struct node));
    third->data = 30;
    third->next = NULL;

    // 10 20 30 10

    head = first;
    first->next = second;
    second->next = third;
    third->next = head;


    traverseCircular(head);

    printf("\n");

    head = insertFront(head, 100);
    head = insertFront(head, 200);
    head = insertBack(head, 600);
    head = insertBack(head, 700);

    traverseCircular(head);

    head = deleteFront(head);
    head = deleteBack(head);
    printf("\n");
    traverseCircular(head);


}