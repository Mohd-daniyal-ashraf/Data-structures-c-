#include<bits/stdc++.h>
using namespace std;

class fuck{
     vector<int> v;
     void heapify(int i){
        int left=2*i;
        int right=2*i+1;
        int minidx=i;
        if(left<v.size() && v[left]<v[i]){
            minidx=left;
        }
        if(right<v.size() && v[right]<v[minidx]){
            minidx=right;
        }
        if(minidx!=i){
            swap(v[i],v[minidx]);
            heapify(minidx);
        }
     }
public:
    fuck(int defultsize=11){
        v.reserve(defultsize);
        v.push_back(-1);
    }

    void push(int data){
        v.push_back(data);
        int ind=v.size()-1;
        int parent=ind/2;
        while(ind>1 && v[ind]<v[parent]){
           swap(v[ind],v[parent]);
           ind=parent;
           parent=parent/2;
        }
    }
    void pop(){
      int idx=v.size()-1;
      swap(v[1],v[idx]);
      v.pop_back();
      heapify(1);
    }
    
    int top(){
       return v[1];
    }

    bool empty(){
       return v.size()==1;
    }
};
