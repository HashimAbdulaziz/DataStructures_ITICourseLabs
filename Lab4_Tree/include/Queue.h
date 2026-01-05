#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

// Generic Node for the Queue
template <typename T>
class QNode {
public:
    T data; // T can be 'int' or 'TreeNode*'
    QNode* next;
    QNode* prev;

    QNode(T val) {
        data = val;
        next = prev = nullptr;
    }
};


template <typename T>
class Queue {
private:
    QNode<T>* front;
    QNode<T>* rear;

public:
    Queue() { front = rear = nullptr; }

    ~Queue() {
        while (!isEmpty()) deleteFront();
    }

    bool isEmpty() { return front == nullptr; }

    void enqueue(T item) { // insertRear
        QNode<T>* newNode = new QNode<T>(item);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }

    T dequeue() { // deleteFront
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return T(); // Returns default value (0 or null)
        }

        QNode<T>* temp = front;
        T value = temp->data;

        if (front == rear) {
            front = rear = nullptr;
        } else {
            front = front->next;
            front->prev = nullptr;
        }

        delete temp;
        return value;
    }
};

#endif
