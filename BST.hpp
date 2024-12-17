#ifndef BST_H
#define BST_H
#include <iostream>
using namespace std;

template <typename datatype>
class BST
{
    public:
BST(){};
bool empty();
void insert( datatype value);
void erase( datatype &value);
bool search( datatype value);
void inorder(ostream&out);
void preorder(ostream&out);
void postorder(ostream&out);



    private:
 class BNode
{
    public:
    datatype data;
    BNode *left;
    BNode *right;
    BNode(datatype value): data(value),left(nullptr),right(nullptr){};
    BNode():left(nullptr),right(nullptr){};
   
};typedef*BNodeptr;
BNodeptr root;



void  insertAux(BST<datatype>::BNodeptr &root, datatype &value);
bool searchAux(BST<datatype>::BNodeptr &root, datatype& value);
void inorderAux(ostream& out, BST<datatype>::BNodeptr subtreePtr);
void preorderAux(ostream& out, BST<datatype>::BNodeptr subtreePtr);
void postorderAux(ostream& out, BST<datatype>::BNodeptr subtreePtr);

datatype minValue(BNodeptr& root);
datatype maxValue(BNodeptr& root);



};

#endif BST_H