#pragma once

#include <iostream>

template <typename Key>
struct BinaryTreeNode {
    Key key;
    BinaryTreeNode* parent;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode() = default;

    static BinaryTreeNode* createNil() {
        auto nil = new BinaryTreeNode();
        nil->parent = nil;
        nil->left = nil;
        nil->right = nil;
    }

    explicit BinaryTreeNode(Key key) : key(key) {}
};

template <typename Key, typename Node=BinaryTreeNode<Key>>
class BinaryTree {
protected:
    Node* root;
    Node* nil;

    BinaryTree() {
        nil = Node::createNil();
        root = nil;
    }

    virtual void insert(Node*) = 0;
    virtual Node* remove(Node*) = 0;

    virtual void push(Key key) = 0;
    virtual void pop(Key key) = 0;

    void getNodeString(Node* node, std::string& res, const std::string& pad) const {
        if (node == nil) return;
        res += pad + ' ' + std::to_string(node->key) + ' ';
        if (node->left == nil && node->right == nil) {
            return;
        }
        res += "( ";
        getNodeString(node->left, res, "L");
        getNodeString(node->right, res, "R");
        res += ") ";
    }

    std::string getString() const {
        std::string res;
        getNodeString(root, res, "");
        return res;
    }

    friend std::ostream& operator<<(std::ostream& os, const BinaryTree& tree) {
        os << "Binary Tree[";
        os << tree.getString();
        os << " ]";
        return os;
    }

    void destroy(Node* node) {
        if (node == nil) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

    virtual ~BinaryTree() {
        destroy(root);
        delete nil;
    }
};
