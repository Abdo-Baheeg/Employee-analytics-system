#ifndef BST_H
#define BST_H

#include <iostream>
#include "include/vector.hpp"
#include "Employee.hpp"

class BST {
private:
    // Node class definition
    class Node {
    public:
        int key;
        Vector<Employee> Employees;
        Node* left;
        Node* right;

        Node(Employee e) {
            this->key = e.age;
            this->left = nullptr;
            this->right = nullptr;
            Employees.push_back(e);
        }

    };

    typedef   Node* NodePtr;

    NodePtr root; // Root of the BST

    // Helper functions (private)
    void insertAux(NodePtr& subtree, const Employee& value);
    bool searchAux(NodePtr subtree, const Employee& value) const;
    void inorderAux(std::ostream& out, NodePtr subtree) const;
    void preorderAux(std::ostream& out, NodePtr subtree) const;
    void postorderAux(std::ostream& out, NodePtr subtree) const;
    NodePtr eraseAux(NodePtr subtree, const Employee& value);
    NodePtr findMin(NodePtr subtree) const;
    NodePtr findMax(NodePtr subtree) const;
    void printAux(std::ostream& out, NodePtr subtree) const;

public:
    // Constructor
    BST() : root(nullptr) {}

    // Check if the tree is empty
    bool empty() const;

    // Public interface for insertion, deletion, and search
    void insert(const Employee& employee);
    void erase(const Employee& employee);
    bool search(const Employee& employee) const;

    // Traversal functions
    void inorder(std::ostream& out) const;
    void preorder(std::ostream& out) const;
    void postorder(std::ostream& out) const;

    void print(std::ostream& out)const;
};


#endif
