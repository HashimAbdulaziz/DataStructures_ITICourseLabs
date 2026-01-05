#include "QueueLinkedList.h"

QueueLinkedList::QueueLinkedList(){front = rear = nullptr;}

QueueLinkedList::~QueueLinkedList(){
    while (!isEmpty()) {
        deleteFront();
    }
}

bool QueueLinkedList::isEmpty(){
    return front == nullptr;
}

// Insert at Rear
void QueueLinkedList::insertRear(int item){
    Node* newNode = new Node(item);

    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        newNode->prev = rear;
        rear = newNode;
    }
}

// Insert at Front
void QueueLinkedList::insertFront(int item){
    Node* newNode = new Node(item);

    if (isEmpty()) {
        front = rear = newNode;
    } else {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
}

// Delete from Front
int QueueLinkedList::deleteFront(){
    if (isEmpty()) {
        cout << "Empty Queue!\n";
        return -1;
    }

    Node* temp = front;
    int value = temp->data;

    if (front == rear) {
        front = rear = nullptr;
    } else {
        front = front->next;
        front->prev = nullptr;
    }

    delete temp;
    return value;
}


// Delete from Rear
int QueueLinkedList::deleteRear() {
    if (isEmpty()) {
        cout << "Empty Queue!\n";
        return -1;
    }

    Node* temp = rear;
    int value = temp->data;

    if (front == rear) {
        front = rear = nullptr;
    } else {
        rear = rear->prev;
        rear->next = nullptr;
    }

    delete temp;
    return value;
}



// Display Queue
void QueueLinkedList::display() {
    if (isEmpty()) {
        cout << "Empty Queue\n";
        return;
    }

    cout << "\n========================================\n";
    Node* temp = front;
    while (temp != nullptr) {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << "\n========================================\n";
}


