#include<iostream>
#include"BST.hpp"
using namespace std;

//employee info peter had to use 
struct Employee {
    int age;               // Age of the employee
    double income;         // Monthly income
    int performanceScore;  // Performance score
};

//                    from Quiry 8 -> 12
//-------------------------------------------------------------------

//Query 8: Total Income of Employees Aged Above a Certain Age
template <typename datatype>
double BST<datatype>::totalIncomeAboveAge(BNodeptr root, int age) {
    if (!root) return 0.0;
    double total = 0.0;

    Employee emp = root->data; // Assuming each node stores an Employee
    if (emp.age > age) {
        total += emp.income;  // Include income if age > threshold
    }
    return total + totalIncomeAboveAge(root->left, age) + totalIncomeAboveAge(root->right, age);
}


//Query 9: Minimum Performance Score Within a Range
template <typename datatype>
int BST<datatype>::minPerformanceInRange(BNodeptr root, int low, int high) {
    if (!root) return INT_MAX;

    Employee emp = root->data;
    int minScore = INT_MAX;

    if (emp.age >= low && emp.age <= high) {
        minScore = emp.performanceScore; // Check only within range
    }
    return min({ minScore, minPerformanceInRange(root->left, low, high), minPerformanceInRange(root->right, low, high) });
}


//Query 10: Number of Employees with Performance Score Above a Certain Threshold
template <typename datatype>
int BST<datatype>::countPerformanceAbove(BNodeptr root, int threshold) {
    if (!root) return 0;

    Employee emp = root->data;
    int count = 0;

    if (emp.performanceScore > threshold) {
        count = 1; // Increment count if performance score > threshold
    }
    return count + countPerformanceAbove(root->left, threshold) + countPerformanceAbove(root->right, threshold);
}

// Query 11: Average Performance Score for Employees Aged Between L and R
// Calculate total performance score
template <typename datatype>
int BST<datatype>::totalPerformanceInRange(BNodeptr root, int low, int high) {
    if (!root) return 0;

    int total = 0;
    Employee emp = root->data;

    if (emp.age >= low && emp.age <= high) {
        total += emp.performanceScore; // Add performance score if age is within range
    }

    // Recursive calls for left and right subtrees
    return total + performanceInRange(root->left, low, high) + performanceInRange(root->right, low, high);
}

// Count employees in age range
template <typename datatype>
int BST<datatype>::countPerformanceInRange(BNodeptr root, int low, int high) {
    if (!root) return 0;

    int count = 0;
    Employee emp = root->data;

    if (emp.age >= low && emp.age <= high) {
        count = 1; // Increment count if age is within range
    }

    // Recursive calls for left and right subtrees
    return count + countPerformanceInRange(root->left, low, high) + countPerformanceInRange(root->right, low, high);
}

// Calculate the average performance score
template <typename datatype>
double BST<datatype>::averagePerformance(BNodeptr root, int low, int high) {
    if (!root) return 0.0; // If tree is empty, return 0.0

    int count = countPerformanceInRange(root, low, high);
    if (count == 0) {
        cerr << "No employees found in the specified age range.\n";
        return 0.0; // Avoid division by zero
    }

    double totalPerformance = static_cast<double>(performanceInRange(root, low, high));
    return totalPerformance / count; // Calculate average
}

//Query 12: Top 5 Employees with the Lowest Performance Score
template <typename datatype>
void BST<datatype>::top5LowestPerformance(BNodeptr root, ostream& out, int& count) {
    if (!root || count >= 5) return; // Stop traversal if 5 nodes are collected or tree is empty

    // Traverse the left subtree
    top5LowestPerformance(root->left, out, count);

    // Process the current node
    if (count < 5) {
        Employee emp = root->data; // Assuming `data` is of type `Employee`
        out << "Age: " << emp.age << ", Performance Score: " << emp.performanceScore << endl;
        count++;
    }

    // Traverse the right subtree
    top5LowestPerformance(root->right, out, count);
}
