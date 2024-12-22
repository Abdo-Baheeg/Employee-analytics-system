#include <iostream>
#include <unordered_map>
#include <vector>
#include <bits/stdc++.h>
#include <climits> // For INT_MAX

using namespace std;

class Employee {
    public:
    int emp_id;
    float income;
    int age;
    float performance_score;
    Employee* left;
    Employee* right;

    
    Employee(int id, float income, int age, int score)
        : emp_id(id), income(income), age(age), performance_score(score), left(nullptr), right(nullptr) {}
};

class EmployeeBST{
    private:
    Employee* root;
    unordered_map<Employee* ,vector<Employee*>>incomeMemo; //income queries
    unordered_map<Employee* , int>totalIncomeMemo;          //total income
    unordered_map<Employee*,float>performaceMemo  ;              //min performance
   /*insert aux*/ void insertHelper(Employee* & employeeptr,int emp_id, float income, int age, float performance_score)
   {
 
        
        if(employeeptr==nullptr)
        {
               employeeptr=new Employee( emp_id,  income,  age, performance_score );
               return;
        }
        if(emp_id < employeeptr->emp_id){
            insertHelper(employeeptr->left,emp_id,  income,  age, performance_score);
        }
        else if(emp_id > employeeptr->emp_id){
            insertHelper(employeeptr->right ,emp_id,  income,  age, performance_score);
        }

   }
   vector<Employee*> findEmployeesAboveIncomeHelper(Employee* employeeptr, float threshold) 
   {
    
    if(employeeptr==nullptr)return {};
    //check if result already have memo;
    if(incomeMemo.find(employeeptr)!=incomeMemo.end())
    {
        return incomeMemo[employeeptr];
    }
    vector<Employee *>result;
    if(employeeptr->income >threshold)
     result.push_back(employeeptr);
    
    vector<Employee*>leftresult= findEmployeesAboveIncomeHelper( employeeptr->left,  threshold) ;
    vector<Employee*>rightresult= findEmployeesAboveIncomeHelper(employeeptr->right,  threshold); 

//combine leftresult and rightresult in one list
    result.insert(result.end(),leftresult.begin(),leftresult.end());
    result.insert(result.end(),rightresult.begin(),rightresult.end());


    incomeMemo[employeeptr]=result;
    return result;




   }

   float totalIncomeAboveAgeHelper(Employee *employeeptr,float ageThreshold)
   {
    if(employeeptr==nullptr){return 0;}
     if(totalIncomeMemo.find(employeeptr)!=totalIncomeMemo.end())
     {
        return totalIncomeMemo[employeeptr];
     }
     float totalincome=0;
     if(employeeptr->age >ageThreshold)
     {
        totalincome+=employeeptr->income;
     }
     totalincome+=totalIncomeAboveAgeHelper(employeeptr->left,ageThreshold);
     totalincome+=totalIncomeAboveAgeHelper(employeeptr->right,ageThreshold);
     totalIncomeMemo[employeeptr]=totalincome;
     return totalincome;

   }
   float MinPerformanceScoreHelper(Employee * employeeptr, int minage , int maxage)
   {
    if(employeeptr==nullptr) return INT_MAX;
    if(performaceMemo.find(employeeptr)!=performaceMemo.end())
    {
       return performaceMemo[employeeptr];
    }
    float minscore=INT_MAX;

    if(employeeptr->age >=minage && employeeptr->age <=maxage)
    {
        minscore=employeeptr->performance_score;
    }
    float minleft=MinPerformanceScoreHelper(employeeptr->left,minage,maxage);
   float  minright=MinPerformanceScoreHelper(employeeptr->right,minage,maxage);
   minscore=min(minscore,minleft);
   minscore=min(minscore,minright);

   performaceMemo[employeeptr]=minscore;
   return minscore;

   }

    public:
     EmployeeBST() : root(nullptr) {}
    void insert(int emp_id, float income, int age, float performance_score) {
        insertHelper(root, emp_id, income, age, performance_score);
    }
    float TotalIncomeAboveAge(float ageThreshold)
    {
        return totalIncomeAboveAgeHelper(root,ageThreshold);
    }

  // Public function to get employees with income above the given threshold
    vector<Employee*> getEmployeesAboveIncome(float threshold) {
        return findEmployeesAboveIncomeHelper(root, threshold);
    }
    float getMinPerformanceScoreInRange(int minage,int maxage)
    {
        return MinPerformanceScoreHelper(root,minage,maxage);

    }



};



int main() {
    // Create the BST
    EmployeeBST bst;

    // Insert some employees into the BST
    bst.insert(1, 100, 30, 80);
    bst.insert(2, 200, 45, 90);
    bst.insert(3, 300, 25, 75);
    bst.insert(4, 400, 50, 85);

    // 1. Find employees with income above 45000
    vector<Employee*> employees_above_income = bst.getEmployeesAboveIncome(100);
    cout << "Employees with income above 100:" << endl;
    for (auto& emp : employees_above_income) {
        cout << "Employee ID: " << emp->emp_id << ", Income: " << emp->income << endl;
    }

    // 2. Total income of employees aged above 30  
    int total_income = bst.TotalIncomeAboveAge(30);
    cout << "Total income of employees aged above 30: " << total_income << endl;
  
    // 3. Minimum performance score of employees aged between 30 and 50
    int min_performance_score = bst.getMinPerformanceScoreInRange(30, 50);
    cout << "Minimum performance score between 30 and 50 years old: " << min_performance_score << endl;

    return 0;
}
