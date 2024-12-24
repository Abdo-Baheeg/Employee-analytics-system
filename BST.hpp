#ifndef BST_H
#define BST_H

#include <iostream>

class BST {
private:
    // Node class definition
    class Node {
    public:
        int key;
        Vector<Employee> Employees;
        Node* left;
        Node* right;

    };

    // Typedef for convenience
    using NodePtr = Node*;

    NodePtr root; // Root of the BST

    // Helper functions (private)
    void insertAux(NodePtr& subtree, const T& value);
    bool searchAux(NodePtr subtree, const T& value) const;
    void inorderAux(std::ostream& out, NodePtr subtree) const;
    void preorderAux(std::ostream& out, NodePtr subtree) const;
    void postorderAux(std::ostream& out, NodePtr subtree) const;
    NodePtr eraseAux(NodePtr subtree, const T& value);
    NodePtr findMin(NodePtr subtree) const;
    NodePtr findMax(NodePtr subtree) const;

public:
    // Constructor
    BST() : root(nullptr) {}

    // Check if the tree is empty
    bool empty() const;

    // Public interface for insertion, deletion, and search
    void insert(const T& value);
    void erase(const T& value);
    bool search(const T& value) const;

    // Traversal functions
    void inorder(std::ostream& out) const;
    void preorder(std::ostream& out) const;
    void postorder(std::ostream& out) const;

    // Utility functions
    T minValue() const;
    T maxValue() const;

    void print(std::ostream& out)const;
};


#endif
