#include <iostream>
#include "LinkedList.h" // Include your linked list header

using namespace std;

// --- 1. Linear Search ---
int LinearSearch(LinkedList& list, int key) {
    Node* current = list.getHead();
    int index = 0;

    while (current != nullptr) {
        if (current->data == key) {
            return index; // Found
        }
        current = current->next;
        index++;
    }
    return -1; // Not found
}

// to swap values between two nodes
void SwapData(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// --- 2. Bubble Sort ---
void BubbleSort(LinkedList& list) {
    Node* head = list.getHead();
    if (head == nullptr) return;

    bool swapped;
    Node* ptr1;
    Node* lptr = nullptr; // Pointer to the last sorted element

    // Bubble Sort logic
    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                SwapData(ptr1, ptr1->next);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1; // last element is now sorted
    } while (swapped);
}

// --- 3. Insertion Sort ---
void InsertionSort(LinkedList& list) {
    Node* head = list.getHead();
    if (head == nullptr || head->next == nullptr) return;

    Node* current = head->next; // Start from second element

    while (current != nullptr) {
        Node* keyNode = current;
        Node* prevNode = current->prev;

        while (prevNode != nullptr && prevNode->data > keyNode->data) {
            SwapData(prevNode, keyNode);

            // Move pointers back
            keyNode = prevNode;
            prevNode = prevNode->prev;
        }
        current = current->next;
    }
}

int main() {
    LinkedList myList;

    myList.insertLast(50);
    myList.insertLast(10);
    myList.insertLast(40);
    myList.insertLast(20);
    myList.insertLast(30);

    cout << "Original List:" << endl;
    myList.display();

    cout << "-------------------------------" << endl;

    // Linear Search
    int searchKey = 40;
    int index = LinearSearch(myList, searchKey);
    if (index != -1)
        cout << "Linear Search: Value " << searchKey << " found at index " << index << endl;
    else
        cout << "Linear Search: Value " << searchKey << " not found." << endl;

    cout << "-------------------------------" << endl;


    cout << "Test Bubble Sort" << endl;
    BubbleSort(myList);
    myList.display();

    cout << "-------------------------------" << endl;


    LinkedList list2;
    list2.insertLast(5);
    list2.insertLast(1);
    list2.insertLast(4);
    list2.insertLast(2);
    list2.insertLast(8);

    cout << "New List for Insertion Sort:" << endl;
    list2.display();


    cout << "Test Insertion Sort" << endl;
    InsertionSort(list2);
    list2.display();

    return 0;
}
