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
int sumtree(Node * root){
  if(root==NULL)return 0;

   int leftsum=sumtree(root->left);
   int rightsum=sumtree(root->right);
   int data=root->key;
   int newleft=root->left==NULL ? 0 : root->left->key;
   int newright=root->right==NULL ? 0 : root->right->key;

   root->key= newleft+leftsum+newright+rightsum;
   return data;
}
/*     
          10
       1      11
    2   -1   -1    3
 4   5           6   7 
  -1 -1 -1 -1 -1 -1 -1 -1
*/
int preindex=0;
Node * build1(vector<int>&pre,vector<int>&ino,int Is,int Ie){
     if(Is>Ie)return NULL;
     Node * root=new Node(pre[preindex]);
     preindex++;
     int index=0;
     for(int i=Is;i<=Ie;i++){
        if(ino[i]==root->key){
           index=i;
           break;
        }
     }
     root->left=build1(pre,ino,Is,index-1);
     root->right=build1(pre,ino,index+1,Ie);
     return root;
}
// using postorder
//
vector<int>post={9,15,7,20,3};
int postindex=post.size()-1;
Node * buildd2(vector<int> &post,vector<int>&ino,int is,int ie){
   if(is>ie){
      return NULL;
   }
   Node * root=new Node(post[postindex]);
   postindex--;
   int index=0;
   for(int i=is;i<=ie;i++){
      if(ino[i]==root->key){
         index=i;
         break;
      }
   }
/*
   we have to calculate right first because postorder is l r R
   if last element of postorder is root then previous of last emement is 
    alsways is right  rode ,in postorder we have to traverse reverse  
                <-------
      l      r        R
     left   right     root
*/
   root->right=buildd2(post,ino,index+1,ie);
   root->left=buildd2(post,ino,is,index-1);
   return root;
   
}
 void preorder(Node * root){
   if(root==NULL){
    return ;
   }
   
   cout<<root->key<<" ";
   preorder(root->left); 
   preorder(root->right);
   
}
int main(){
  // Node * root=levelorderbuild();
  // sumtree(root);
  // preordr(root);
   vector<int> pre={3,9,20,15,7};
   vector<int> ino={9,3,15,20,7};
   Node * root1= build1(pre,ino,0,ino.size()-1);
   preorder(root1);
   Node * root2=buildd2(post,ino,0,ino.size()-1);
   cout<<endl;
   preorder(root2);
 }