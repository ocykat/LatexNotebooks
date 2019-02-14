#pragma once

#include "array-list.h"
#include "binary-tree.h"
#include "../util/util.h"

template <typename Key, typename Node=BinaryTreeNode<Key>>
class BinarySearchTree : public BinaryTree<Key, Node> {
protected:
    virtual void insert(Node* inode) {
        auto parent = this->nil;
        auto curr = this->root;

        while (curr != this->nil) {
            parent = curr;

            if (inode->key < curr->key) {
                curr = curr->left;
            }
            else {
                curr = curr->right;
            }
        }

        inode->parent = parent;

        if (parent == this->nil) {
            this->root = inode;
        }
        else {
            if (inode->key < parent->key) {
                parent->left = inode;
            }
            else {
                parent->right = inode;
            }
        }
    }

    virtual Node* remove(Node* rnode) {
        if (rnode == this->nil) return this->nil;

        Node* rnode_parent = rnode->parent;

        // Case 1: rnode has only one child
        if (rnode->left == this->nil || rnode->right == this->nil) {
            if (rnode->left != this->nil) {
                if (rnode_parent == this->nil) {
                    this->root = rnode->left;
                }
                else if (rnode == rnode_parent->left) {
                    rnode_parent->left = rnode->left;
                }
                else {
                    rnode_parent->right = rnode->left;
                }

                rnode->left->parent = rnode_parent;
            }
            else {
                if (rnode->parent == this->nil) {
                    this->root = rnode->right;
                }
                else if (rnode == rnode_parent->left) {
                    rnode_parent->left = rnode->right;
                }
                else {
                    rnode_parent->right = rnode->right;
                }

                rnode->right->parent = rnode_parent;
            }

            delete rnode;
            return rnode_parent;
        }

        // Case 2: rnode has both children
        Node* next_larger = this->getMinNode(rnode->right);
        Node* next_larger_parent = next_larger->parent;

        if (next_larger_parent != rnode) {
            next_larger_parent->left = next_larger->right;
            next_larger->right->parent = next_larger_parent;
            util::swap(rnode->key, next_larger->key);

            delete next_larger;
            return next_larger_parent;
        }

        util::swap(rnode->key, next_larger->key);
        rnode->right = next_larger->right;
        next_larger->right->parent = rnode;

        delete next_larger;
        return rnode;
    }

    Node* search(Key key) const {
        Node* curr = this->root;

        while (curr != this->nil && curr->key != key) {
            if (key < curr->key) {
                curr = curr->left;
            }
            else {
               curr = curr->right;
            }
        }

        return curr;
    }

    Node* getMinNode(Node* root) const {
        Node* curr = root;

        while (curr->left != this->nil) {
            curr = curr->left;
        }

        return curr;
    }

    Node* getMaxNode(Node* root) const {
        Node* curr = root;

        while (curr->right != this->nil) {
            curr = curr->right;
        }

        return curr;
    }

public:
    virtual void push(Key key) {
        auto inode = new Node(key);
        inode->left = this->nil;
        inode->right = this->nil;
        inode->parent = this->nil;
        this->insert(inode);
    }

    virtual void pop(Key key) {
        this->remove(this->search(key));
    }

    bool hasKey(Key key) const {
        return this->search(key) != this->nil;
    }

    Key get(Key key) const {
        return this->search(key)->key;
    }

    Key getMin() const {
        return getMinNode(this->root)->key;
    }

    Key getMax() const {
        return getMaxNode(this->root)->key;
    }

    void inOrderGetKey(Node* node, ArrayList<Key>& list) {
        if (node == this->nil) return;
        inOrderGetKey(node->left, list);
        list.pushBack(node->key);
        inOrderGetKey(node->right, list);
    }

    ArrayList<Key> getArrayList() {
        ArrayList<Key> list;
        inOrderGetKey(this->root);
        return list;
    }
};