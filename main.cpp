#include <iostream>

#include <C:\Users\Abdelrahman Bahig\CLionProjects\Employee-analytics-system\BST.hpp>
using namespace std;

void displayMenu() {
    cout << "1. Maximum Income in a Specific Age Range" << endl;
    cout << "2. Total Performance Score Below a Certain Age" << endl;
    cout << "3. Count of Employees in a Specific Age Range" << endl;
    cout << "4. Average Income of Employees Aged Under certain age" << endl;
    cout << "5. Median Performance Score in the Tree" << endl;
    cout << "6. Top 3 Employees with the Highest Income" << endl;
    cout << "7. Find Employees with Income Above a Threshold" << endl;
    cout << "8. Total Income of Employees Aged Above certain age" << endl;
    cout << "9. Minimum Performance Score Within a Range" << endl;
    cout << "10. Number of Employees with Performance Score Above a Certain Threshold" << endl;
    cout << "11. Average Performance Score for Employees Aged Between L and R" << endl;
    cout << "12. Top 5 Employees with the Lowest Performance Score" << endl;
    cout << "q. Quit" << endl;
    cout << "Enter your choice: ";
}

int main() {


    BST<int> employeeTree;

    bool quit = false;
    while (!quit) {
        char choice;
        displayMenu();
        cin >> choice;

        switch (choice) {
            case '1': {
                // int minAge, maxAge;
                // cout << "Enter minimum age: ";
                // cin >> minAge;
                // cout << "Enter maximum age: ";
                // cin >> maxAge;
                // cout << "Maximum Income: " << employeeTree.getMaxIncomeInRange(minAge, maxAge) << endl;
                break;
            }
            case '2': {
                // int age;
                // cout << "Enter age: ";
                // cin >> age;
                // cout << "Total Performance Score: " << employeeTree.getTotalPerformanceScoreBelowAge(age) << endl;
                break;
            }
            case '3': {
                // int minAge, maxAge;
                // cout << "Enter minimum age: ";
                // cin >> minAge;
                // cout << "Enter maximum age: ";
                // cin >> maxAge;
                // cout << "Count of Employees: " << employeeTree.getCountInRange(minAge, maxAge) << endl;
                break;
            }
            case '4': {
                // int age;
                // cout << "Enter age: ";
                // cin >> age;
                // cout << "Average Income: " << employeeTree.getAverageIncomeUnderAge(age) << endl;
                break;
            }
            case '5': {
                // cout << "Median Performance Score: " << employeeTree.getMedianPerformanceScore() << endl;
                // break;
            }
            case '6': {
                // auto top3 = employeeTree.getTop3HighestIncome();
                // cout << "Top 3 Employees with Highest Income: " << endl;
                // for (const auto& employee : top3) {
                //     cout << employee << endl;
                // }
                break;
            }
            case '7': {
                // double threshold;
                // cout << "Enter income threshold: ";
                // cin >> threshold;
                // auto employees = employeeTree.getEmployeesWithIncomeAbove(threshold);
                // cout << "Employees with Income Above " << threshold << ": " << endl;
                // for (const auto& employee : employees) {
                //     cout << employee << endl;
                // }
                break;
            }
            case '8': {
                int age;
                cout << "Enter age: ";
                cin >> age;
              //  cout << "Total Income: " << employeeTree.getTotalIncomeAboveAge(age) << endl;
                break;
            }
            case '9': {
                // int minAge, maxAge;
                // cout << "Enter minimum age: ";
                // cin >> minAge;
                // cout << "Enter maximum age: ";
                // cin >> maxAge;
                // cout << "Minimum Performance Score: " << employeeTree.getMinPerformanceScoreInRange(minAge, maxAge) << endl;
                break;
            }
            case '10': {
                // double threshold;
                // cout << "Enter performance score threshold: ";
                // cin >> threshold;
                // cout << "Number of Employees: " << employeeTree.getCountWithPerformanceAbove(threshold) << endl;
                break;
            }
            case 11: {
                int minAge, maxAge;
                cout << "Enter minimum age: ";
                cin >> minAge;
                cout << "Enter maximum age: ";
                cin >> maxAge;
                //cout << "Average Performance Score: " << employeeTree.getAveragePerformanceScoreInRange(minAge, maxAge) << endl;
                break;
            }
            case 12: {
                // auto bottom5 = employeeTree.getBottom5LowestPerformanceScore();
                // cout << "Top 5 Employees with Lowest Performance Score: " << endl;
                // for (const auto& employee : bottom5) {
                //     cout << employee << endl;
                // }
                break;
            }
            case 'q' : {
                cout << "Exiting Program." << endl;
                quit = true;
                break;
            }
            default:
                cout << "Invalid choice!" << endl;
                cout << "Please try again." << endl;
        }
    }

    return 0;
}