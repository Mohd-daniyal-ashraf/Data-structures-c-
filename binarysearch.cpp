#include<bits/stdc++.h>
using namespace std;

int helper(vector<int>arr,int key){
    int n=arr.size();
    int s=0;
    int e=n-1;
    while(s<=e){
        int mid=(s+e)/2;
        if(arr[mid]==key){
           return mid;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return -1;
}

// void binarysearch(vector<int>&arr,int key,int s,int e){
//      if(s>=e){
//         return ;
//      }
//      int mid=(s+e)/2;
//      binarysearch(arr,key,s,mid);
//      binarysearch(arr,key,mid+1,e);
//      return helper(arr,key,s,e);
// }
int main(){
    vector<int> arr{1,2,4,6,58,699};
    int s=0;
    int e=arr.size()-1;
    int key;
    cin>>key;
    int index=helper(arr,key);
    if(index!=-1){
        cout<<index;
    }
    else{
        cout<<"-1";
    }

}