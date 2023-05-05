#include<iostream>
using namespace std;

class list;
class Node{
     int data;
    
public:
     Node* next;
    Node(int d):data(d),next(NULL){}
    int getdata(){
        return data;
    }
    ~Node(){
        if(next!=NULL){
            delete next;
        }
        cout<<"delete  "<<data<<endl;
    }
    friend class list;
};

class list{
    Node * head;
    Node * tail;

    int helper(Node * start,int key){
        //bae case
        if(start==NULL){
            return -1;
        }
        
        if(start->data==key){
            return 0;
        }

        //rec case
        int subidx=helper(start->next,key);
        if(subidx==-1){
            return -1;
        }
        return subidx+1;

    }
public:
    list():head(NULL),tail(NULL){}
    Node * begin(){
        return head;
    }
    void push_front(int data){
        if(head==NULL){
            Node * n=new Node(data);
            head=tail=n;
        }
        else{
            Node * n=new Node(data);
            n->next=head;
            head=n;
        }
    }

    void push_back(int data){
        if(head==NULL){
            Node * n=new Node(data);
            head=tail=n;
        }
        else{
            Node * n=new Node(data);
            tail->next=n;
            tail=n;
        }
    }

    void insert(int data ,int posi){
        if(posi==0){
            push_front(data);
        }
        else{
            Node * temp=head;
            for(int jump=1;jump<=posi-1;jump++){
                temp=temp->next;
            }
            Node * n=new Node(data); 
            n->next=temp->next;
            temp->next=n;
        }
    }
    int search(int key){
        int idx=0;
        Node *temp=head;
        while(head!=NULL){
            if(temp->data==key){
                return idx;
            }
            idx++;
            temp=temp->next;
        }
        return -1;
    }
    int recsearch(int key){
        int idx=helper(head,key);
        return idx;
    }
  
    void pop_front(){
        Node * temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }

    void pop_back(){
        Node * temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        temp->next=NULL;
        delete tail;
        tail=temp;
    }
    void remove(int posi){
         if(posi==0){
            pop_front();
         }
         else{
            Node * temp=head;
            for(int jump=1;jump<=posi-1;jump++){
                temp=temp->next;
            }
            Node * n= temp->next;
            temp->next=n->next;
            n->next=NULL;
            delete n;
        }
    }
    // void reverselist(Node*head){
    //     Node *p=NULL;
    //     Node *c=head;
    //     Node *t;
    //     while(c!=NULL){
    //         t=c->next;
    //         c->next=p;
    //         p=c;
    //         c=t;
    //     }
    //     head=p;
    // }
    ~list(){
      if(head!=NULL){
        delete head;
        head=NULL;
      }
    }

};
