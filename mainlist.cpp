#include<iostream>
#include "linkedlist.h"
using namespace std;

int main(){
    list l;
    l.push_front(11);
    l.push_front(20);
    l.push_back(23);
    l.push_back(13);
    l.insert(43,2);
    l.insert(10,0);
    // l.remove(2);
    l.pop_front();
    // l.search(4);
    l.pop_back();
    Node *head=l.begin();
    while(head!=NULL){
        cout<<head->getdata()<<"->";
        head=head->next;
    }
    cout<<endl;
    int key;

    // cin>>key;
    // cout<<l.search(key)<<endl;
    // cout<<l.recsearch(key);
    
}
/*
**************************************************************
                            SECOND WAY
**************************************************************
*/

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    return 0;
}
