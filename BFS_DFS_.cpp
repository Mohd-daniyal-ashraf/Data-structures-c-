#include<bits/stdc++.h>
using namespace std;

// BFS--->
// template<typename T>

// class graph{
//     unordered_map<T, list<T>> m;
// public:
//     graph(){
//     }
//     void addnode(T city){
//         m[city];
//     }
//     void addedge(T x ,T y,bool both){
//         m[x].push_back(y);
//         if(both==true){ 
//            m[y].push_back(x);
//         }
//     }

//     void bfs(T source){
//         queue<T>q;
//         unordered_map<T,bool> visited;  //store that node visited or not
        
//         q.push(source);//first as a sourse node
//         visited[source]=true;

//         while(!q.empty()){
//             int f=q.front();
//             cout<<f<<" ";
//             q.pop();
//             for(auto nbr:m[f]){ 
//                if(!visited[nbr]){
//                    q.push(nbr);
//                    visited[nbr]=true;
//                 }
//             }
//         }
//     }
// };

// DFS-->
template<typename T>

class graph{
    unordered_map<T,list<T>> m;
public:
    graph(){

    }
    void addnode(T city){
        m[city];
    }

    void addedge(T x,T y,bool both){
        m[x].push_back(y);
        if(!both){
           m[y].push_back(x); 
        }
    }
    
    void dfshelper(T node, unordered_map<T,bool> &visited){
        visited[node]=true;
        cout<<node<<" ";

        for(auto nbr: m[node]){
            if(!visited[nbr]){
                dfshelper(nbr,visited);
            }
        }
        return ;
    }
    void dfs(T source){
        unordered_map<T,bool> visited;
        dfshelper(source,visited);
    }

};
int main(){

    graph <int> g;
    g.addnode(9);
    g.addnode(1);
    g.addnode(2);
    g.addnode(3);
    g.addnode(4);
    g.addnode(5);
    g.addnode(6);
    
    g.addedge(0,1,false); //true mean there is only one direction from 0 to 1, not 1 to 0
    g.addedge(0,2,false);
    g.addedge(1,3,false);
    g.addedge(2,4,false);
    g.addedge(4,3,false);
    g.addedge(4,5,false);
    g.addedge(5,6,false);
    g.addedge(5,3,false);
    // g.bfs(0);
    g.dfs(0);
}
