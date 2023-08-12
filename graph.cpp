#include<bits/stdc++.h>
using namespace std;

// //for integer node-->
// class graph{
//     int V;
//     list<int> *l;
// public:
//     graph(int v){
//         V=v;
//         l=new list<int> [V];
//     }

//     void addenge(int i,int j,bool both){
//         l[i].push_back(j);
//         if(both==false){
//             l[j].push_back(i);
//         }
//     }

//     void printdraph(){
//         for(int i=0;i<V;i++){
//             cout<<i<<"->";
//             for(auto node:l[i]){
//                 cout<<node<<" ";
//             }
//             cout<<endl;
//         }
//     }
// };

// class Node{

// public:
//     string name;
//     list<string> naber; 

//     Node(string name){
//         this->name=name;
//     }
// };

// class graph{
//     unordered_map<string,Node*> m;
// public:
//     graph(vector<string> cities){
//         for(auto city: cities){
//             m[city]=new Node(city); // make node of all cities 
//         }
//     }

//     void addedge(string &i,string &j){
//         m[i]->naber.push_back(j);  // make the edges
//         // if(dir){
//             // m[j]->naber.push_back(i);
//         // }
//     }

//     void printgraph(){
//         for(auto citypair:m){
//             string city=citypair.first;
//             cout<<city<<"->";
//             Node * node=citypair.second;
//             for(auto nbr:node->naber){
//                 cout<<nbr<<" ";
//             }
//             cout<<endl;
//         }
//     }
// };
template<typename T>

class graph{
    int V;
    unordered_map<T, list<T>> m;
public:
    graph(){
    }

    void addnode(T city){
        m[city];
    }

    void addedge(T x ,T y,bool both){
        m[x].push_back(y);
        if(both==true){
           m[y].push_back(x);
        }
    }

    void printgraph(){
        for(auto citypair:m){
            cout<<citypair.first<<"->";
            for(auto cities:citypair.second){
                cout<<cities<<" ";
            }
            cout<<endl;
        }
    }

};
/*
     0 -- 1
     | \  |
     2 -- 3

*/
int main(){

    graph <int> g;
    g.addnode(10);
    g.addnode(20);
    g.addnode(15);
    g.addnode(2);   
    g.addedge(10,15,false); //true mean there is only one direction from 0 to 1, not 1 to 0
    g.addedge(10,20,false);
    g.addedge(20,15,false);
    g.addedge(15,2,false);
    g.printgraph();
}