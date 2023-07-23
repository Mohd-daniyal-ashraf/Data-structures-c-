#include<bits/stdc++.h>
// #include "heap.h"
using namespace std;

int main(){
    int v[]={2,3,5,4};
    int n=sizeof(v)/sizeof(int);
    priority_queue<int> h;
    for(int x: v){
        h.push(x);
    }
    while(!h.empty()){
        cout<<h.top()<<endl;
        h.pop();
    }
}

