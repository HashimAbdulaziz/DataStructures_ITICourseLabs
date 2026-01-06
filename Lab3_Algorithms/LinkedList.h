#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

using namespace std;

class Node {
public:
    Node* next;
    Node* prev;
    int data;

    Node(int data) {
        next = nullptr;
        prev = nullptr;
        this->data = data;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int count;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    LinkedList(int data) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        count = 1;
    }

    Node* getHead() {
        return head;
    }

    void insertLast(int data) {
        Node* newNode = new Node(data);

        if (tail == nullptr) {
            tail = newNode;
            head = newNode;
        }
        else {
            Node* oldNode = tail;
            tail->next = newNode;
            tail = newNode;
            tail->prev = oldNode;
        }
        count++;
    }

    void insertFirst(int data) {
        Node* newNode = new Node(data);
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
        count++;
    }

    void insertAfter(int data, int afterData) {
        Node* current = head;
        if (current == nullptr) {
            cout << "Ops LinkedList is empty!" << endl;
            return;
        }

        while (current != nullptr && current->data != afterData) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Ops node with data " << afterData << " not exist!" << endl;
            return;
        }

        if (current == tail) {
            insertLast(data);
        }
        else {
            Node* newNode = new Node(data);
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
            count++;
        }
    }

    void insertBefore(int data, int beforeData) {
        Node* current = head;
        if (current == nullptr) {
            cout << "Ops LinkedList is empty!" << endl;
            return;
        }

        while (current != nullptr && current->data != beforeData) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Ops node with data " << beforeData << " not exist!" << endl;
            return;
        }

        if (current == head) {
            insertFirst(data);
        }
        else {
            Node* newNode = new Node(data);
            newNode->prev = current->prev;
            newNode->next = current;
            current->prev->next = newNode;
            current->prev = newNode;
            count++;
        }
    }

    int getDataByIndex(int index) {
        Node* current = head;
        if (index > count - 1 || index < 0) {
            cout << "Ops index out of bounds";
            return -1;
        }
        for (int i = 0; i < index; i++, current = current->next);
        return current->data;
    }

    void removeFirst(int data) {
        Node* current = head;
        if (current == nullptr) return;

        while (current != nullptr && current->data != data) {
            current = current->next;
        }

        if (current == nullptr) return; // Data not found

        if (current != head)
            current->prev->next = current->next;
        else
            head = current->next;

        if (current != tail)
            current->next->prev = current->prev;
        else
            tail = current->prev;

        delete current;
        count--;
    }

    void removeALL(int data) {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            if (current->data == data) {
                removeFirst(data);
            }
            current = nextNode;
        }
    }

    void display() {
        Node* current = head;
        while (current) {
            cout << "[" << current->data << "]->";
            current = current->next;
        }
        cout << "NULL\n";
    }

    int getSize() {
        return count;
    }

    // Destructor
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

#endif
