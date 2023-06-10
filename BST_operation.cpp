#include<bits/stdc++.h>
using namespace std;
 
class Node{
public:
     int key;
     Node * left;
     Node * right;
    Node(int key){
       this->key=key;
       left=right=NULL;
    }
}; 

Node * buildBST(Node * root,int key){
   if(root==NULL)return new Node(key);
     
   if(key < root->key)
     root->left= buildBST(root->left,key);
   else
     root->right= buildBST(root->right,key);
   return root;
} 
bool search(Node * root,int key){
   if(root==NULL)
      return false;
  
   if(key==root->key)
       return true;
   if(key < root->key)
       return search(root->left,key);
   else
      return  search(root->right,key); 
}      


void inorder(Node * root){
    if(root==NULL)return;

    inorder(root->left);
    cout<< root->key<<" ";
    inorder(root->right);              
}

Node * minnode(Node * root){
   while(root->right!=NULL){
      root=root->right;
   }
   return root;
}
Node * deletenode(Node * root,int key){
    if(root==NULL) return NULL;

    if(key < root->key){
        root->left=deletenode(root->left,key);
    }
    else if(key > root->key){
       root->right=deletenode(root->right,key);
    }
    else{
        //there may be three cases 
        //1--> 0 child
        if(root->left==NULL && root->right==NULL){
           delete root;
           root=NULL;
        }
        //2--> 1 child
        else if(root->left==NULL){
           Node * temp=root;
           root=root->right;
           delete temp;
        }
        else if(root->right==NULL){
           Node * temp=root;
           root=root->left;
           delete temp;
        }
        //3--> 2 children
        else{
           Node * temp=minnode(root->right);
           root->key=temp->key;
           root->right=deletenode(root->right,temp->key);
        }
    }
    return root;
}
 
void findrange(Node * root,int n1,int n2){
    if(root==NULL)
       return;
    
    if(n1<root->key and root->key<n2){
       cout<<root->key<<" ";
       findrange(root->left,n1,n2);
       findrange(root->right,n1,n2);
    }
    
    else if(root->key<n1){
       findrange(root->right,n1,n2);
    }
    else{
       findrange(root->left,n1,n2);
    }
}
   vector<vector<int>>res;
void roottoleaf(Node * root,vector<int>&res){  
    if(root==NULL) return  ;
    
    res.push_back(root->key);
    if(root->left==NULL and root->right==NULL){
       for(auto x: res){
         cout<<x<<" ";
       }
       cout<<endl;
    }    
    if(root->left)roottoleaf(root->left,res);
    if(root->right)roottoleaf(root->right,res);
    res.pop_back();
    return ;
}
/* 
     8,3,10,1,6,14,7,4,13
            8
        3       10
    2     6        14
        4   7    13

    8 3 6 7
*/

int main(){
  Node * root=NULL;
  int arr[]={8,3,10,1,6,14,7,4,13};
  for(auto x:arr)
     root=buildBST(root,x);
   //   inorder(root);
  //  int k=0;
  //  if(search(root,k)==true)cout<<endl<<"YES";
  //  else cout<<endl<<"NO";
  //  deletenode(root,k);
//   findrange(root,0,588);
   vector<int>v1;
   roottoleaf(root,v1);
}