#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node* prev;

    node(int d) {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

// Function to insert a new node at the end of the doubly circular linked list
void insertnode(node*& head, int d) {
    node* newnode = new node(d);
    cout << "MEMORY ADDRESS OF NODE IS: " << newnode << " WITH THIS DATA: " << d << endl;

    if (head == NULL) { // If the list is empty
        head = newnode;
        newnode->next = newnode;
        newnode->prev = newnode;
    } else {
        node* tail = head->prev; // Get the last node
        tail->next = newnode;
        newnode->prev = tail;
        newnode->next = head;
        head->prev = newnode;
    }
}

// Function to insert a new node after a specific node in the doubly circular linked list
void insertnodeafter(node*& head, int data, int newData) {
    if (head == NULL) {
        cout << "List is empty, cannot insert after " << data << endl;
        return;
    }

    node* temp = head;
    do {
        if (temp->data == data) {
            node* newNode = new node(newData);
            cout << "MEMORY ADDRESS OF VALUE NODE IS: " << newNode << " WITH THIS DATA: " << newData << endl;

            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    } while (temp != head);

    cout << "Node with data " << data << " not found." << endl;
}

// Function to delete a node with a specific value in the doubly circular linked list
void deletenode(node*& head, int d) {
    if (head == NULL) {
        cout << "List is empty, cannot delete " << d << endl;
        return;
    }

    node* current = head;
    do {
        if (current->data == d) {
            if (current == head && current->next == head) { // Single node case
                head = NULL;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                if (current == head) {
                    head = current->next;
                }
            }
            cout << "Deleted node with data: " << d << " at address: " << current << endl;
            delete current;
            return;
        }
        current = current->next;
    } while (current != head);

    cout << "Node with data " << d << " not found." << endl;
}

// Function to print the doubly circular linked list
void print(node* head) {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    node* temp = head;
    do {
        cout << "DATA IN THIS NODE IS: " << temp->data << endl;
        cout << "THE NEXT NODE IS: " << temp->next << " AND PREV NODE IS: " << temp->prev << endl;
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    node* head = NULL;

    insertnode(head, 10);
    insertnode(head, 20);
    insertnode(head, 30);
    insertnode(head, 40);

    cout << "List after insertions: " << endl;
    print(head);

    insertnodeafter(head, 20, 25);
    cout << "List after inserting 25 after 20: " << endl;
    print(head);

    deletenode(head, 30);
    cout << "List after deleting 30: " << endl;
    print(head);

    deletenode(head, 10);
    cout << "List after deleting 10 (head node): " << endl;
    print(head);

    return 0;
}
