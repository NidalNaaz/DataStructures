#include<iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val);
};

class BinaryTree {
private:
    TreeNode* root;
public:
    BinaryTree();
    ~BinaryTree();
    void insert(int val);
    void levelOrderTraversal();
};


