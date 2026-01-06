#ifndef STACK_H
#define STACK_H

#include <stdio.h> // For printf if needed
#include "TreeNode.h"

// 2. Custom Stack Class for Node Pointers
class Stack {
private:
    int top;
    int size;
    TreeNode **array; // Array to hold Node pointers

public:
    // Constructor (default size 100)
    Stack(int capacity = 100) {
        size = capacity;
        top = -1;
        array = new TreeNode*[size];
    }

    // Destructor to clean up memory
    ~Stack() {
        delete[] array;
    }

    // Push operation
    void push(TreeNode* x) {
        if (top == size - 1) {
            printf("Stack Overflow\n");
        } else {
            top++;
            array[top] = x;
        }
    }

    // Pop operation (Returns Node* as required by your code)
    TreeNode* pop() {
        TreeNode* x = NULL;
        if (top == -1) {
            printf("Stack Underflow\n");
        } else {
            x = array[top];
            top--;
        }
        return x;
    }

    // Check if empty (Returns 1 if empty, 0 if not)
    int isEmpty() {
        return top == -1;
    }
};

#endif
