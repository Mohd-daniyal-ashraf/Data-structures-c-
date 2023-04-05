#include<bits/stdc++.h>
using namespace std;
class product{
    char car_name[200];
    int car_id;
    int car_mrp;
    int car_sellP; 
public:
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
    product daniyal;
    daniyal.setcar_mrp(200);
    daniyal.setcar_sellP(10000);
    cout<<daniyal.getcar_mrp()<<endl;
    cout<<daniyal.getcar_sellP()<<endl;
    
}

