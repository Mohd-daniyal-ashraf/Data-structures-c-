#include<bits/stdc++.h>
using namespace std;

int find(int x, vector<int>& parent) {
    if (x == parent[x]) {
        return x;
    }

    return parent[x] = find(parent[x], parent);
}
void union_(int x, int y, vector<int>& parent, vector<int>& rank) {
    int x_p = find(x, parent);
    int y_p = find(y, parent);

    if (x_p != y_p) {
        if (rank[x_p] > rank[y_p]) {
            parent[y_p] = x_p;
        } else if (rank[y_p] > rank[x_p]) {
            parent[x_p] = y_p;
        } else {
            parent[y_p] = x_p;
            rank[x_p]++;
        }
    }
}

int main(){


}