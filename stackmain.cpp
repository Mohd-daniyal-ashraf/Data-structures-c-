#include <iostream>
#include "stack.h"
using namespace std;

int main(){
    stack<int> s;
    s. push(1);
    s. push(2);
    s. push(3);
    s. push(4);
    s. push(5);
   
    cout<<s.top()<<endl;
    s.print();
    cout<<endl;
    s.pop();
    s.print();

}