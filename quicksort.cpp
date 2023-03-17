#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>&arr,int s,int e){
    int pivot=arr[e];
    int i=s-1;
    for(int j=s;j<=e;j++){
        if(arr[j]<pivot){
             i++;
            swap(arr[i],arr[j]);
        
        }
    }
    swap(arr[i+1],arr[e]);
    return i+1;
}



void quicksort(vector<int>&arr,int s,int e){
    if(s>=e){
        return;
    }

     int p= partition(arr,s,e);
    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);
}
int main(){
    vector<int> arr{5,6,2,7,4,28,1};
    int n=arr.size();
    quicksort(arr,0,n-1);
    for(auto x: arr){
        cout<<x<<",";
    }
}