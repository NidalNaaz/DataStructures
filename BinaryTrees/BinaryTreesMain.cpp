#include <iostream>
#include "BinaryTree.cpp"

int main() {
    BinaryTree tree(10);
    tree.insert(5);
    tree.insert(3);
    tree.insert(8);
    tree.insert(2);
    tree.insert(4);
    tree.insert(7);
    tree.insert(9);

    std::cout << "Pre-order traversal: ";
    tree.preOrder();
    std::cout << std::endl;

    std::cout << "In-order traversal: ";
    tree.inOrder();
    std::cout << std::endl;

    std::cout << "Post-order traversal: ";
    tree.postOrder();
    std::cout << std::endl;

    return 0;
}
