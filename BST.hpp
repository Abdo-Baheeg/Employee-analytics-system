#ifndef BST_H
#define BST_H
#include <iostream>
using namespace std;

template <typename datatype>
class BST{
public:
    BST(){};
    bool empty();
    bool search(const datatype& value) const;
    void insert(const datatype& value);
    void erase(const datatype& value);
    void inorder(ostream&out) const;
    void preorder(ostream&out) const;
    void postorder(ostream&out) const;

private:
 class EmployeeNode{
    public:
        datatype data;
        int age;           // Age of the employee
        double income;         // Monthly income
        double performanceScore;  // Performance score
        EmployeeNode* left;
        EmployeeNode* right;
        EmployeeNode(datatype value): data(value),left(nullptr),right(nullptr){};
        EmployeeNode():left(nullptr),right(nullptr){};
};
typedef EmployeeNode* NodePtr; ;
NodePtr root{};



void insertAux(BST<datatype>::NodePtr &root, datatype& value);
bool searchAux(BST<datatype>::NodePtr &root, datatype& value);
void inorderAux(ostream& out, BST<datatype>::NodePtr subtreePtr);
void preorderAux(ostream& out, BST<datatype>::NodePtr subtreePtr);
void postorderAux(ostream& out, BST<datatype>::NodePtr subtreePtr);

datatype minValue(NodePtr& root);
datatype maxValue(NodePtr& root);



};

#endif BST_H