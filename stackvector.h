#include<iostream>
#include<vector>
using namespace std;
template<typename T>

class stack{
    vector<T> arr;
public:
    void push(T data){
         arr.push_back(data);
    }
    void pop(){
        arr.pop_back();
    }

    T top(){
        int lastind=arr.size()-1;
        return arr[lastind];
    }     
    
    bool empty(){
        return arr.size()==0;
    }

    //for only int integer 
    void print(){
        for(auto x:arr){
            cout<<x<<"-->";
        }
    }
};