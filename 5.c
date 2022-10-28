#include <stdio.h>
#include <stdlib.h>
#include "ListFunctionsHeader.h"

void deleteNode(Node ** list, Node * rd) {
    if (*list == rd) {
        *list = (*list)->next;
        free(rd);
        return;
    }
    Node * temp = (Node *) malloc(sizeof(Node));
    temp = *list;
    while (1) {
        if (temp->next == rd) {
            temp->next = rd->next;
            break;
        }
        temp = temp->next;
    }
    free(rd);
}

void delOccurences(Node **list, int key) {
    Node * temp = (Node *) malloc(sizeof(Node));
    temp = *list;

    while(temp != NULL) {
        if (temp->val == key*key) {
            deleteNode(list,temp);
            temp = *list;
            continue;
        }
        temp = temp->next;
    }
}

int main() {
    int n,i,k,temp;
    printf("Enter length of list ");
    scanf("%d",&n);
    Node * node1 = (Node *) malloc(sizeof(Node));
    Node * node2 = (Node *) malloc(sizeof(Node));
    
    printf("Enter input for list\n");
    input(node1,n);
    printf("The list is: ");
    display(node1);
    printf("Enter k ");
    scanf("%d",&k);
    printf("List after deletion : ");
    delOccurences(&node1,k);
    display(node1);
}
