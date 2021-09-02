#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
    int data;
    struct node_t *next;
} Node;

void print_list(Node *node) {
    while(node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    Node *head = NULL;
    Node *current = NULL;

    head = (Node *)malloc(sizeof(Node));
    head->data = 10;  // (*head).data
    head->next = NULL;

    current = (Node *)malloc(sizeof(Node));
    current->data = 11;
    current->next = NULL;

    head->next = current;

    print_list(head);
    
    current = head;
    while(head != NULL) {
        head = head->next;
        free(current);
        current = head;
    }
    if(head == NULL) {
        printf("List is empty!\n");
    }
    return 0;
}