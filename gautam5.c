#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    char* name;
    int roll;
    int marks;
    struct Node* next;
};

void sort(struct Node** head){
    struct Node *large = NULL, *curr = NULL, *pivot = NULL, *prev_piv = NULL;
    struct Node *prev_large = NULL, *prev = NULL;
    pivot = *head;
    while(pivot != NULL) {
        prev_large = pivot;
        large = pivot;
        prev = pivot;
        curr = pivot->next;
        while(curr != NULL) {
            if(large->marks < curr->marks) {
                prev_large = prev;
                large = curr;
            }
            prev =  curr;
            curr = curr->next;
        }

        if(pivot != large) {
            prev_large->next = large->next;
            large->next = pivot;
            if(pivot == *head) {
                *head = large;
            }
            else {
                prev_piv->next = large;
            }
            prev_piv = large;
        }
        else {
            prev_piv = pivot;
            pivot = pivot->next;
        }
    }
}

void linkedArrayTraversal(struct Node* ptr){
    while(ptr != NULL){
        printf("\t%s, %d, %d\t", ptr->name, ptr->roll, ptr->marks);
        ptr = ptr->next;
        if (ptr != NULL)
        {
            printf(" -> ");
        }
    }
    printf("\n");
}

struct Node* secondHigh(struct Node* ptr){
    return ptr->next;
}

int main(int argc, char const *argv[])
{
    int n;
    char name[20];
    struct Node *head = NULL, *temp;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        if (!head)
        {
            head = temp = (struct Node*) malloc (sizeof(struct Node));
        }
        else{
            temp->next = (struct Node*) malloc (sizeof(struct Node));
            temp = temp->next;
        }
        printf("Student %d:\n", i+1);
        printf("Name: ");
        scanf(" %s", name);
        temp->name = (char*) calloc(strlen(name) + 1, sizeof(char));
        strcpy(temp->name, name);
        printf("Roll No: ");
        scanf("%d", &temp->roll);
        printf("Marks: ");
        scanf("%d", &temp->marks);  
    }
    temp->next = NULL;
    
    printf("Before Sorting: ");
    linkedArrayTraversal(head);

    sort(&head);

    printf("After Sorting: ");
    linkedArrayTraversal(head);

    struct Node* second = secondHigh(head);
    
    if (second)
    {
        printf("Second Highest: %s, %d, %d\n", second->name, second->roll, second->marks);
    }
    else{
        printf("Less nodes present...");
    }

    return 0;
}
