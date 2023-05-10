#include <iostream>
#include<vector>
#include<stack>
// #include "stackvector.h"
using namespace std;
void insertbottem(stack<int>&s,int data){
    if(s.empty()){
      s.push(data);
      return ;
    }

    int temp=s.top();
    s.pop();
    insertbottem(s,data);
    s.push(temp);
}

void reverse(stack<int>&s){
    if(s.empty()){
        return ;
    }

    int temp=s.top();
    s.pop();
    reverse(s);
    insertbottem(s,temp);
}


int main(){

   stack<int>s;
   cout<<endl;
   s.push(1);
   s.push(2);
   s.push(3);
   s.push(4);
   cout<<endl;
   insertbottem(s,5); 
   //    reverse(s);
   while (!s.empty()){
       cout<<s.top()<<endl;
       s.pop();
   }
}
