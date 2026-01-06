#include <iostream>
#include "TreeNode.h"
#include "Queue.h"
#include "Stack.h"

using namespace std;


class Tree{
    public:
        TreeNode* root;

        Tree(){root = nullptr;}

        void createTree();
        void preorderRecursiveTraversal(TreeNode* p);
        void postorderRecursiveTraversal(TreeNode* p);
        void inorderRecursiveTraversal(TreeNode* p);

        void prerderIterationTraversal(TreeNode* t);
        void inorderIterationTraversal(TreeNode* t);
        void postorderIterationTraversal(TreeNode* t);


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


void Tree::preorderRecursiveTraversal(TreeNode* p){
    if(p == nullptr)
        return;

    // PreOrder --> (root, left, right)

    printf("%d ", p->data); // visit Root

    preorderRecursiveTraversal(p->left); // visit Left

    preorderRecursiveTraversal(p->right); // visit Right
}

void Tree::inorderRecursiveTraversal(TreeNode* p){
    if(p == nullptr)
        return;

    // InOrder --> (left, root, right)

    inorderRecursiveTraversal(p->left); // visit Left

    printf("%d ", p->data); // visit Root

    inorderRecursiveTraversal(p->right); // visit Right
}

void Tree::postorderRecursiveTraversal(TreeNode* p){
    if(p == nullptr)
        return;

    // PostOrder --> (left, right, root)

    postorderRecursiveTraversal(p->left); // visit Left

    postorderRecursiveTraversal(p->right); // visit Right

    printf("%d ", p->data); // visit Root
}


void preorderIteration(TreeNode* t){
	Stack st;

	while(t != NULL || !st.isEmpty()){
		if(t != NULL){
			printf("%d", t->data);
			st.push(t);
			t = t->left;
		}
		else{
			t = st.pop();
			t = t->right;
		}
	}
}


void Tree::inorderIterationTraversal(TreeNode* t){
	Stack st;

	while(t != NULL || !st.isEmpty()){
		if(t != NULL){
			st.push(t);
			t = t->left;
		}
		else{
			t = st.pop();
			printf("%d", t->data);
			t = t->right;
		}
	}
}


/* Postorder by change print location
// Why this FAILS for Postorder
else {
    t = st.pop();     // 1. We pop the Root (e.g., 200)
    t = t->right;     // 2. We move 't' to the Right Child (e.g., 230)
    printf(t->data);  // 3. BUG! You are printing 230, not 200!
                      //    And if 230 has children, you just skipped them!
}
*/


void Tree::postorderIterationTraversal(Node* t) {
    if (t == NULL) return;
    Stack st1, st2;

    st1.push(t);

    while (!st1.isEmpty()) {
        t = st1.pop();
        st2.push(t); // Don't print, save it for later

        // Push Left then Right (so Right is processed first -> Preorder modified)
        if (t->left) st1.push(t->left);
        if (t->right) st1.push(t->right);
    }

    // Print the second stack (Reverse order)
    while (!st2.isEmpty()) {
        t = st2.pop();
        printf("%d ", t->data);
    }
}



int main() {
    Tree t;
    t.createTree();
    printf("\n");

    printf("\n ======== testing Recursive version ===== \n");

    printf("Preorder: ");
    t.preorderRecursiveTraversal(t.root);
    printf("\n");

    printf("Inorder: ");
    t.inorderRecursiveTraversal(t.root);
    printf("\n");

    printf("Postorder: ");
    t.postorderRecursiveTraversal(t.root);

    printf("\n ======== testing Iteration version ===== \n");




    return 0;
}
