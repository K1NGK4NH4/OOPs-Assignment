#include<bits/stdc++.h>
using namespace std;
#define MAX_SIZE 10000
template<typename T>
class Vector{
private:
     T* arr;      
    int capacity; 
    int ind;      
    //resizing new array when old is full
    void resize() {
        capacity = capacity * 2;
        T* newArr = new T[capacity];
        for (int i = 0; i <= ind; i++){
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }
public:
     Vector(int cap = 2) {  
        capacity = cap;
        arr = new T[capacity];
        ind = -1;
    }
    //Pushing an data back to vector
    void push_back(T x){
        for(int i = 0; i <= ind; i++){
            if(arr[i] == x) return; // Already exists, do nothing
        }   
        if (ind + 1 == capacity)
            resize();
        ind++;
        arr[ind] = x;
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
                for (int j = i; j < ind; j++){
                    arr[j] = arr[j + 1];
                }
                ind--;
                break;
            }
        }

        if (!found)
            cout << "Element not found!" << endl;
    }

    bool empty(){
        return ind == -1;
    }
    int size(){
        return ind+1;
    }
    void display(){
        if(empty()){
            cout<<"No elements to show"<<endl;
            return;
        }
        for(int i=0;i<=ind;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    std::optional<T> search(T x) {
        for (int i = 0; i <= ind; i++) {
            if (arr[i] == x)
                return arr[i]; 
        }
        return std::nullopt; 
    }
 };
int main(){
   Vector<int> v;
   v.push_back(1);
   v.push_back(2);
   v.push_back(3);
   v.display();
   cout<<v.size()<<endl;
   v.pop(2);
   v.push_back(4);
   v.push_back(4);
   v.push_back(5);
   v.pop(5);
   v.display();
}