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

void printlevel(Node * root){
   queue<Node*> q;
   q.push(root);
   q.push(NULL);
   Node * r=q.front();
   while(!q.empty()){
      Node * temp=q.front();
      if(temp==NULL){
         cout<<endl;
         q.pop();
         if(!q.empty()){
            q.push(NULL);
         }
      }
      else{
         q.pop();
         cout<<"   "<<temp->data<<" ";
         if(temp->left){
            q.push(temp->left);
         }
         if(temp->right){
            q.push(temp->right);
         }
      }
   }
   



}
 /*
 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
 1 2 3 4 5 -1 6 -1 -1  7 -1 -1 -1 -1 -1
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
int height(Node * root){
    if(root==NULL){
       return 0;
    }
   int h1=height(root->left);
   int h2=height(root->right);
   return 1+max(h1,h2);
}

int main(){
   // Node * root=binarytree();
   Node * root=levelorderbuild();
   printlevel(root);
   cout<<endl;
   cout<<height(root);
   // printpreorder(root);
   // cout<<endl;
   // printinorder(root);
   // cout<<endl;
   // printpostorder(root);

}