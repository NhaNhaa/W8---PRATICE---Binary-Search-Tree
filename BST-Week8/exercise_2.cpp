#include <iostream>
#include "Node.h"
#include "BinarySearchTree.h"

using namespace std;

int main() {
    BinarySearchTree tree(7);
    Node* root = tree.getroot();

    tree.insert(root, 5);
    tree.insert(root, 1);
    tree.insert(root, 6);
    tree.insert(root, 9);
    tree.insert(root, 8);
    tree.insert(root, 11);

    cout << "Level-order traversal of the tree:\n";
    cout << tree.levelOrderTraverse() << endl;

    return 0;
}
