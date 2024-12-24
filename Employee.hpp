//
// Created by Abdelrahman Bahig on 12/24/2024.
//
#include<iostream>
#include<string>
using namespace std;
class Employee{
public:
    string name;
    int id;
    int age;
    float performanceScore;
    double salary;
    Employee(const string &name, const int id, const int age, const float performanceScore, double salary){
        this->name = name;
        this->id = id;
        this->age = age;
        this->performanceScore = performanceScore;
        this->salary = salary;
    }
    Employee(){}
    bool operator==(const Employee &e) const {
        return name == e.name && age == e.age && id == e.id && performanceScore == e.performanceScore;
    }
    bool operator<(const Employee &e) const {
        return this-> age < e.age;
    }
    bool operator>(const Employee &e) const {
        return this-> age > e.age;
    }
    bool operator<=(const Employee &e) const {
        return this-> age <= e.age;
    }
    Employee& operator=() {
        return *this;
    }
};
