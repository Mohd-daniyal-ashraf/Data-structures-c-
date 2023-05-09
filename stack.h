#include <iostream>
using namespace std;

template<typename T>
class stack;

template<typename T>
class Node{
public:
   T data;
   Node <T> * next;
   int getdata(){
        return data;
    }
   Node(T data){
        this->data=data;
       next=NULL;
   }
};
template<typename T>
class stack{
    Node <T> * head;
public:
    
    stack(){
      head=NULL;
    }
    void push(T data){
         Node <T> * n=new Node<T>(data);
         n->next=head;
         head=n;
    }
    // Node * begin(){
    //     return head;
    // }
    int top(){
        return head->data;;
    }

    bool empty(){
        head=NULL;
    }

    void pop(){
        if(head!=NULL){
            Node<T> * temp=head;
            head=head->next;
            delete temp;
        }
    }
    void print(){
        Node<T> * temp;
        if(head==NULL){
            cout<<"stack overfloe";
        }
        else{
            temp=head;
            while(temp!=NULL){
                cout<<temp->data;
                temp=temp->next;
                if(temp!=NULL){
                    cout<<"-->";
                }
            }
        }
    }
};