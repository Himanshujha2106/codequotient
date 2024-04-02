#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* create(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

void sinsert(Node** head_ref, Node* newNode) {
    Node* current = *head_ref;

    if (*head_ref == nullptr || (*head_ref)->data >= newNode->data) {
        newNode->next = *head_ref;
        if (*head_ref != nullptr) {
            (*head_ref)->prev = newNode;
        }
        *head_ref = newNode;
        return;
    }

    while (current->next != nullptr && current->next->data < newNode->data) {
        current = current->next;
    }

    newNode->next = current->next;
    if (current->next != nullptr) {
        current->next->prev = newNode;
    }
    current->next = newNode;
    newNode->prev = current;
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    int num;
    cout << "Enter numbers (enter any non-numeric value to stop): ";
    while (cin >> num) {
        Node* newNode = create(num);
        sinsert(&head, newNode);
        cout << "Sorted list after inserting " << num << ": ";
        printList(head);
        cout << "Enter next number: ";
    }

    cout << "Final sorted doubly linked list: ";
    printList(head);

    return 0;
}
