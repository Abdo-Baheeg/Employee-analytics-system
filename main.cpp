#include <iostream>

#include "BST.hpp"
#include <string>
#include "Employee_Tree.hpp"
using namespace std;

EmployeeTree employees;

void QueryMenu() {
    cout << "1. Maximum Income in a Specific Age Range" << endl;
    cout << "2. Total Performance Score Below a Certain Age" << endl;
    cout << "3. Count of Employees in a Specific Age Range" << endl;
    cout << "4. Average Income of Employees Aged Under a Certain Age" << endl;
    cout << "5. Median Performance Score in the Tree" << endl;
    cout << "6. Top 3 Employees with the Highest Income" << endl;
    cout << "7. Find Employees with Income Above a Threshold" << endl;
    cout << "8. Total Income of Employees Aged Above a Certain Age" << endl;
    cout << "9. Minimum Performance Score Within a Range" << endl;
    cout << "10. Number of Employees with Performance Score Above a Certain Threshold" << endl;
    cout << "11. Average Performance Score for Employees Aged Between L and R" << endl;
    cout << "12. Top 5 Employees with the Lowest Performance Score" << endl;
    cout << "q. Quit" << endl;

    bool quit = false;
    while (!quit) {
        char choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                while (true) {
                    string input;
                    cout << "Enter minimum age (or 'q' to return): ";
                    cin >> input;
                    if (input == "q") break;

                    int minAge;
                    try {
                        minAge = stoi(input);
                    } catch (...) {
                        cout << "Invalid input! Please enter a positive integer." << endl;
                        continue;
                    }

                    cout << "Enter maximum age (or 'q' to return): ";
                    cin >> input;
                    if (input == "q") break;

                    int maxAge;
                    try {
                        maxAge = stoi(input);
                    } catch (...) {
                        cout << "Invalid input! Please enter a positive integer." << endl;
                        continue;
                    }

                    if (minAge <= 0 || maxAge <= 0 || minAge > maxAge) {
                        cout << "Invalid age range! Ensure minimum age is less than or equal to maximum age and both are positive." << endl;
                        continue;
                    }

                    // double maxIncome = employeeTree.getMaxIncomeInRange(minAge, maxAge);
                    // cout << "Maximum Income: " << maxIncome << endl;
                    break;
                }
                break;
            }
            case '2': {
                while (true) {
                    string input;
                    cout << "Enter age (or 'q' to return): ";
                    cin >> input;
                    if (input == "q") break;

                    int age;
                    try {
                        age = stoi(input);
                    } catch (...) {
                        cout << "Invalid input! Please enter a positive integer." << endl;
                        continue;
                    }

                    if (age <= 0) {
                        cout << "Invalid input! Age must be a positive integer." << endl;
                        continue;
                    }

                    // double totalScore = employeeTree.getTotalPerformanceScoreBelowAge(age);
                    // cout << "Total Performance Score: " << totalScore << endl;
                    break;
                }
                break;
            }
            case '3': {
                while (true) {
                    string input;
                    cout << "Enter minimum age (or 'q' to return): ";
                    cin >> input;
                    if (input == "q") break;

                    int minAge;
                    try {
                        minAge = stoi(input);
                    } catch (...) {
                        cout << "Invalid input! Please enter a positive integer." << endl;
                        continue;
                    }

                    cout << "Enter maximum age (or 'q' to return): ";
                    cin >> input;
                    if (input == "q") break;

                    int maxAge;
                    try {
                        maxAge = stoi(input);
                    } catch (...) {
                        cout << "Invalid input! Please enter a positive integer." << endl;
                        continue;
                    }

                    if (minAge <= 0 || maxAge <= 0 || minAge > maxAge) {
                        cout << "Invalid age range! Ensure minimum age is less than or equal to maximum age and both are positive." << endl;
                        continue;
                    }

                    // int count = employeeTree.getCountInRange(minAge, maxAge);
                    // cout << "Count of Employees: " << count << endl;
                    break;
                }
                break;
            }
            case '4': {
                while (true) {
                    string input;
                    cout << "Enter age (or 'q' to return): ";
                    cin >> input;
                    if (input == "q") break;

                    int age;
                    try {
                        age = stoi(input);
                    } catch (...) {
                        cout << "Invalid input! Please enter a positive integer." << endl;
                        continue;
                    }

                    if (age <= 0) {
                        cout << "Invalid input! Age must be a positive integer." << endl;
                        continue;
                    }

                    // double avgIncome = employeeTree.getAverageIncomeUnderAge(age);
                    // cout << "Average Income: " << avgIncome << endl;
                    break;
                }
                break;
            }
            case '5': {
                // double medianScore = employeeTree.getMedianPerformanceScore();
                // cout << "Median Performance Score: " << medianScore << endl;
                break;
            }
            case '6': {
                // auto top3 = employeeTree.getTop3HighestIncome();
                // cout << "Top 3 Employees with the Highest Income:" << endl;
                // for (const auto& employee : top3) {
                //     cout << employee << endl;
                // }
                break;
            }
            case '7': {
                while (true) {
                    string input;
                    cout << "Enter income threshold (or 'q' to return): ";
                    cin >> input;
                    if (input == "q") break;

                    double threshold;
                    try {
                        threshold = stod(input);
                    } catch (...) {
                        cout << "Invalid input! Please enter a positive number." << endl;
                        continue;
                    }

                    if (threshold <= 0) {
                        cout << "Invalid input! Threshold must be a positive number." << endl;
                        continue;
                    }

                    // auto employees = employeeTree.getEmployeesWithIncomeAbove(threshold);
                    // cout << "Employees with Income Above " << threshold << ":" << endl;
                    // for (const auto& employee : employees) {
                    //     cout << employee << endl;
                    // }
                    break;
                }
                break;
            }
            case '8': {
                while (true) {
                    string input;
                    cout << "Enter age (or 'q' to return): ";
                    cin >> input;
                    if (input == "q") break;

                    int age;
                    try {
                        age = stoi(input);
                    } catch (...) {
                        cout << "Invalid input! Please enter a positive integer." << endl;
                        continue;
                    }

                    if (age <= 0) {
                        cout << "Invalid input! Age must be a positive integer." << endl;
                        continue;
                    }

                    // double totalIncome = employeeTree.getTotalIncomeAboveAge(age);
                    // cout << "Total Income of Employees Aged Above " << age << ": " << totalIncome << endl;
                    break;
                }
                break;
            }
            case '9': {
                while (true) {
                    string input;
                    cout << "Enter minimum age (or 'q' to return): ";
                    cin >> input;
                    if (input == "q") break;

                    int minAge;
                    try {
                        minAge = stoi(input);
                    } catch (...) {
                        cout << "Invalid input! Please enter a positive integer." << endl;
                        continue;
                    }

                    cout << "Enter maximum age (or 'q' to return): ";
                    cin >> input;
                    if (input == "q") break;

                    int maxAge;
                    try {
                        maxAge = stoi(input);
                    } catch (...) {
                        cout << "Invalid input! Please enter a positive integer." << endl;
                        continue;
                    }

                    if (minAge <= 0 || maxAge <= 0 || minAge > maxAge) {
                        cout << "Invalid age range! Ensure minimum age is less than or equal to maximum age and both are positive." << endl;
                        continue;
                    }

                    // double minScore = employeeTree.getMinPerformanceScoreInRange(minAge, maxAge);
                    // cout << "Minimum Performance Score in Range [" << minAge << ", " << maxAge << "]: " << minScore << endl;
                    break;
                }
                break;
            }
            case '10': {
                while (true) {
                    string input;
                    cout << "Enter performance score threshold (or 'q' to return): ";
                    cin >> input;
                    if (input == "q") break;

                    double threshold;
                    try {
                        threshold = stod(input);
                    } catch (...) {
                        cout << "Invalid input! Please enter a positive number." << endl;
                        continue;
                    }

                    if (threshold <= 0) {
                        cout << "Invalid input! Threshold must be a positive number." << endl;
                        continue;
                    }

                    // int count = employeeTree.getCountWithPerformanceAbove(threshold);
                    // cout << "Number of Employees with Performance Score Above " << threshold << ": " << count << endl;
                    break;
                }
                break;
            }
            case 11: {
                while (true) {
                    string input;
                    cout << "Enter minimum age (or 'q' to return): ";
                    cin >> input;
                    if (input == "q") break;

                    int minAge;
                    try {
                        minAge = stoi(input);
                    } catch (...) {
                        cout << "Invalid input! Please enter a positive integer." << endl;
                        continue;
                    }

                    cout << "Enter maximum age (or 'q' to return): ";
                    cin >> input;
                    if (input == "q") break;

                    int maxAge;
                    try {
                        maxAge = stoi(input);
                    } catch (...) {
                        cout << "Invalid input! Please enter a positive integer." << endl;
                        continue;
                    }

                    if (minAge <= 0 || maxAge <= 0 || minAge > maxAge) {
                        cout << "Invalid age range! Ensure minimum age is less than or equal to maximum age and both are positive." << endl;
                        continue;
                    }

                    // double avgScore = employeeTree.getAveragePerformanceScoreInRange(minAge, maxAge);
                    // cout << "Average Performance Score for Employees Aged Between " << minAge << " and " << maxAge << ": " << avgScore << endl;
                    break;
                }
                break;
            }
            case 12: {
                // auto bottom5 = employeeTree.getBottom5LowestPerformanceScore();
                // cout << "Top 5 Employees with the Lowest Performance Score:" << endl;
                // for (const auto& employee : bottom5) {
                //     cout << employee << endl;
                // }
                break;
            }
            case 'q': {
                cout << "Exiting Program." << endl;
                quit = true;
                break;
            }
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
}

