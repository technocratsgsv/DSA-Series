#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Create new node
struct node *createNode(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Create linked list
struct node *createLinkedList(int n) {
    struct node *head = NULL, *temp = NULL, *prev = NULL;
    for (int i = 1; i <= n; i++) {
        int data;
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        temp = createNode(data);
        if (!head)
            head = temp;
        else
            prev->next = temp;
        prev = temp;
    }
    return head;
}

// Print linked list
void printLinkedList(struct node *head) {
    struct node *temp = head;
    printf("The linked list is: ");
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Delete at beginning
struct node *deleteAtBeg(struct node *head) {
    if (!head) {
        printf("List is empty.\n");
        return NULL;
    }
    struct node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Delete at end
struct node *deleteAtEnd(struct node *head) {
    if (!head) {
        printf("List is empty.\n");
        return NULL;
    }
    if (!head->next) {
        free(head);
        return NULL;
    }
    struct node *temp = head;
    while (temp->next->next) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

// Delete after a node
struct node *deleteAfterNode(struct node *head, int after) {
    struct node *temp = head;
    while (temp && temp->data != after)
        temp = temp->next;
    if (!temp || !temp->next) {
        printf("Cannot delete after %d — node not found or no next node.\n", after);
        return head;
    }
    struct node *del = temp->next;
    temp->next = del->next;
    free(del);
    return head;
}

// Delete before a node
struct node *deleteBeforeNode(struct node *head, int value) {
    if (!head || head->data == value) {
        printf("No node exists before %d.\n", value);
        return head;
    }

    if (head->next && head->next->data == value) {
        // Delete head
        struct node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct node *prev = NULL, *curr = head, *next = head->next;

    while (next && next->data != value) {
        prev = curr;
        curr = next;
        next = next->next;
    }

    if (!next) {
        printf("Node with value %d not found.\n", value);
        return head;
    }

    if (prev) {
        prev->next = next;
        free(curr);
    }

    return head;
}

// Main Function 

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    struct node *head = createLinkedList(n);
    printLinkedList(head);

    int choice;
    do {
        printf("\n1. Delete at Beginning\n2. Delete Before Node\n3. Delete After Node\n4. Delete at End\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        int refValue;
        switch (choice) {
            case 1:
                head = deleteAtBeg(head);
                printLinkedList(head);
                break;
            case 2:
                printf("Enter the value before which to delete: ");
                scanf("%d", &refValue);
                head = deleteBeforeNode(head, refValue);
                printLinkedList(head);
                break;
            case 3:
                printf("Enter the value after which to delete: ");
                scanf("%d", &refValue);
                head = deleteAfterNode(head, refValue);
                printLinkedList(head);
                break;
            case 4:
                head = deleteAtEnd(head);
                printLinkedList(head);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}

