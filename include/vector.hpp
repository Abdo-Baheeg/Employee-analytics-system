#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <optional>
#include <stdexcept> 

template <typename T>
class Vector {
private:
    T* data;           
    size_t vec_size;   
    size_t vec_capacity; 

    // Private method to resize the array
    void resize(size_t new_capacity) {
        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < vec_size; i++) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        vec_capacity = new_capacity;
    }

public:

    Vector() : data(nullptr), vec_size(0), vec_capacity(0) {}


    ~Vector() {
        delete[] data;
    }

    size_t size() const {
        return vec_size;
    }


    size_t capacity() const {
        return vec_capacity;
    }

    bool empty() const {
        return vec_size == 0;
    }


    void push_back(const T& value) {
        if (vec_size == vec_capacity) {
            // Double the capacity if full, or start with a capacity of 1
            size_t new_capacity = (vec_capacity == 0) ? 1 : vec_capacity * 2;
            resize(new_capacity);
        }
        data[vec_size] = value;
        vec_size++;
    }

    // Remove the last element of the vector
    void pop_back() {
        if (vec_size > 0) {
            vec_size--;
        } else {
            throw std::underflow_error("Vector is empty");
        }
    }


    T& operator[](size_t index) {
        if (index >= vec_size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= vec_size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }


    void clear() {
        delete[] data;
        vec_size = 0;
    }

    #include <optional>
    // Function to find a value in the data array
    T find(T value) const {
        for (size_t i = 0; i < vec_size; i++) {
            if (data[i] == value) {
                return data[i];
            }
        }
        return nullptr;
    }

    void insert(size_t index, const T& value) {
        if (index >= vec_size) {
            throw std::out_of_range("Index out of range");
        }
        data[index] = value;
    }
    void erase(T value) {
        for (size_t i = 0; i < vec_size; i++) {
            if (data[i] == value) {
                data[i] = nullptr;
                return;
            }
        }
    }
    T& front() {
        if (vec_size == 0) {
            throw std::out_of_range("Vector is empty");
        }
        return data[vec_size - 1];
    }
    T& back() {
        if (vec_size == 0) {
            throw std::out_of_range("Vector is empty");
        }
        return data[vec_size - 1];
    }

};

#endif
