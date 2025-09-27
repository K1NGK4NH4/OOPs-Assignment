#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
using namespace std;

template<typename T>
class Vector {
private:
    T* arr;
    int capacity;
    int ind;

    void resize() {
        capacity *= 2;
        T* newArr = new T[capacity];
        for (int i = 0; i <= ind; i++)
            newArr[i] = arr[i];
        delete[] arr;
        arr = newArr;
    }

public:
    Vector(int cap = 2) {
        capacity = cap;
        arr = new T[capacity];
        ind = -1;
    }

    Vector(const Vector& other) {
        capacity = other.capacity;
        ind = other.ind;
        arr = new T[capacity];
        for (int i = 0; i <= ind; i++) {
            arr[i] = other.arr[i];
        }
    }

    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] arr;
            capacity = other.capacity;
            ind = other.ind;
            arr = new T[capacity];
            for (int i = 0; i <= ind; i++) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    ~Vector() {
        delete[] arr;
    }

    void push_back(T x) {
        if (ind + 1 == capacity)
            resize();
        arr[++ind] = x;
    }

    void pop(T x) {
        if (ind == -1) {
            cout << "Empty list!" << endl;
            return;
        }
        bool found = false;
        for (int i = 0; i <= ind; i++) {
            if (arr[i] == x) {
                found = true;
                for (int j = i; j < ind; j++)
                    arr[j] = arr[j + 1];
                ind--;
                break;
            }
        }
        if (!found)
            cout << "Element not found!" << endl;
    }

    void pop() {
        if (ind == -1) {
            cout << "Empty list!" << endl;
            return;
        }
        arr[ind--] = T();
    }

    bool empty() const { return ind == -1; }
    int size() const { return ind + 1; }

    void display () const  {
        if (empty()) {
            cout << "No elements to show" << endl;
            return;
        }
        for (int i = 0; i <= ind; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    void clear() {
        delete[] arr;
        capacity = 2;
        arr = new T[capacity];
        ind = -1;
    }

    const T& operator[](int index) const { return arr[index]; }
    T& operator[](int index) { return arr[index]; }
};

#endif