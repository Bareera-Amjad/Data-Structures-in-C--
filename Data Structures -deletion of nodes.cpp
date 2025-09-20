#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

void insertEnd(int val) {
    Node* n = new Node{val, NULL, NULL};
    if (head == NULL) {
        head = n;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = n;
    n->prev = temp;
}

void display() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteBegin() {
    if (head == NULL) return;
    Node* temp = head;
    head = head->next;
    if (head != NULL) head->prev = NULL;
    delete temp;
}

void deleteEnd() {
    if (head == NULL) return;
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->prev->next = NULL;
    delete temp;
}

void deleteAtPos(int pos) {
    if (head == NULL) return;
    if (pos == 1) {
        deleteBegin();
        return;
    }
    Node* temp = head;
    for (int i = 1; temp != NULL && i < pos; i++) temp = temp->next;
    if (temp == NULL) return;
    if (temp->next != NULL) temp->next->prev = temp->prev;
    if (temp->prev != NULL) temp->prev->next = temp->next;
    delete temp;
}

int main() {
    int choice, val, pos;
    do {
        cout << "1. Insert at End" << endl;
        cout << "2. Delete at Beginning" << endl;
        cout << "3. Delete at End" << endl;
        cout << "4. Delete at Position" << endl;
        cout << "5. Display" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: 
			cout << "Enter value: "; 
			cin >> val; insertEnd(val); break;
            case 2: 
			deleteBegin(); break;
            case 3: 
			deleteEnd(); break;
            case 4: 
			cout << "Enter position: "; cin >> pos; deleteAtPos(pos); break;
            case 5: display();
			 break;
            case 6: 
			break;
            default: cout << "Invalid choice" << endl;
        }
    } while (choice != 6);
    return 0;
}
