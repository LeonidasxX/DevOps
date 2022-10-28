

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char *name;
    int count;
    struct node *next;
} node;

node *Create();
void Search(node *);
void display(node *, int);
void free_list(node *);

int main(void)
{
    node *head = Create();

    printf("Input: ");
    display(head, 0);

    Search(head);

    printf("Output: ");
    display(head, 1);

    free_list(head);

    return 0;
}

node *Create()
{
    int n;
    char name[50];

    node *head, *temp;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        if (!head)
        {
            head = temp = (node *)malloc(sizeof(node));
        }
        else
        {
            temp->next = (node *)malloc(sizeof(node));
            temp = temp->next;
        }
        printf("Student %d:\n", i + 1);
        printf("\tName: ");
        scanf(" %[^\n]s", name);
        temp->name = (char *)calloc(strlen(name) + 1, sizeof(char));
        strcpy(temp->name, name);
        temp->count = 1;
    }
    temp->next = NULL;

    return head;
}

void Search(node *head)
{
    int count = 0;
    node *prev;
    node *curr;
    while (head != NULL)
    {
        prev = head;
        curr = head->next;
        while (curr != NULL)
        {
            if (strcmp(curr->name, head->name) == 0)
            {
                head->count++;
                curr = curr->next;
                free(prev->next);
                prev->next = curr;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        head = head->next;
    }
}

void display(node *list, int s)
{
    while (list != NULL)
    {
        printf("%s", list->name);
        if (s)
        {
            printf(", %d", list->count);
        }
        list = list->next;
        if (list != NULL)
        {
            printf("->");
        }
    }
    printf("\n");
}

void free_list(node *list)
{
    node *temp;
    while (list != NULL)
    {
        temp = list;
        list = list->next;
        free(temp->name);
        free(temp);
    }
}
