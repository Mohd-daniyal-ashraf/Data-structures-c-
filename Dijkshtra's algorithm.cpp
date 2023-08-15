#include<bits/stdc++.h>
using namespace std;



class graph{
    int V;
    list<pair<int,int>> *l;
public:
    graph(int v){
        V=v;
        l=new list<pair<int,int>> [v];
    }

    void addedge(int u,int v,int wt,bool both=true){
        l[u].push_back({wt,v});
        if(both){
            l[v].push_back({wt,u});
        }
    }


    int dijkstara(int src,int dest){
        vector<int> dist(V,INT_MAX);
        set<pair<int,int>> s;

        dist[src]=0;
        s.insert({0,src});

        while(!s.empty()){
            auto it=s.begin(); //give the front of set for further process

            int node=it->second;
            int distillnow=it->first;
            s.erase(it);

            //interate over the naighbor
            for(auto nbrpair:l[node]){

                 int nbr=nbrpair.second;
                 int currentdist=nbrpair.first;
                 if(distillnow+currentdist<dist[nbr]){
                    //remove if nbr already exist in the list of pair
                    auto f=s.find({dist[nbr],nbr});
                    if(f!=s.end()){
                        s.erase(f);
                    }
                    dist[nbr]=distillnow+currentdist;
                    s.insert({dist[nbr],nbr});
                 }
            }
        }
        for(int i=0;i<V;i++){
            cout<<i<<"->>"<<dist[i]<<endl;
        }
        return dist[dest];
    }
};
int main(){

    graph  g{5};  
    g.addedge(0,1,1); 
    g.addedge(1,2,1); 
    g.addedge(0,2,4); 
    g.addedge(0,3,7); 
    g.addedge(3,2,2); 
    g.addedge(3,4,3); 
    g.dijkstara(0,0);
    


}
