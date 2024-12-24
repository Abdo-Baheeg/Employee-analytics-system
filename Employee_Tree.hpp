//
// Created by Abdelrahman Bahig on 12/22/2024.
//
#include <iostream>
#include"BST.hpp"
using namespace std;

class EmployeeTree {
  public:
  EmployeeTree() {
    BST<Employee> employees;
  }
  void insertEmployee(string name, int id, int age, float performanceScore,double salary) {
    this->employees.insert( Employee(std::move(name),id,age,performanceScore,salary));
  }
  void deleteEmployee(int id) {
    this->employees.search();
  }
  void displayEmployees() {
    this->employees.print();
  }
  private:

};




