#include<bits/stdc++.h>
using namespace std;

// helper method--->
void merge(vector<int> &array,int s,int e){
    int i=s;
    int m=(s+e)/2;
    int j=m+1;
    vector<int>temp;
    while(i<=m and j<=e){
        if(array[i]<array[j]){
            temp.push_back(array[i]);
            i++;
        }
        else{
            temp.push_back(array[j]);
            j++;
        }
    }
    //copy rem elements from first array-->
    while(i<=m){
        temp.push_back(array[i++]);
    }
    // or copy rem elements from second array-->
    while(j<=e){
        temp.push_back(array[j++]);
    }
    //copy back the eleemtns from temp to original array
    int k=0;
    for(int a=s;a<=e;a++){
        array[a]=temp[k++];
    }
    return;
}
//sorting method-->
void mergesort(vector<int> &array,int s,int e){
    if(s>=e){
        return;
    }
    int mid=(s+e)/2;
    mergesort(array,s,mid);
    mergesort(array,mid+1,e);
    return merge(array,s,e);
}

int main(){
    vector<int> array={6,4,-8,2,-1,8,-3,5};
    int s=0;
    int e=array.size()-1;
    mergesort(array,s,e);
    for(int b:array){
        cout<<b<<" ";
    }
}