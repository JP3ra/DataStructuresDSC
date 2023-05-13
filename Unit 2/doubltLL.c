#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node{
    int info;
    struct node *next;
    struct node *prev;
};

struct node *insertFront(struct node *head, int item){
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->info = item;
    p->next = NULL;
    p->prev = NULL;

    if(head==NULL){
        head = p;
    }
    else{

        p->next = head;
        head->prev = p;
        head = p;
    }


    return head;

}

struct node *insertRear(struct node *head, int item){

    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->info = item;
    p->next = NULL;
    p->prev = NULL;


    if(head==NULL){
        head = p;
    }
    else{
        struct node *temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }

        temp->next = p;
        p->prev= temp;
    }

    return head;
}

struct node *insertAfter(struct node *head, int key, int item){
    if(head==NULL){
        printf("The lsit is empty\n");
        return head;
    }

    struct node *p;
    p = (struct node*)malloc(sizeof(struct node));
    p->info = item;
    p->next = NULL;
    p->prev = NULL;

    if(head->info == key){
        p->prev = head;
        head->next = p;
        head = p;
    }

    else{
        struct node *temp = head;
        while(temp!=NULL && temp->info!=key){
            temp = temp->next;
        }

        if(temp==NULL){
            printf("cant insert");
            return head;
        }
        else{
            p->next = temp->next;
            temp->next->prev = p;
            p->prev = temp;
            temp->next = p;
        }

    }

    return head;
    
}

struct node *insertBefore(struct node *head, int key, int item){
    if(head==NULL){
        printf("The lsit is empty\n");
        return head;
    }

    struct node *p;
    p = (struct node*)malloc(sizeof(struct node));
    p->info = item;
    p->next = NULL;
    p->prev = NULL;

    if(head->info == key){
        head->prev = p;
        p->next = head;
        head = p;
    }
    else{
        struct node *temp = head;
        while(temp!=NULL && temp->info!=key){
            temp = temp->next;
        }

        if(temp==NULL){
            printf("cant insert");
            return head;
        }
        else{
            temp->prev->next = p;
            p->prev = temp->prev;
            p->next = temp;
            temp->prev = p;
        }
    }

    return head;
}

struct node *deleteFront(struct node *head){
    if(head==NULL){
        printf("cant ");
        return head;
    }
    else{
        struct node *temp = head;
        head = head->next;
        head->next->prev = NULL;
        free(temp);
    }

    return head;
}

struct node *deleteRear(struct node *head){
    if(head==NULL){
        printf("cant");
        return head;
    }
    else{
        struct node *temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }

        struct node *p = temp;
        temp->prev->next = NULL;
        temp->prev = NULL;
        free(temp);

    }

    return head;
}

struct node *deleteAfter(struct node *head, int key){
    struct node *temp = head;

    while(temp!=NULL && temp->info!=key){
        temp = temp->next;
    }

    if(temp==NULL){
        printf("cant");
        return head;

    }
    else{
        struct node *ptr = temp->next;
        ptr->prev = NULL;
        ptr->next = NULL;
        temp->next->next 
    }
}

void display(struct node *head){
    struct node *temp = head;
    while(temp!=NULL){
        printf("%d\t", temp->info);
        temp = temp->next;
    }
}

int main(){
    struct node *head;
    head = NULL;
    head = insertFront(head, 10);
    head = insertFront(head, 20);
    head = insertFront(head, 30);

    head = insertRear(head, 45);
    head = insertRear(head, 60);



    head = insertAfter(head, 20, 100);


    head = insertBefore(head, 60, 200);
    display(head);

    head = deleteFront(head);
    head = deleteRear(head);
    display(head);
}