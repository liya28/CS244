#include "list.hpp"
#include <iostream>

using namespace std;

struct node {
    int elem;
    node *next;
};

class LinkedList : public List {
    node *head;
    node *tail;
    int index;
    
    node *create_node(int num) {
        node *n = new node { num, NULL };
        return n;
    }
    
    bool invalidPos(int pos) {
        return (pos >= index || pos < 0); // Now zero-based
    }
    
    node *getPrevNode(int pos) {
        if (invalidPos(pos)) return NULL;
        node *curr = head;
        for (int i = 0; i < pos - 1; i++) curr = curr->next;
        return curr;
    }
    
    public:
    
    LinkedList() {
        index = 0;
        head = tail = NULL;
    }
    
    int add(int num) {
        node *n = create_node(num);
        
        if (!head) {
            head = tail = n;
        } else {
            tail->next = n;
            tail = n;
        }
        
        return ++index;
    }
    
    int get(int pos) {
        if (pos < 0 || pos >= index) return -1;  // Adjust bounds for zero-based index
        node *curr = head;
        for (int i = 0; i < pos; i++) curr = curr->next;
        return curr->elem;
    }
    
    int size() {
        return index;
    }
    
    void swap(int pos1, int pos2) {
        if (pos1 == pos2 || invalidPos(pos1) || invalidPos(pos2)) return;
        if (pos1 > pos2) std::swap(pos1, pos2);  // Ensure pos1 < pos2
        
        node *prev1 = (pos1 == 1) ? NULL : getPrevNode(pos1);
        node *prev2 = (pos2 == 1) ? NULL : getPrevNode(pos2);
        node *node1 = (prev1 == NULL) ? head : prev1->next;
        node *node2 = (prev2 == NULL) ? head : prev2->next;
    
        if (!node1 || !node2) return;
    
        // Adjust previous nodes' next pointers
        if (prev1) prev1->next = node2;
        else head = node2;
    
        if (prev2) prev2->next = node1;
        else head = node1;
    
        // Swap next pointers
        if (node1->next == node2) {
            node1->next = node2->next;
            node2->next = node1;
        } else if (node2->next == node1) {
            node2->next = node1->next;
            node1->next = node2;
        } else {
            std::swap(node1->next, node2->next);
        }
    
        // Update tail pointer if necessary
        if (node1 == tail) tail = node2;
        else if (node2 == tail) tail = node1;
    }

    
    void set(int pos, int num) {
        if (pos < 0 || pos >= index) return;
        node *curr = head;
        for (int i = 0; i < pos; i++) curr = curr->next;
        curr->elem = num;
    }
    
    void print() {
        node* currnode = head;
        if (head == NULL && tail == NULL) {
            cout << "(empty)";
            return;
        }
        while (true) {
            cout << currnode->elem;
            if (currnode == tail) {
                cout << endl;
                return;
            }
            cout << " -> ";
            currnode = currnode->next;
        }
    }
};
