#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node *next;
};

void print_list(struct node *head);
struct node* insert_at_end(struct node *head, int data);
int delete_at_front(struct node **phead); 
 
int main() {
    struct node *head = NULL;
    head = insert_at_end(head, 10);
    head = insert_at_end(head, 20);
    head = insert_at_end(head, 30);
    delete_at_front(&head);
    delete_at_front(&head);
    delete_at_front(&head);
    return 0;
}

void print_list(struct node *head) {
    struct node *current = head;
    if (current == NULL) {
        printf("Empty list.\n");
    } else {
        while (current) {
            printf("|%d|%p| -> ", current->data, current->next);
            current = current->next;
        } 
        printf("\n");
    } 
}

struct node* insert_at_end(struct node *head, int data) {
    // create a new node.
    struct node * new_node = malloc(sizeof(struct node));
    assert(new_node != NULL);
    new_node->data = data;
    new_node->next = NULL;

    // list is empty.
    if (head == NULL) {
        head = new_node;
        return head;    
    }

    // list has some elements already.
    struct node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = new_node;
    return head;
}

int delete_at_front(struct node **phead) {
    struct node *first = *phead;
    assert(first != NULL);
    *phead = first->next;
    int data = first->data;
    free(first);
    first = NULL;
    return data;
}
