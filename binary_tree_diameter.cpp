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
/*
 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
 1 2 3 4 5 -1 6 -1 -1  7 -1 -1 -1 -1 -1
 2 7 5 -1 6 -1 9 1 11 4 -1 -1 -1 -1 -1 -1 -1
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
//one way O(N^2)
int height(Node * root){
   if(root==NULL){
     return 0;
   }

   int h1=height(root->left);
   int h2=height(root->right);
   return max(h1,h2)+1;
}
int diameter(Node *root){
   if(root==NULL){
     return 0;
   }

   int leftd=diameter(root->left);
   int rightd=diameter(root->right);

   int leftheight=height(root->left);
   int rightheight=height(root->right);
   int selffiameter=leftheight+rightheight;

   return max(selffiameter,max(leftd,rightd));
}
//  5 4 8 11 -1 13 4 7 2 -1 -1 5 1 -1 -1 -1 -1 -1 -1 -1 -1
// optimized approach O(N)
class optidiamter{
public:
    int height;
    int diamter;
};

optidiamter diameter2(Node * root){
    optidiamter p;
    if(root==NULL){
       p.height=p.diamter=0;
       return p;
    }
    
    optidiamter left=diameter2(root->left);
    optidiamter right=diameter2(root->right);
    
    p.height=max(left.height,right.height)+1;
    int d1=left.height + right.height;
    int d2=left.diamter;
    int d3=right.diamter;
    p.diamter =max(d1,max(d2,d3));
    return p;
}



int main(){
   Node * root=levelorderbuild();
   cout<<diameter(root);
   cout<<endl;
   cout<<diameter2(root).diamter;
 }
