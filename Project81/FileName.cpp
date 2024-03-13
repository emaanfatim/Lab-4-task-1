#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};
class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(NULL) {}
    void append(int data) {
        Node* new_node = new Node(data);
        if (head == NULL) {
            head = new_node;
            return;
        }
        Node* last_node = head;
        while (last_node->next != NULL) {
            last_node = last_node->next;
        }
        last_node->next = new_node;
    }
    bool search(int data) {
        Node* current = head;
        while (current != NULL) {
            if (current->data == data)
                return true;
            current = current->next;
        }
        return false;
    }
    void reverse() {
        Node* prev = NULL;
        Node* current = head;
        Node* next_node = NULL;
        while (current != NULL) {
            next_node = current->next;
            current->next = prev;
            prev = current;
            current = next_node;
        }
        head = prev;
    }
    void printList() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << "->";
            current = current->next;
        }
        cout << "NULL" << endl;
    }
    ~LinkedList() {
        Node* current = head;
        Node* next_node = NULL;
        while (current != NULL) {
            next_node = current->next;
            delete current;
            current = next_node;
        }
        head = NULL;
    }
};
int main() {
    LinkedList linkedList;
    linkedList.append(1);
    linkedList.append(2);
    linkedList.append(3);
    linkedList.append(4);
    cout << "Original linked list:" << endl;
    cout << "--------------------" << endl;
    linkedList.printList();
    cout << "------------------" << endl;
    int choice;
    do {
        int number;
        cout << "Enter a number to search in the linked list: ";
        cin >> number;
        cout << "Is " << number << " present in the linked list? " << (linkedList.search(number) ? "Yes" : "No") << endl;
        cout << "Do you want to search again? (1 for Yes / 0 for No): ";
        cin >> choice;
    } while (choice != 0);
    linkedList.reverse();
    cout << "---------------------" << endl;
    cout << "Reversed linked list:" << endl;
    linkedList.printList();
    cout << "---------------------";
    return 0;
}