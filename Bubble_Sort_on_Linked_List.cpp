#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    // Node(int d):data(d),next(NULL){}
    int getdata(){
        return data;
    }
    Node(int data){
		this->data = data;
		next = NULL;
	}
};
   

    Node * head1;
    Node * tail1;
    Node * head2;
    Node * tail2;

    // Node * begin1(){
    //     return head1;
    // }
    // Node * begin2(){
    //     return head2;
    // }
    void print(Node*head){
         while(head!=NULL){
         cout<<head->getdata()<<"->";
         head=head->next;
       }
    }

    void push_back1(int data){
        if(head1==NULL){
            Node * n=new Node(data);
            head1=tail1=n;

        }
        else{
            Node * n=new Node(data);
            tail1->next=n;
            tail1=n;
        }
    }

Node* bubble_sort_LinkedList_itr(Node* head)
{
    Node *temp=head;
    int len=1;
    int temp2;
    while(temp->next!=NULL){
         len++;
         temp=temp->next;
    }
     for(int i=0;i<len-1;i++){
        temp=head;
        for(int j=0;j<len-i-1;j++){
            if(temp->next!=NULL && temp->data>temp->next->data){
                 temp2=temp->data;
                 temp->data=temp->next->data;
                 temp->next->data=temp2;
            }
            temp=temp->next;
        }
     }
     return head;
}
int main(){
    push_back1(10);
    push_back1(30);
    push_back1(20);
    push_back1(5);    
    print(head1);
    cout<<endl;
    print(bubble_sort_LinkedList_itr(head1));
    
}