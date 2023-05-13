int count_occurence(struct node *start, int key){
    int count = 0;
    struct node *temp;
    if(start==NULL){
        printf("The list is empty\n");
        count = 0;
    }
    else{
        temp = start;
        while(temp!=NULL){
            if(temp->info == key){
                
                count++;
                
            }
            temp = temp->next;
        }
    }
    return count;
}