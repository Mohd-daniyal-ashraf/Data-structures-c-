#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Node{
public:
    int key;
    T value;
    Node * next;

    Node(int key,T value){
        this->key=key;
        this->value=value;
        next=nullptr;
    }
    ~Node(){
        if(next!=NULL){
            delete next;
        }
    }
};
template<typename T>
class MyHashMap{
    Node<T> ** table;
    int cs;
    int ts;
    int hashf(int key){
        return key%10;
    }
    void rehash(){
        Node<T> ** oldtable=table;
        int oldts=ts;
        ts=ts*2+1;
        table=new Node<T>*[ts];

        for(int i=0;i<ts;i++){
            table[i]=nullptr;
        }

        for(int i=0;i<oldts;i++){
            Node<T>* temp=oldtable[i];

            while(temp!=nullptr){
                int key=temp->key;
                T value=temp->value;
                insert(key,value);
                temp=temp->next;
            }
            if(oldtable[i]!=nullptr){
                delete oldtable[i];
            }
        }
        delete [] oldtable;
    }
public:
    MyHashMap(int default_size=7){
        cs=0;
        ts=default_size;
        table  = new Node <T> * [ts];
        for(int i=0;i<ts;i++){
            table[i]=nullptr;
        }
    }
    void insert(int key,int value){
        int idx=hashf(key);
        Node <T> * n=new Node<T>(key,value);
        n->next=table[idx];
        table[idx]=n;
        cs++;

        float load_factor=cs/(float) ts;
        if(load_factor>0.7){
            rehash();
        }
    }
    void print() {
        for (int i = 0; i < ts; i++) {
            std::cout << "bucket " << i << " : ";
            Node<T>* temp = table[i];
            while (temp != nullptr) {
                std::cout << "(" << temp->key << "," << temp->value << ") ";
                temp = temp->next;
            }
            std::cout << std::endl;
        }
    }
    int search(int key){
		int idx = hashf(key);

		Node<T> *temp = table[idx];

		while(temp!=NULL){
			if(temp->key == key){
				return temp->value;
			}
			temp = temp->next;
		}

		return -1;
	}
    void erase(int key) {
    int idx = hashf(key);

    Node<T>* prev = nullptr;
    Node<T>* current = table[idx];

    while (current != nullptr) {
        if (current->key == key) {
            if (prev != nullptr) {
                prev->next = current->next;
            } else {
                // If the node to be deleted is the first node in the bucket
                table[idx] = current->next;
            }
            current->next = nullptr; // Remove the link from the current node
            delete current; // Delete the node
            cs--; // Decrement the count of entries
            return; // Key found and deleted
        }
        prev = current;
        current = current->next;
    }
}

};

int main(){
    MyHashMap<int> h;
    h.insert(1,10);
    h.insert(2,20);    
    h.insert(3,30);
    h.erase(2);
    h.print();

}