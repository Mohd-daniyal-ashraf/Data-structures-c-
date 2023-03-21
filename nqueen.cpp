#include<bits/stdc++.h>
using namespace std;

bool canplace(int board[][20],int n,int x,int y){
     //column
     for(int k=0;k<n;k++){
        if(board[k][y]==1){
            return false;
        }
     }

     //left digonal
     int i=x;
     int j=y;
     while(i>=0 and j>=0){
        if(board[i][j]==1){
            return false;
        }
        i--,j--;
     }

     //rigth digonal
      i=x;
      j=y;
     while(i>=0 and j<n){
         if(board[i][j]==1){
            return false;
         }
        i--,j++;
     }

     return true;
}


void print(int board[][20],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int  nqueen(int board[][20],int n,int i){
    //base case
    if(i==n){
        print(board,n);
        return true;
    }

    int ways=0;
    for(int j=0;j<n;j++){
        if(canplace(board,n,i,j)){ // check can place or not
            board[i][j]=1;
            //for printiong all possiable nqueen
            ways+=nqueen(board,n,i+1);
            //backtrack
            board[i][j]=0;
        }
    }
    return ways;
}




int main(){
   int board[20][20]={0};
   int n;
   cin>>n;
   nqueen(board,n,0);
   return 0;
 }