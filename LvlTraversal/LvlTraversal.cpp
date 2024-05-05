#include "LevelOtrav.h"
#include <iostream>
#include <queue>

TreeNode::TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}

BinaryTree::BinaryTree() : root(nullptr) {}

BinaryTree::~BinaryTree() {
    // Free allocated memory for the tree nodes
}

void BinaryTree::insert(int val) {
    // Insertion logic implementation
}

void BinaryTree::levelOrderTraversal() {
    if (root == nullptr) {
        return;
    }
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        std::cout << current->data << " ";
        if (current->left) {
            q.push(current->left);
        }
        if (current->right) {
            q.push(current->right);
        }
    }
}
