#include<bits/stdc++.h>
using namespace std;

class Node{
    char data;
public:
    bool isterminal;
    unordered_map<char,Node*> m;
    Node(char d){
        data=d;
        isterminal=false;
    }
        // friend class trie;
};

class trie{
    Node*root;
public:
    trie(){
        root=new Node('\0');
    }

    void insert(string word){
        Node*temp=root;

        for(char ch:word){
            if(temp->m.count(ch)==0){
                Node* n=new Node(ch);
                temp->m[ch]=n;
            }
            temp=temp->m[ch];
        }
        temp->isterminal=true;
    }

    bool search(string word){
        Node *temp=root;
        for(char ch: word){
            if(temp->m.count(ch)==0){ //ch is not present at next of root
                return false;
            }
            temp=temp->m[ch];
        }
        return temp->isterminal;
    }
};