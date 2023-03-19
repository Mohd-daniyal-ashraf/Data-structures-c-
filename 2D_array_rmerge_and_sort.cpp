#include<bits/stdc++.h>
using namespace std;


void merge_row(vector<vector<int>> &arr,int i,int cs,int cm,int ce){
    vector<int>temp;
    int x=cs;
    int y=cm+1;
    while(x<=cm and y<=ce){
        if(arr[i][x]<arr[i][y]){
           temp.push_back(arr[i][x]);
           x++;
        }
        else{
            temp.push_back(arr[i][y]);
            y++;
        }
    }
    while(x<=cm){
        temp.push_back(arr[i][x]);
           x++;
    }
    while(y<=ce){
        temp.push_back(arr[i][y]);
            y++;
    }

    int k=0;
    for(int j=cs;j<=ce;j++){
        arr[i][j]=temp[k];
        k++;
    }
    return;
}


void merge_col(vector<vector<int>>&arr,int j,int rs,int rm, int re){
    vector<int>temp;
    int x=rs;
    int y=rm+1;
    while(x<=rm and y<=re){
        if(arr[x][j]<arr[y][j]){
            temp.push_back(arr[x][j]);
            x++;
        }
        else{
            temp.push_back(arr[y][j]);
            y++;
        }
    }
    while(x<=rm){
        temp.push_back(arr[x][j]);
            x++;
    }
    while(y<=re){
        temp.push_back(arr[y][j]);
            y++;
    }
    int k=0;
    for(int i=rs;i<=re;i++){
        arr[i][j]=temp[k];
        k++;
    }
    return;
}


void merge(int m,int n,vector<vector<int>>&arr,int rs,int rm ,int re ,int cs ,int cm ,int ce){

    for(int i=rs;i<=re;i++){
        merge_row(arr,i,cs,cm,ce);
    }

    for(int j=cs;j<=ce;j++){
        merge_col(arr,j,rs,rm,re);
    }
}

 void merge_Sort(int m, int n, vector<vector<int>>&arr,int rs,int re,int cs ,int ce){
   if( rs>=re && cs>=ce){
       return;
   }
   int rm=(rs+re)/2;
   int cm=(cs+ce)/2;
    
   merge_Sort(m,n,arr,rs,rm,cs,cm);
   merge_Sort(m,n,arr,rm+1,re,cs,cm);
   merge_Sort(m,n,arr,rs,rm,cm+1,ce);
   merge_Sort(m,n,arr,rm+1,re,cm+1,ce);


    merge(m,n,arr,rs,rm,re,cs,cm,ce);
   return; 
}



vector<vector<int>> mergeSort(int m, int n, vector<vector<int>> v){
     merge_Sort(m,n,v,0,m-1,0,n-1);
    return v;
    
}

int main(){
    vector<vector<int>> arr={{18,4,16,8},
                             {23,13,20,11},
                             {28,24,26,25},
                           {1,30,15,19}};
    // int m=0;
    // int n=arr.size();
    int m;
    int n;
    vector<vector<int>>vect=mergeSort(m,n,arr);
    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect[i].size(); j++)
        {
            cout << vect[i][j] << " ";
        }    
        cout << endl;
    }
} 