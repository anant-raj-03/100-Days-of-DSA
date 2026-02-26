#include <stdlib.h>

// Node definition
typedef struct Node {
    int val;
    struct Node* next;
} Node;

// Linked list definition
typedef struct {
    Node* head;
    int size;
} MyLinkedList;


// Create list
MyLinkedList* myLinkedListCreate() {
    MyLinkedList* obj = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    obj->head = NULL;
    obj->size = 0;
    return obj;
}


// Get value at index
int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size)
        return -1;

    Node* curr = obj->head;
    for (int i = 0; i < index; i++)
        curr = curr->next;

    return curr->val;
}


// Add at head
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = obj->head;
    obj->head = node;
    obj->size++;
}


// Add at tail
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = NULL;

    if (obj->head == NULL) {
        obj->head = node;
    } else {
        Node* curr = obj->head;
        while (curr->next)
            curr = curr->next;
        curr->next = node;
    }
    obj->size++;
}


// Add at index
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index < 0 || index > obj->size)
        return;

    if (index == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }

    Node* prev = obj->head;
    for (int i = 0; i < index - 1; i++)
        prev = prev->next;

    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->next = prev->next;
    prev->next = node;

    obj->size++;
}


// Delete at index
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->size)
        return;

    Node* temp;

    if (index == 0) {
        temp = obj->head;
        obj->head = obj->head->next;
        free(temp);
    } else {
        Node* prev = obj->head;
        for (int i = 0; i < index - 1; i++)
            prev = prev->next;

        temp = prev->next;
        prev->next = temp->next;
        free(temp);
    }

    obj->size--;
}


// Free entire list
void myLinkedListFree(MyLinkedList* obj) {
    Node* curr = obj->head;
    while (curr) {
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/