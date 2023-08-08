#include<bits/stdc++.h>
#include "Trie.h"

using namespace std;

int main(){
    string word[]={"hello","he","apple","aple","news"};
    trie t;
    for(auto ch:word){
        t.insert(ch);
    }
    cout<<"enter: ";
    string key;
    cin>>key;
    cout<<t.search(key);
}