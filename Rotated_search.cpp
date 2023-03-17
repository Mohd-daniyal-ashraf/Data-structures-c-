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

        if(arr[s]<=arr[mid]){
            if(arr[s]<=key and arr[mid]>=key){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
      else{
        if(arr[mid]<=key and key<=arr[e]){
            s=mid+1;
        } 
        else{
            e=mid-1;
        }
      }
    }
    return -1;
}

int main(){
    vector<int> arr{4,5,6,7,0,1,2,3};
    int s=0;
    int e=arr.size()-1;
    int key;
    cin>>key;
    cout<<helper(arr,key);

} 