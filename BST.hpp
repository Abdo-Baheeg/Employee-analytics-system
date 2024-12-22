#ifndef BST_H
#define BST_H
#include <iostream>
#include <map>
#include <vector>
using namespace std;

template <typename datatype>
class BST{
    private:
    void collectTopIncomes(NodePtr root, vector<datatype>& topEmployees, int& count);

public:
    BST(){};
    bool empty();
    void insert( datatype value);
    void erase( datatype &value);
    bool search( datatype value);
    void inorder(ostream&out);
    void preorder(ostream&out);
    void postorder(ostream&out);

    // 4,5,6 queries
    //double averageIncomeUnderAge(NodePtr root, int age, map<NodePtr, pair<double, int>>& memo);
    double averageIncomeUnderAge(NodePtr root, int age, std::map<NodePtr, std::pair<double, int>>& memo);
    float findMedianPerformance(NodePtr root, map<NodePtr, vector<float>>& memo);
    void collectTopIncomes(NodePtr root, vector<datatype>& topEmployees, int& count);
    void top3HighestIncome(NodePtr root, vector<datatype>& topEmployees, int& count);




  private:
    class EmployeeNode
    {
    public:
        datatype data;
        int age;           // Age of the employee
        double income;         // Monthly income
        float performanceScore;  // Performance score
        EmployeeNode *left;
        EmployeeNode *right;
        EmployeeNode(datatype value): data(value),left(nullptr),right(nullptr){};
        EmployeeNode():left(nullptr),right(nullptr){};

};
typedef EmployeeNode* NodePtr; ;
NodePtr root{};



void  insertAux(BST<datatype>::NodePtr &root, datatype &value);
bool searchAux(BST<datatype>::NodePtr &root, datatype& value);
void inorderAux(ostream& out, BST<datatype>::NodePtr subtreePtr);
void preorderAux(ostream& out, BST<datatype>::NodePtr subtreePtr);
void postorderAux(ostream& out, BST<datatype>::NodePtr subtreePtr);

datatype minValue(NodePtr& root);
datatype maxValue(NodePtr& root);

};

#endif BST_H