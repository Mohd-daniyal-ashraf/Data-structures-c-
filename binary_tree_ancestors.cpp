#include <bits/stdc++.h>
using namespace std;
struct Node {
    int   key;
    Node* left, *right;
    Node(int d){
      key=d;
      left=right=NULL;
    }
};

Node * levelorderbuild(){
   int d;
   cin>>d;
   Node * root=new Node(d);
   queue<Node*> q;
   q.push(root);
   while(!q.empty()){
       Node * current= q.front();
       q.pop();
       int c1,c2;
       cin>>c1>>c2;
       if(c1!=-1){
         current->left=new Node(c1);
         q.push(current->left);
       }
       if(c2!=-1){
         current->right=new Node(c2);
         q.push(current->right);
       }
   }
   return root;
}

// 1 2 3 4 5 -1 6 -1 -1 -1 -1 -1 -1
// 2 4 5 -1 -1 -1 -1 
//      50
//   60     70
// 90 40  3  20 
// -1 -1 -1 -1 -1 -1 -1 -1
//lowest common ancestor 
Node* lca(Node * root,int n1 ,int n2){
   if(root==NULL || root->key==n1 || root->key==n2){
     return root;
   }
   Node * leftlca =lca(root->left,n1,n2);
   Node * rightlca=lca(root->right,n1,n2);
    if(leftlca!=NULL && rightlca!=NULL){
         return root;
    }
    else if(leftlca==NULL)
      return rightlca;
    else if(rightlca==NULL) 
      return leftlca;
    else{
        return NULL;
    } 
}
//min destence of two node
int lcades(Node * root ,int n){
    if(root==NULL)return -1;
    if(root->key==n)return  0;
    int leftdes=lcades(root->left,n);
    int rightdes=lcades(root->right,n);
    if(leftdes==-1 && rightdes==-1)return -1;
    
    else if(leftdes==-1)return rightdes+1;
    else return leftdes+1;
}
int minDes(Node * root,int n1 ,int n2){
   Node * lcatemp=lca(root,n1,n2);
   int leftlenght =lcades(lcatemp,n1);
   int rightlenght=lcades(lcatemp,n2);
   return leftlenght+rightlenght;
}

//Kth ancester of node
int Kthancester(Node * root ,int n,int k){
    if(root==NULL){
        return -1;
    }
    if(root->key==n){
        return 0;
    }
    int leftdist=Kthancester(root->left,n,k);
    int rightdist=Kthancester(root->right,n,k);

    if(leftdist==-1 && rightdist==-1){
        return -1;
    }
     int m=max(leftdist,rightdist);
     if((m+1)==k){
        std::cout<< root->key;
     }
      return m+1;
     
}
/*
         2
     50    100
  60  -1  -1   70
90   40      3   20 
-1 -1  -1 -1 -1 -1 -1 -1

*/
int main(){
  Node * root=levelorderbuild();
//   int n1=90,n2=20;
//   Node * res=lca(root,n1,n2);
//   if(res==NULL || res->key==n1 || res->key==n2){
//      cout<<" Oops! Not found";
//   }
//   else{
//      cout<<" Found: "<<res->key;
//   }
//    cout<<minDes(root,n1,n2);
    int n=90,k=2;
    Kthancester(root,n,k);
 }