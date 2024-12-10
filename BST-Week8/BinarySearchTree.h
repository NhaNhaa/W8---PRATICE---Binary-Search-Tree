#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include <string>
#include <queue>
#include "Node.h"

class BinarySearchTree {
private:
    Node* root;
public:
    BinarySearchTree() : root(nullptr) {}
    BinarySearchTree(int value) {
        root = new Node(value);
    }
    int calculateHeight() {
        return calculateHeight(root);
    }
    Node* getroot() {
        return root;
    }
    std::string printTree() {
        std::string result = "";
        printTree(root, 0, result);
        return result;
    }

public:
    void insert(Node* root, int newValue) {
        if (newValue < root->data) {
            if (root->left == nullptr) {
                root->left = new Node(newValue);
            } else {
                insert(root->left, newValue);
            }
        } else {
            if (root->right == nullptr) {
                root->right = new Node(newValue);
            } else {
                insert(root->right, newValue);
            }
        }
    }

    bool search(Node* root, int key) {
        if (root == nullptr) return false;
        if (root->data == key) return true;
        if (key < root->data) {
            return search(root->left, key);
        } else {
            return search(root->right, key);
        }
    }

    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* deleteNode(Node* root, int value) {
        if (root == nullptr) return root;
        if (value < root->data) {
            root->left = deleteNode(root->left, value);
        } else if (value > root->data) {
            root->right = deleteNode(root->right, value);
        } else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    std::string levelOrderTraverse() {
        std::string result = "";
        if (root == nullptr) return result;
        std::queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            result += std::to_string(current->data) + " ";
            if (current->left != nullptr) q.push(current->left);
            if (current->right != nullptr) q.push(current->right);
        }
        return result;
    }

private:
    void printTree(Node* node, int depth, std::string& result) {
        if (node == nullptr) return;
        for (int i = 0; i < depth; ++i) {
            result += "- ";
        }
        result += std::to_string(node->data) + "\n";
        printTree(node->left, depth + 1, result);
        printTree(node->right, depth + 1, result);
    }

    int calculateHeight(Node* node) {
        if (node == nullptr) return 0;
        int leftHeight = calculateHeight(node->left);
        int rightHeight = calculateHeight(node->right);
        return std::max(leftHeight, rightHeight) + 1;
    }
};

#endif // BINARYSEARCHTREE_H
