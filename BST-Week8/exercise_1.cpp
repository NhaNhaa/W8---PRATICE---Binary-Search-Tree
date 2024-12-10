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

    cout << "Tree structure:\n";
    cout << tree.printTree() << endl;

    cout << "Deleting node with value 5:\n";
    tree.deleteNode(root, 5);
    cout << tree.printTree() << endl;

    cout << "Searching for value 5:\n";
    (tree.search(root, 5)) ? cout << "Search Found\n" : cout << "Search Not Found\n";

    return 0;
}
