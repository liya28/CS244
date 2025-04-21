#include "node.hpp"
#include <iostream>

using namespace std;

class RedBlackTree {
    private:
    node *root;
    
    void rotateLeft(node *x) {
        node *y = x->right; // x's right child and becomes the new root
        x->right = y->left; // y's left child becomes the new right of x 
        
        if (y->left) y->left->parent = x;
        // if y had a left child, point its new parent
        
        y->parent = x->parent;
        if (!x->parent) root = y;
        else if (x == x->parent->left) x->parent->left = y;
        else x->parent->right = y;
        
        y->left = x;
        x->parent = y;
        
    }
    
    void rotateRight(node *x) {
        node *y = x->left;
        x->left = y->right;
        
        if (y->right) y->right->parent = x;
        y->parent = x->parent;
        if (!x->parent) root = y;
        else if (x == x->parent->right) x->parent->right = y;
        else x->parent->left = y;
        
        y->right = x;
        x->parent = y;
    }
    
    void fixInsert(node *x) {
        node *y, *z;
        
        while (x != root && x->parent->isRed) {
            y = x->parent;
            z = y->parent;
            
            // case: a parent is left child of grandparent
            if (y == z->left) {
                node *u = z->right; // uncle
                if (u && u->isRed) {
                    // case 1: uncle is red
                    y->isRed = false;
                    u->isRed = false;
                    z->isRed = true;
                    x = z;
                } else {
                    if (x == y->left) {
                        // case 2 
                        x = y;
                        rotateRight(x);
                        y = x->parent;
                        z = y->parent;
                    }
                    // case 3 
                    y->isRed = false;
                    z->isRed = true;
                    rotateLeft(z);
                }
            }
        }
        root->isRed = false;
    }
    
    node *insertBST(node *root, node *x) {
        if (!root) return x;
        if (x->elem < root->elem) {
            root->left = insertBST(root->left, x);
            root->left->parent = root;
        } else {
            root->right = insertBST(root->right, x);
            root->right->parent = root;
        }
        
        return root;
    }
    
    node *search(node *root, int elem) {
        
    }
    
    public:
    RedBlackTree() {
        root = nullptr;
    }
    
    void insert(int elem) {
        node *n = new node();
        n->elem = elem;
        n->isRed = true;
        
        root = insertBST(root, n);
        fixInsert(n);
    }
    
    bool search(int elem) {
        
    }
    
    void print() {
        
    }
    
    void inorder(node *n) {
        
    }
};
