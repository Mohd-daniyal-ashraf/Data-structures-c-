#include<bits/stdc++.h>
using namespace std;

class Node{
public:
   Node * left;
   Node * right;
   int data;
   Node(int d){
      data=d;
      left=right=NULL;
   }
};
Node * binarytree(){
   int d;
   cin>>d;
   if(d==-1){
      return NULL;
   }

   Node * n=new Node(d);
   n->left=binarytree();
   n->right=binarytree();
   return n;
}

void printpreorder(Node * root){
    if(root==NULL){
       return;
    }
    
    cout<<root->data<<" ";
    printpreorder(root->left);
    printpreorder(root->right); 
       
}

void printinorder(Node * root){
   if(root==NULL){
      return ;
   }
   printinorder(root->left);
   cout<<root->data<<" ";
   printinorder(root->right);
}

void printpostorder(Node * root){
   if(root==NULL){
      return ;
   }
   printpostorder(root->left);
   printpostorder(root->right);
   cout<<root->data<<" ";
}
 /*
 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
 
                         1
                        / \
                       /   \
                      2     3
                     / \     \
                    /   \     \
                   4     5     6
                         /
                        /
                       7  
 
 
 Preorder(Root,Left,Right)= 1 2 4 5 7 3 6
 Inorder(Left.Root,Righ)=   4 2 7 5 1 6 3
 Postorder(Left,Righ,Root)= 4 7 5 2 6 3 1
 */


int main(){
   Node * root=binarytree();
   printpreorder(root);
   cout<<endl;
   printinorder(root);
   cout<<endl;
   printpostorder(root);
}