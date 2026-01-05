#include <iostream>
#include "Queue.h"

using namespace std;

class TreeNode{
    public:
        TreeNode* left;
        int data;
        TreeNode* right;

        TreeNode(int data){
            this->data = data;
            left = right = nullptr;
        }
};

class Tree{
    public:
        TreeNode* root;

        Tree(){root = nullptr;}

        void createTree();
        void preorderTraversal(TreeNode* p);
        void postorderTraversal(TreeNode* p);
        void inorderTraversal(TreeNode* p);
        void levelorderTraversal(TreeNode* p);
        int height(TreeNode* p);

};

void Tree::createTree() {
    TreeNode* parent;
    TreeNode* temp;

    int data;

    Queue<TreeNode*> q;

    printf("Enter root value: ");
    scanf("%d", &data);

    root = new TreeNode(data);
    q.enqueue(root);

    while (!q.isEmpty()) {
        parent = q.dequeue();

        printf("Enter left child of %d (-1 for no node): ", parent->data);
        scanf("%d", &data);

        if (data != -1) {
            temp = new TreeNode(data);
            parent->left = temp;
            q.enqueue(temp); // Push pointer to queue
        }

        printf("Enter right child of %d (-1 for no node): ", parent->data);
        scanf("%d", &data);

        if (data != -1) {
            temp = new TreeNode(data);
            parent->right = temp;
            q.enqueue(temp); // Push pointer to queue
        }
    }
}


void Tree::preorderTraversal(TreeNode* p){
    if(p == nullptr)
        return;

    // PreOrder --> (root, left, right)

    printf("%d ", p->data); // visit Root

    preorderTraversal(p->left); // visit Left

    preorderTraversal(p->right); // visit Right
}

void Tree::inorderTraversal(TreeNode* p){
    if(p == nullptr)
        return;

    // InOrder --> (left, root, right)

    inorderTraversal(p->left); // visit Left

    printf("%d ", p->data); // visit Root

    inorderTraversal(p->right); // visit Right
}

void Tree::postorderTraversal(TreeNode* p){
    if(p == nullptr)
        return;

    // PostOrder --> (left, right, root)

    postorderTraversal(p->left); // visit Left

    postorderTraversal(p->right); // visit Right

    printf("%d ", p->data); // visit Root
}



int main() {
    Tree t;
    t.createTree();
    printf("\n");

    printf("Preorder: ");
    t.preorderTraversal(t.root);
    printf("\n");

    printf("Inorder: ");
    t.inorderTraversal(t.root);
    printf("\n");

    printf("Postorder: ");
    t.postorderTraversal(t.root);




    return 0;
}
