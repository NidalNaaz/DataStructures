#include <iostream>
#include "BinarySearchTree.cpp"

int main() {
    BinarySearchTree bst;
    
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);
    
    std::cout << "In-order traversal (after inserting nodes): ";
    bst.printInOrder();
    std::cout << std::endl;

    std::cout << "Checking if 40 is in the tree: " << std::boolalpha << bst.contains(40) << std::endl;
    std::cout << "Checking if 90 is in the tree: " << std::boolalpha << bst.contains(90) << std::endl;

    bst.remove(30);
    std::cout << "In-order traversal (after removing 30): ";
    bst.printInOrder();
    std::cout << std::endl;

    return 0;
}
