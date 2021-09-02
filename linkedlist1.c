#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
    int data;
    struct node_t *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int length;
} LinkedList;


void init_list(LinkedList *list) {
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
}

void print_list(LinkedList *list) {
    Node *node = list->head;
    while(node != NULL) {
        printf("%d", node->data);
        if(node->next == NULL) {
            printf(" -| ");
        }
        else {
            printf(" -> ");
        }
        
        node = node->next;
    }
    printf("\n");
}

Node *push_tail(LinkedList *list, int data) {
    if (list->tail == NULL) {
        // List is empty
        list->tail = (Node *)malloc(sizeof(Node));
        if(list->tail == NULL) {
            printf("Memery error!\n");
            return list->tail;
        }
        list->tail->data = data;
        list->tail->next = NULL;
        list->head = list->tail;
        list->length++;
        return list->tail;
    }

    // We have something in the list
    list->tail->next = (Node *)malloc(sizeof(Node));
    if(list->tail == NULL) {
        printf("Memery error!\n");
        return list->tail;
    }
    list->tail = list->tail->next;
    list->tail->data = data;
    list->tail->next = NULL;
    list->length++;
    return list->tail;
}

// push head
// pop head
// push tail
// pop tail
// push at
// pop at
// pop value
// peek at
// Alla pop skall returna datat i den poppade noden

// Gör om listan till en dubbellänkad lista

int main() {

    LinkedList list;
    init_list(&list);


    push_tail(&list, 1);
    push_tail(&list, 2);
    push_tail(&list, 3);
    push_tail(&list, 4);
    printf("%d\n", list.length);
    print_list(&list);

    Node *current = list.head;
    while(list.head != NULL) {
        list.head = list.head->next;
        free(current);
        list.length--;
        current = list.head;
    }
    list.tail = NULL;
    if(list.head == NULL) {
        printf("List is empty!\n");
    }
    printf("%d\n", list.length);
    return 0;
}