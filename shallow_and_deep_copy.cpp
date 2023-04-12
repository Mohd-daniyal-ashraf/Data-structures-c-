#include<bits/stdc++.h>
using namespace std;

class  product{
private:
       int id;
       char *name;
       int mrp;
       int sellP;
public:

       product(){
		cout<<"Inside constructor";
	  }

       product(int id,char *n,int mer,int sellP){
            this->id=id;
            name=new char[strlen(n)+1];
            strcpy(name,n);
            this->mrp=mrp;
            this->sellP=sellP;
       }

	   /*if we are define an object dinamically then we 
	   have to defind our own copy Constructour ,this is shallow copy and deep copy of object 
	   id needed*/
      product(product &X){
		id = X.id;
		strcpy(name,X.name); //Array
		mrp = X.mrp;
		sellP = X.sellP;
	}
    
       void setid(int price){
            id=price;
       }

       void setmrp(int price){
            mrp=price;
       }
	   void setsellP(int price){
            sellP=price;
       }
       void setname(char *name){
            strcpy(this->name,name);
       }

       int getid(){
           return id;
       }
       int getmrp(){
           return mrp;
       }
       int getsellP(){
           return sellP;
       }
      
      void showDetails(){
		cout<<"Id : "<<id<<endl;
        cout<<"Name : "<<name<<endl;
		cout<<"MRP : "<<mrp <<endl;
        cout<<"SellP "<<sellP<<endl;
		cout<<"----------" <<endl;
	}
    
};


int main(){
    product apple(323,"HELLO",7473,65);
    product orange;
    orange=apple;
    orange.setname("lund");
    apple.showDetails();
    orange.showDetails();
    

 }


