#include<bits/stdc++.h>
using namespace std;

class ListNode{
public:
    ListNode* next;
    int val;
    ListNode(int v){
        val = v;
        next = nullptr;
    }
};
int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);       
    head->next->next = new ListNode(3); 
    head->next->next->next = new ListNode(4); 
    head->next->next->next->next = new ListNode(5); 
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }

}