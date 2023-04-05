#include<bits/stdc++.h>
using namespace std;
class product{
    int car_id;
    char car_name[100];
    int car_mrp;
    int car_sellP; 

public:
    // constructor
    product(){
        cout<<"this is constructor"<<endl;
    }
    //parameterized constructor
    product(int id,char *n,int mrp,int car_sellP){
          this->car_id=id;
          strcpy(car_name,n);
          this->car_mrp=mrp;
          this->car_sellP=car_sellP;
          
    }

    int setcar_mrp(int price){
        car_mrp=price;
    }
    int setcar_sellP(int price){
        car_sellP=price;
    }
    int getcar_mrp(){
          return car_mrp;
     }
    int getcar_sellP(){
        return car_sellP;
     }

};

int main(){
    product daniyal(111,"heelo",100,4445);
    
    cout<<daniyal.getcar_mrp()<<endl;
    cout<<daniyal.getcar_sellP()<<endl;
    
}