void EmployeeManagementMenu() {
    cout << "==========================================================================" << endl;
    bool quit = false;
    while (!quit) {
        cout << "1. Add new Employee.\n";
        cout << "2. Delete Employee.\n";
        cout << "3. Search Employees with specific age.\n";
        cout << "4. Display all employees.\n";
        cout << "5. Go to Queries.\n";
        cout << "q. Quit\n";
        cout << "Enter your choice: ";
        char choice;
        cin >> choice;
        switch (choice) {
            case '1':
                cout << "Enter Employee ID: ";
                string employeeID;
                cin >> employeeID;
                cout << "Enter Employee Name: ";
                string employeeName;
                cin >> employeeName;
                cout << "Enter Employee Age: ";
                int employeeAge;
                cin >> employeeAge;
                cout << "Enter Employee Salary: ";
                double employeeSalary;
                cin >> employeeSalary;
                cout << "Enter Employee Performance Score: ";
                double employeePerformanceScore;
                cin >> employeePerformanceScore;
                //employees.insert(Employee())

                break;
            case '2':
                cout << "Enter the name of the employee: ";
                string name;
                cin >> name;
                // employees.delete()

                break;
            case '3':
                /// search
                cout << "Enter age: ";
                int age;
                cin >> age;
                // process
                break;
            case '4':
                cout << "===========================================================================" << endl;

                // display all
                break;
            case '5':
                cout<< "Go to Queries!\n";
                QueryMenu();
                break;
            case 'q':
                cout << "Quit Program!\n";
                quit = true;
                break;
            default:
                cout << "Invalid Choice!\n";
        }
    }
}

int main() {
    
    EmployeeManagementMenu();

    return 0;
}