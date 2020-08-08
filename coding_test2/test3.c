#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int value;
    struct node *next;
} Node;
void menu();
Node* create_list_1();
Node* create_list_2();
Node* insert_front(Node *temp, int key);
Node* delete_back(Node *temp);
int search(Node *temp, int key);
Node* print_reverse(Node *list);
Node* copy_list_recursive(Node *copy);
void print_list(Node *temp);
int main()
{
    menu();
    return 0;
}
void menu()
{
    Node *head1 = NULL;
    Node *list1 = NULL;
    head1 = create_list_1();
    int value, option;
    do
    {
        system("cls");
        printf("1. Insert Front\n");
        printf("2. Delete Back\n");
        printf("3. Search\n");
        printf("4. Reverse\n");
        printf("5. Copy\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your Option : ");
        scanf("%d", &option);
        if(option == 1)
        {
            int x, y;
            head1 = create_list_1();
            printf("Display List 1: ");
            print_list(head1);
            printf("Enter Value: ");
            scanf("%d", &x);
            head1 = insert_front(head1, x);
            printf("After Front Insert: ");
            print_list(head1);
            getchar();
            printf("\nPress Enter to Continue\n");
            getchar();
        }
        else if(option == 2)
        {
            printf("Display List 1: ");
            print_list(head1);
            head1 = delete_back(head1);
            printf("After Front Delete from List 1: ");
            print_list(head1);
            getchar();
            printf("\nPress Enter to Continue\n");
            getchar();
        }
        else if (option == 3)
        {
            int key;
            scanf("%d",&key);
            head1 = create_list_1();
            print_list(head1);
            search(head1,key);

            printf("\n");
            getchar();
            printf("\nPress Enter to Continue\n");
            getchar();
        }
        else if(option == 4)
        {
            printf("Display List 1: ");
            print_list(head1);
            head1 = print_reverse(head1);
            printf("Display List 1 in Reverse: ");
            print_list(head1);
            getchar();
            printf("\nPress Enter to Continue\n");
            getchar();
        }
        else if(option == 5)
        {
            printf("Display List 1: ");
            print_list(head1);
            list1 = copy_list_recursive(head1);
            printf("After Copy Recursively from List 1: ");
            print_list(list1);
            getchar();
            printf("\nPress Enter to Continue\n");
            getchar();
        }
        else if(option == 6)
        {
            printf("Display List 1: ");
            print_list(head1);
            getchar();
            printf("\nPress Enter to Continue\n");
            getchar();
        }
        else if (option == 7)
        {
            exit(0);
        }
        else
        {
            printf("\nInvalid Option, Please Option Between '1 to 7'");
            getchar();
            printf("\nPress Enter to Continue\n");
            getchar();
        }
    }
    while(option != 7);
}
Node* create_list_1()
{
    Node *a, *b, *c, *d;
    a = (Node *) malloc(sizeof(Node));
    b = (Node *) malloc(sizeof(Node));
    c = (Node *) malloc(sizeof(Node));
    d = (Node *) malloc(sizeof(Node));
    a->value = 10;
    a->next = b;
    b->value = 20;
    b->next = c;
    c->value = 30;
    c->next = d;
    d->value = 40;
    d->next = NULL;
    return a;
}
Node* insert_front(Node *temp, int key)
{
    Node *new_head;
    new_head = (Node*) malloc(sizeof(Node) );
    new_head->value = key;
    new_head->next = temp;
    return new_head;
}
Node* delete_back(Node *temp)
{
    Node *head = temp, *last;
    if(temp)
    {
        if (head->next!=NULL)
        {
            while(temp->next)
            {
                last = temp;
                temp = temp->next;
            }
            free(temp);
            last->next = NULL;
        }
        else
        {
            free(temp) ;
            head = NULL;
        }
        return head;
    }
    else
        printf("Underflow Linked List");
    return head;
}
int search(Node *temp, int key)
{
    if(temp)
    {
        while(temp)
        {
            if(key == temp->value)
            {
                printf("%d: Found",key);
            }
            temp = temp->next;
        }
        printf("%d: Not Found",key);
    }
    return 0;
}
Node* print_reverse(Node *list)
{
    Node *first, *current, *temp;
    first = list;
    current = list->next;
    first->next = NULL;
    while(current)
    {
        temp = current->next;
        current->next = first;
        first = current;
        current = temp;
    }
    return first;
}
Node* copy_list_recursive(Node *copy)
{
    if(copy == NULL)
        return NULL;
    Node *temp = (Node*) malloc(sizeof (Node));
    temp->value = copy->value;
    temp->next = copy_list_recursive(copy->next) ;
    return temp;
}
void print_list(Node *temp)
{
    while(temp!=NULL)
    {
        printf("%d ",temp->value);
        temp = temp->next;
    }
    printf("\n");
}
