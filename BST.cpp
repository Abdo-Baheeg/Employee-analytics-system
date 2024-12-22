#include "BST.hpp"
#include <iostream>
using namespace std;


template <typename datatype>
inline bool BST< datatype>::empty(){return root==0;}

template <typename datatype>
bool  BST< datatype>::  searchAux(BST<datatype>::NodePtr currentptr,const datatype value)
{
    if(currentptr==nullptr){return false;}
    if(currentptr->data <value)
        return searchAux(currentptr->right,value);
    else if(currentptr->data >value)
        return searchAux(currentptr->left,value);
    else
       return true;
}

template <typename datatype>
bool BST< datatype>:: search( datatype value)
{
     return searchAux(currentptr,value);
}

template <typename datatype>
void BST<datatype>::insertAux(BST<datatype>::BNodeptr root, datatype value)
{
  BNodeptr  newnode=new BST< datatype>:: BNodeptr(value);
if(empty())
{
    root= newnode(value);

}
 if(value < root->data){
    if(root->left==nullptr)
    {
       root->left  =newnode(value);
    }
    insert(value,root->left);
}
else if(value >root->data)
{
    if(root->right==nullptr)
    {
        root->right=newnode(value);
    }
    insert(root->right,value);
}
else {
    cerr<<"Item already exists ";
}
}

template <typename datatype>
void BST<datatype>::  insert(const datatype value)
{
    return insertAux(root,value);
}

template <typename datatype>
void BST<datatype>::erase(const datatype& item) {

    bool found;
    BST<datatype>::BNodeptr deletednode, parent; 
    serachAux(parent,value);

    if (!found) {
        cout << "value not found \n";
        return;
    }

    if (deletednode->left != 0 && deletednode->right != 0) { 

       
        BST<datatype>::BinNodePointer deletednodeSuc = deletednode->right;
        parent = deletednode;
        while (deletednodeSuc->left != 0) { 
            parent = deletednodeSuc;
            deletednodeSuc = deletednodeSuc->left;
        }

        deletednode->data = deletednodeSuc->data;
        deletednode = deletednodeSuc;
    }

 
    BST<datatype>::BinNodePointer subtree = deletednode->left;
    if (subtree == 0) subtree = deletednode->right;


    if (parent == 0) myRoot = subtree;

    else if (parent->left == deletednode) parent->left = subtree;

    else parent->right = subtree;
    delete deletednode;
}



template <typename datatype>
void BST< datatype>:: inorder(ostream&out)
{

}

template <typename datatype>
void  BST< datatype>::preorder(ostream&out)
{

}

template <typename datatype>
void BST< datatype>::postorder(ostream&out)
{

}

template <typename datatype>
datatype BST< datatype>:: minValue(BNodeptr& root)
{

   while(root!=nullptr)
    {
    searchAux(root->left,value);
    }
    return value;

}

template <typename datatype>
datatype BST< datatype>::maxValue(NodePtr& root){
    NodePtr temp=root;
    if(root!=nullptr){
      while(temp->right!=nullptr){
        temp=temp->right;
      }
      return temp->data;
    }
}





