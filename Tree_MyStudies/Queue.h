#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;


template <typename T>
class Node {
    public:
        T data;
        Node* next;
        Node(T val) { data = val; next = nullptr; }
};


template <typename T>
class Queue {
    private:
        Node<T>* front;
        Node<T>* rear;

    public:
        Queue() { front = rear = nullptr; }

        bool isEmpty() { return front == nullptr; }

        void enqueue(T item) {
            Node<T>* newNode = new Node<T>(item);
            if (isEmpty()) front = rear = newNode;
            else { rear->next = newNode; rear = newNode; }
        }


        T dequeue() {
            if (isEmpty()) return T();
            Node<T>* temp = front;
            T val = temp->data;
            front = front->next;
            delete temp;
            return val;
        }

};
#endif
