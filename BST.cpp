#include "BST.hpp"
#include <map>
#include <vector>
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

//Query 4: Average Income of Employees Aged Under a Certain Age
template <typename datatype>
double BST<datatype>::averageIncomeUnderAge(NodePtr root, int age, std::map<NodePtr, std::pair<double, int>>& memo) {
    if (!root) return 0.0;

    // If the result for this subtree is already computed, return it
    if (memo.find(root) != memo.end()) {
        auto [totalIncome, count] = memo[root];
        return count > 0 ? totalIncome / count : 0.0;
    }

    double totalIncome = 0.0;
    int count = 0;

    // Check the current node's age and income
    if (root->age < age) {
        totalIncome += root->income;
        count++;
    }

    // Recurse for left and right subtrees
    std::pair<double, int> leftResult, rightResult;

    if (root->left) {
        leftResult = memo[root->left];
        totalIncome += leftResult.first;  // Add income from left subtree
        count += leftResult.second;      // Add count from left subtree
    }
    if (root->right) {
        rightResult = memo[root->right];
        totalIncome += rightResult.first;  // Add income from right subtree
        count += rightResult.second;       // Add count from right subtree
    }

    // Memoize the result
    memo[root] = {totalIncome, count};

    // Return average income
    return count > 0 ? totalIncome / count : 0.0;
}

//Query 5: Median Performance Score
template <typename datatype>
void collectScores(NodePtr root, vector<float>& scores) {
    if (!root) return;

    collectScores(root->left, scores);
    scores.push_back(root->data.performanceScore);
    collectScores(root->right, scores);
}

template <typename datatype>
float BST<datatype>::findMedianPerformance(NodePtr root, map<NodePtr, vector<float>>& memo) {

    if (!root) return 0.0;

    if (memo.find(root) != memo.end()) {
        vector<float>& scores = memo[root];
        size_t n = scores.size();
        return n % 2 == 0 ? (scores[n / 2 - 1] + scores[n / 2]) / 2.0 : scores[n / 2];
    }

    vector<float> scores;
    collectScores(root, scores);
    memo[root] = scores;

    size_t n = scores.size();
    return n % 2 == 0 ? (scores[n / 2 - 1] + scores[n / 2]) / 2.0 : scores[n / 2];
}

//Query 6: Top 3 Employees with the Highest Income
template <typename datatype>
void BST<datatype>::collectTopIncomes(NodePtr root, vector<datatype>& topEmployees, int& count) {
    if (!root || count >= 3) return;

    // Reverse in-order traversal (Right -> Node -> Left)
    collectTopIncomes(root->right, topEmployees, count);

    // Add the current employee data if less than 3 employees collected
    if (count < 3) {
        topEmployees.push_back(root->data);  // Store the employee data (datatype)
        count++;
    }

    collectTopIncomes(root->left, topEmployees, count);
}

template <typename datatype>
void BST<datatype>::top3HighestIncome(NodePtr root, vector<datatype>& topEmployees, int& count) {
    collectTopIncomes(root, topEmployees, count);
};
