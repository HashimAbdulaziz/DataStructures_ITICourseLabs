#ifndef NODE_H
#define NODE_H

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

#endif
