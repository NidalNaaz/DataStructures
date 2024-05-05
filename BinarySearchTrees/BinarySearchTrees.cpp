#include "BinarySearchTree.h"
#include <iostream>

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::~BinarySearchTree() {
    clearTree(root);
}

void BinarySearchTree::clearTree(TreeNode* node) {
    if (node) {
        clearTree(node->left);
        clearTree(node->right);
        delete node;
    }
}

void BinarySearchTree::insert(int key) {
    root = insertHelper(root, key);
}

TreeNode* BinarySearchTree::insertHelper(TreeNode* node, int key) {
    if (!node) {
        return new TreeNode(key);
    }
    if (key < node->key) {
        node->left = insertHelper(node->left, key);
    } else if (key > node->key) {
        node->right = insertHelper(node->right, key);
    }
    return node;
}

void BinarySearchTree::remove(int key) {
    root = removeHelper(root, key);
}

TreeNode* BinarySearchTree::removeHelper(TreeNode* node, int key) {
    if (!node) {
        return nullptr;
    }
    if (key < node->key) {
        node->left = removeHelper(node->left, key);
    } else if (key > node->key) {
        node->right = removeHelper(node->right, key);
    } else {
        if (!node->left) {
            TreeNode* temp = node->right;
            delete node;
            return temp;
        } else if (!node->right) {
            TreeNode* temp = node->left;
            delete node;
            return temp;
        }
        TreeNode* temp = findMin(node->right);
        node->key = temp->key;
        node->right = removeHelper(node->right, temp->key);
    }
    return node;
}

TreeNode* BinarySearchTree::findMin(TreeNode* node) {
    while (node && node->left) {
        node = node->left;
    }
    return node;
}

bool BinarySearchTree::contains(int key) {
    TreeNode* foundNode = searchHelper(root, key);
    return foundNode != nullptr;
}

TreeNode* BinarySearchTree::searchHelper(TreeNode* node, int key) {
    if (!node || node->key == key) {
        return node;
    }
    if (key < node->key) {
        return searchHelper(node->left, key);
    } else {
        return searchHelper(node->right, key);
    }
}

void BinarySearchTree::printInOrder() {
    inOrderTraversal(root);
}

void BinarySearchTree::inOrderTraversal(TreeNode* node) {
    if (!node) {
        return;
    }
    inOrderTraversal(node->left);
    std::cout << node->key << " ";
    inOrderTraversal(node->right);
}
