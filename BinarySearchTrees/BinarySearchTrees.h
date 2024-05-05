#include<iostream>

class TreeNode {
public:
    int key;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : key(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    TreeNode* root;
    void clearTree(TreeNode* node);
    TreeNode* insertHelper(TreeNode* node, int key);
    TreeNode* removeHelper(TreeNode* node, int key);
    TreeNode* findMin(TreeNode* node);
    TreeNode* searchHelper(TreeNode* node, int key);
    void inOrderTraversal(TreeNode* node);

public:
    BinarySearchTree();
    ~BinarySearchTree();
    void insert(int key);
    void remove(int key);
    bool contains(int key);
    void printInOrder();
};

