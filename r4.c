#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char* name;
    int roll;
    int marks;
    struct Node* next;
};

void sort(struct Node** head) {
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

void display(struct Node* list) {
    while(list != NULL) {
        printf("{%s, %d, %d}", list->name, list->roll, list->marks);
        list = list->next;
        if(list != NULL) {
            printf("  ->  ");
        }
    }
    printf("\n");
}

struct Node* second_highest(struct Node* head) {
    return head->next;
}

int main(int argc, char const *argv[])
{
    int n;
    char name[20];
    struct Node *head;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        if(!head) {
            head = (struct Node*) malloc(sizeof(struct Node));
        }
        else {
            head->next = (struct Node*) malloc(sizeof(struct Node));
            head = head->next;
        }
        printf("Student %d:\n", i+1);
        printf("\tName: ");
        scanf(" %s", name);
        head->name = (char*) calloc(strlen(name) + 1, sizeof(char));
        strcpy(head->name, name);
        printf("\tRoll No: ");
        scanf("%d", &head->roll);
        printf("\tMarks: ");
        scanf("%d", &head->marks);
    }
    head->next = NULL;

    printf("Before Sorting: ");
    display(head);

    sort(&head);

    printf("After Sorting: ");
    display(head);

    struct Node* second = second_highest(head);

    if(second) {
        printf("Second Highest: %s, %d, %d\n", second->name, second->roll, second->marks);
    }
    else {
        printf("Not enought nodes present in the list...\n");
    }

    return 0;
}
