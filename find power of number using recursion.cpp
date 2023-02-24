#include<bits/stdc++.h>
using namespace std;
//method1
int power1(int a,int n){
  if(n==0){
    return 1;
  }
  return a=a*power1(a,n-1);
}
//method2
int power2(int a,int n){
  if(n==0){
    return 1;
  }
  int subprob=power2(a,n/2);
  int subprobsqu=subprob*subprob;
  if(n&1==1){
    return a*subprobsqu;
  }
  return subprobsqu;
}
int main(){
   int a,n;
   cin>>a>>n;
  //  cout<<power1(a,n);
  cout<<power2(a,n);
}