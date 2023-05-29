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
// subtree of naother tree
bool issafe(Node * node , Node * root){
    if(!node && !root)
        return true;
    if(!node || !root || node->key!=root->key)
        return false;
     return issafe(node->left,root->left) && issafe(node->right,root->right);
}
bool equels(Node * root1 , Node * root2){
     if(!root1)
       return false;
      if(issafe(root1,root2))
         return true;
   return  equels(root1->left,root2) || equels(root1->right,root2);

}
// print all kth node 

void kthnode(Node * root ,int k,int level,set<int> &v){
    if(root==NULL){
       return ;
    }
    if(level==k){
       v.insert(root->key);
       return ;
    }
    kthnode(root->left,k,level+1,v);
    kthnode(root->right,k,level+1,v);
}
vector<int> print(Node * root,int k){
   set<int>res;
   kthnode(root,k,0,res);
   vector<int> v(res.begin(),res.end());
  
   return v;
}
// 1 2 3 4 5 -1 6 -1 -1 -1 -1 -1 -1
// 2 4 5 -1 -1 -1 -1 
// 50 60 70 90 40 40 20 -1 -1 -1 -1 -1 -1 -1 -1

int main(){
   Node * root1=levelorderbuild();
   Node * root2=levelorderbuild(); 
  //  if(equels(root1,root2)){
  //    cout<<"YES";
  //  }
  //  else{
  //    cout<<"NO";
  //  }
   vector<int> res=print(root1,2);
   for(auto x: res ){
      cout<<x<<" ";
   }
 }
