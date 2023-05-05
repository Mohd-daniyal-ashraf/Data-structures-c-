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
