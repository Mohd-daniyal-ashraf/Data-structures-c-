#include<bits/stdc++.h>
using namespace std;
class product{

    char car_name[200];
    int car_id;
public:
    int car_mrp;
    int car_sellP; 
};

int main(){
    product daniyal;
    //cout<<daniyal.car_id;  can not access private members
    daniyal.car_mrp=20000;
    cout<<daniyal.car_mrp;

}

