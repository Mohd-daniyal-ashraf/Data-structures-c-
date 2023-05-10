#include <iostream>
#include<vector>
// #include<stack>
#include "stackvector.h"
using namespace std;

int main(){
    stack <string> s;
    s.push("c++");
    s.push("python");
    s.push("java");
    s.push("c");
    cout<<endl;
    cout<<s.top()<<endl;

//    stack<int>s;
//    stack<int>n;
//    int data;
//    cin>>data;
//    n.push(data);
//    s.push(1);
//    s.push(2);
//    s.push(3);
//    s.push(4);
//     n.push(book);
   while (!s.empty()){
       cout<<s.top()<<endl;
       s.pop();
   }
//    while (!n.empty()){
//        cout<<n.top()<<endl;
//        n.pop();
//    }
   
   
}
