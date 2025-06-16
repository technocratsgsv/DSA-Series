#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev; // Added previous pointer for doubly linked list
};

// Function to create a new node
struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to create a doubly linked list with 'n' nodes
struct node *createLinkedList(int n)
{
    struct node *head = NULL;
    struct node *temp = NULL;
    struct node *prev = NULL;

    for (int i = 1; i <= n; i++)
    {
        int data;
        printf("Enter the data of node %d: ", i);
        scanf("%d", &data);

        temp = createNode(data);
        if (head == NULL)
        {
            head = temp; // Set the head to the first node
        }
        else
        {
            prev->next = temp; // Link previous node to current node
            temp->prev = prev; // Link current node to previous node (for doubly linked list)
        }
        prev = temp; // Move prev to the current node
    }
    return head;
}

// Function to print the doubly linked list
void printLinkedList(struct node *head)
{
    struct node *temp = head;
    printf("The linked list is: ");
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to insert at the beginning
struct node *insertAtBeg(struct node *head, int data)
{
    struct node *new_node = createNode(data);
    if (head == NULL)
    {
        return new_node;
    }
    new_node->next = head;
    head->prev = new_node; // Set the previous pointer of the old head
    head = new_node;
    return head;
}

// Function to insert a node before a node with value 'num'
struct node *insertAtBeforeNode(struct node *head, int value, int num)
{
    struct node *new_node = createNode(value);
    if (head == NULL)
    {
        return new_node;
    }

    struct node *temp = head;

    // If inserting before the head node
    if (head->data == num)
    {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
        return head;
    }

    while (temp != NULL && temp->data != num)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("The number %d is not present in the list.\n", num);
        free(new_node);
        return head;
    }

    new_node->next = temp;
    new_node->prev = temp->prev;
    if (temp->prev != NULL)
    {
        temp->prev->next = new_node;
    }
    temp->prev = new_node;

    return head;
}

// Function to insert a node after a node with value 'num'
struct node *insertAtAfterNode(struct node *head, int value, int num)
{
    struct node *new_node = createNode(value);
    if (head == NULL)
    {
        return new_node;
    }

    struct node *temp = head;
    while (temp != NULL && temp->data != num)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("The number %d is not present in the list.\n", num);
        free(new_node);
        return head;
    }

    new_node->next = temp->next;
    new_node->prev = temp;
    if (temp->next != NULL)
    {
        temp->next->prev = new_node;
    }
    temp->next = new_node;

    return head;
}

// Function to insert at the end of the doubly linked list
struct node *insertAtEnd(struct node *head, int data){
    struct node *new_node = createNode(data);
    if (head == NULL)
    {
        return new_node;
    }

    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new_node;
    new_node->prev = temp;

    return head;
}

struct node *DeletionAtBeginning(struct node *head){
    struct node *ptr = head;
    if (head == NULL)
    {
        printf("Underflow..\n");
        return NULL;
    }
    head = head->next;
    head->prev = NULL;
    free(ptr);
    return head;
}

struct node *DeletionAfterNode(struct node *head, int num){
    struct node *ptr = head;
    if (head == NULL)
    {
        printf("Underflow");
        return NULL;
    }
    while (ptr->data != num)
    {
        ptr = ptr->next;
    }
    struct node *temp = ptr->next;
    ptr->next = temp->next;
    temp->next->prev = ptr;
    free(temp);
    return head;
}

struct node *DeletionBeforeNode(struct node *head, int num){
    struct node* ptr = head;
    if(head==NULL){
        printf("Underflow");
        return NULL;
    }
    while(ptr->data!=num){
        ptr=ptr->next;
    }
    struct node* temp=ptr->prev;
    temp->prev->next = ptr;
    ptr->prev = temp->prev;
    free(temp);
    return head;
}

struct node *DeletionAtEnd(struct node* head){
    struct node* ptr = head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->prev->next=NULL;
    free(ptr);
    return head;

}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    struct node *head = createLinkedList(n);
    printLinkedList(head);
    
    int choice1;
    do {
        printf("What do you want with the node:\n1. Insertion\n2. Deletion\n3. Exit\n");
        scanf("%d", &choice1);
        switch (choice1) {
        case 1: {
            int choice;
            printf("\n1. At the Beginning\n2. Before a Node\n3. After a Node\n4. At the End\n");
            printf("Where do you want to insert? ");
            scanf("%d", &choice);

            switch (choice) {
            case 1: {
                int value;
                printf("Enter the data to add at the beginning: ");
                scanf("%d", &value);
                head = insertAtBeg(head, value);
                printLinkedList(head);
                break;
            }
            case 2: {
                int number, value;
                printf("Enter the number before which to insert the new node: ");
                scanf("%d", &number);
                printf("Enter the data of the new node: ");
                scanf("%d", &value);
                head = insertAtBeforeNode(head, value, number);
                printLinkedList(head);
                break;
            }
            case 3: {
                int number, value;
                printf("Enter the number after which to insert the new node: ");
                scanf("%d", &number);
                printf("Enter the data of the new node: ");
                scanf("%d", &value);
                head = insertAtAfterNode(head, value, number);
                printLinkedList(head);
                break;
            }
            case 4: {
                int value;
                printf("Enter the data to add at the end: ");
                scanf("%d", &value);
                head = insertAtEnd(head, value);
                printLinkedList(head);
                break;
            }
            default:
                printf("Invalid entry! Try again.\n");
            }
            break;
        }

        case 2: {
            int choice2;
            printf("\n1. Deletion at Beginning\n2. Deletion after Node\n3. Deletion Before Node\n4. Deletion at End\n");
            printf("Enter the choice: ");
            scanf("%d", &choice2);
            switch (choice2) {
            case 1:
                head = DeletionAtBeginning(head);
                printLinkedList(head);
                break;
            case 2: {
                int num;
                printf("Enter the number after you want to delete: ");
                scanf("%d", &num);
                head = DeletionAfterNode(head, num);
                printLinkedList(head);
                break;
            }
            case 3: {
                int num;
                printf("Enter the number Before you want to delete: ");
                scanf("%d", &num);
                head = DeletionBeforeNode(head, num);
                printLinkedList(head);
                break;
            }

            case 4:{
                head = DeletionAtEnd(head);
                printLinkedList(head);
                break;

            }
            default:
                printf("Invalid entry! Try again.\n");
            }
            break;
        }

        case 3:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid entry! Try again.\n");
        }
    } while (choice1 != 3);

    return 0;
}