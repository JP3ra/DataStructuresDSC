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

// Searching for an element 
int searchEle(struct node *head, int key){
    if(head==NULL){
        printf("The linked lsit is empty\n");
        return 0;
    }
    else{
        struct node *temp = head;
        while(temp!=NULL){
            if(temp->data == key){
                return 1;
            }
        }
        return 0;
    }
}

// Inserting front
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

// Insert at rear end
struct node *insertEnd(struct node *head, int item){
    struct node *p;
    p = (struct node*)malloc(sizeof(struct node));
    p->data = item;
    p->next = NULL;

    if(head==NULL){
        head = p;
    }
    else{
        struct node *temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }

        temp->next = p;
    }

    return head;
}

// Inserting after a given element 

struct node *insertAfter(struct node *head, int item, int key){
    struct node *p;
    p = (struct node*)malloc(sizeof(struct node));
    p->data = item;
    p->next = NULL;

    if(head == NULL){
        printf("The linked list is empty \n");
        return head;
    }

    if(head->data == key){
        p->next = head->next;
        head->next = p;
        return head;
    }
    else{
        struct node *temp = head;
        while(temp!=NULL && temp->data !=key){
            temp = temp->next;
        }

        if(temp==NULL){
            printf("Couldnt find the key");
        }
        else{
            p->next = temp->next;
            temp->next = p;
            return head;
        }
    }

}

// Inserting before a given element
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


// Deleting the first element

struct node *deleteFront(struct node *head){
    if(head==NULL){
        printf("The linked list is empty \n");
        return head;
    }

    else{
        struct node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

}

// Deleting the last element 

struct node *deleteRear(struct node *head){
    if(head==NULL){
        printf("The linked lsit is empty\n");
        return head;
    }
    else{
        struct node *temp = head;
        struct node *preTemp;

        while(temp->next!=NULL){
            preTemp = temp;
            temp = temp->next;
        }

        preTemp->next = NULL;
        free(temp);

        return head;
    }
}
int main(){
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = 10;
    p->next = NULL;

    struct node *q;
    q = (struct node *)malloc(sizeof(struct node ));
    q->data = 20;
    q->next = NULL;

    p->next = q;

    traversal(p);

    p = insertFront(p, 40);
    p = insertFront(p, 100);
    printf("After inserting front \n\n");

    traversal(p);

    p = insertEnd(p, 5);
    p = insertEnd(p, 15);
    printf("After inserting end \n\n");
    traversal(p);

    p = insertAfter(p, 150, 100);

    traversal(p);

    p = insertBefore(p, 69, 10);
    traversal(p);

    p = deleteFront(p);
    traversal(p);

    p = deleteRear(p);
    traversal(p);

}