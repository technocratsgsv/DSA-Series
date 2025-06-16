#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Function to create a new node
struct node *createNode(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a linked list with 'n' nodes
struct node *createLinkedList(int n) {
    struct node *head = NULL;
    struct node *temp = NULL;
    struct node *prev = NULL;

    for (int i = 1; i <= n; i++) {
        int data;
        printf("Enter the data of node %d: ", i);
        scanf("%d", &data);

        temp = createNode(data);
        if (head == NULL) {
            head = temp;  // Set the head to the first node
        } else {
            prev->next = temp;  // Link previous node to current node
        }
        prev = temp;  // Move prev to the current node
    }
    return head;
}

// Function to print the linked list
void printLinkedList(struct node *head) {
    struct node *temp = head;
    printf("The linked list is: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to insert at the beginning
struct node *insertAtBeg(struct node *head, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Overflow\n");
        return NULL;
    }
    new_node->data = data;
    new_node->next = head;
    head = new_node;
    return head;
}

// Function to insert a node before a node with value 'num'
struct node *insertAtBeforeNode(struct node *head, int value, int num) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Overflow\n");
        return NULL;
    }
    new_node->data = value;

    // If inserting before the head node
    if (head->data == num) {
        new_node->next = head;
        head = new_node;
        return head;
    }

    // Traverse to find the node before the node with 'num'
    struct node *temp = head;
    while (temp->next != NULL && temp->next->data != num) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        printf("The number %d is not present in the list.\n", num);
        free(new_node);
        return head;
    }

    new_node->next = temp->next;
    temp->next = new_node;
    return head;
}

// Function to insert a node after a node with value 'num'
struct node *insertAtAfterNode(struct node *head, int value, int num) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Overflow\n");
        return NULL;
    }
    new_node->data = value;

    struct node *temp = head;
    while (temp != NULL && temp->data != num) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("The number %d is not present in the list.\n", num);
        free(new_node);
        return head;
    }

    new_node->next = temp->next;
    temp->next = new_node;
    return head;
}

// Function to insert at the end of the linked list
struct node *insertAtEnd(struct node *head, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Overflow\n");
        return NULL;
    }
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        return new_node;  // If list is empty, new node becomes the head
    }

    struct node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = new_node;
    return head;
}


int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    struct node *head = createLinkedList(n);
    printLinkedList(head);

    int choice;
    do {
        printf("\n1. At the Beginning\n2. Before a Node\n3. After a Node\n4. At the End\n5. Exit\n");
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
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid entry! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
