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

// push end
// pop end
// push head
// pop head
// push at
// pop at
// pop value
// Alla pop skall returna datat i den poppade noden

// Gör om listan till en dubbellänkad lista

int main() {
    Node *head = NULL;
    Node *tail = NULL;
    Node *current = NULL;

    head = (Node *)malloc(sizeof(Node));
    head->data = 10;  // (*head).data
    head->next = NULL;
    tail = head;

    current = (Node *)malloc(sizeof(Node));
    current->data = 11;
    current->next = NULL;

    head->next = current;
    tail = current;
    print_list(head);
    
    current = head;
    while(head != NULL) {
        head = head->next;
        free(current);
        current = head;
    }
    tail = NULL;
    if(head == NULL) {
        printf("List is empty!\n");
    }
    return 0;
}