#include<bits/stdc++.h>
using namespace std;
#define MAX_SIZE 10000
template<typename T>
class Vector{
private:
    T arr[MAX_SIZE];
    int ind = -1;
public:
    void push_back(T x){
        if(ind >= MAX_SIZE-1){
            cout<<"Overflow"<<endl;
            return;
        }
        for(int i = 0; i <= ind; i++){
            if(arr[i] == x) return; // Already exists, do nothing
        }   
        arr[++ind] = x;
    }
    void pop(T x){
        if(empty()) {
            cout<<"Empty list!!!"<<endl;
            return;
        }
        bool found = false;
        for(int i=0;i<=ind;i++){
            if(arr[i] == x){
                found = true;
                 for(int j = i; j < ind; j++){
                        arr[j] = arr[j + 1];
                    }
                ind--;
                break;
            }
        }
        if(!found) {
            cout<<"No such Element exist"<<endl;
        }
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