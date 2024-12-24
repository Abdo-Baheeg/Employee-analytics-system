//
// Created by Abdelrahman Bahig on 12/22/2024.
//
#include <iostream>
#include"BST.hpp"
using namespace std;

class EmployeeTree {
  public:
  EmployeeTree() {
    employees = BST<Employee>();
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
  class Node{
  public:
    string name;
    int id;
    int age;
    float performanceScore;
    double salary;
    Node(const string &name, const int id, const int age, const float performanceScore, double salary){
      this->name = name;
      this->id = id;
      this->age = age;
      this->performanceScore = performanceScore;
      this->salary = salary;
    }
  };
};




