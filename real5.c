#include<stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node* next;
};

void linkedListTraversal(struct Node* ptr){
    while(ptr != NULL){
        printf("%d", ptr->data);
        ptr = ptr->next;
        if (ptr != NULL)
        {
            printf(" -> ");
        }
    }
    printf("\n");
}

void insertNode(struct Node* head, int data)
{
    struct Node* temp = head;
    struct Node* ptr = (struct Node*) malloc (sizeof(struct Node));
    ptr->data = data;
    while(temp->next != NULL){
            temp = temp->next;
        }
    temp->next = ptr;
    ptr->next = NULL; 
}

void deleteValue(struct Node* head, int value){
    struct Node* p = head;
    struct Node* q = head->next;
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    
}
       
int main(int argc, char const *argv[])
{
    struct Node* head = NULL, *temp;
    int n, value, k;
    printf("Enter the size of Linked List: ");
    scanf("%d", &n);

    printf("Enter List:\n");
    for (int i = 0; i < n; i++)
    {
        if(head == NULL){
            head = temp = (struct Node*) malloc (sizeof(struct Node));
            scanf("%d", &temp->data);
            temp->next == NULL;
        }
        else{
            scanf("%d", &value);
            insertNode(head, value);
        }
        
    }
    
    printf("Original List: ");
    linkedListTraversal(head);

    printf("Enter k: ");
    scanf("%d", &k);

    printf("After deletion: ");
    deleteValue(head, k*k);
    linkedListTraversal(head);
    return 0;
}
