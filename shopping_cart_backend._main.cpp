#include<iostream>
#include<vector>
#include "shopping_cart_backend_project_classes.h"
using namespace std;
vector<Product> allproduct={
     Product(1,"apple",26 ),
     Product(3,"mango",16),
     Product(2,"guava",36),
     Product(5,"banana",56),
     Product(4,"strawberry",29),
     Product(6,"pineapple",20),
};
 
Product* chooseproduct(){
    string Productlist;
    cout<<"*************************************"<<endl;

    cout<<"Available product ";
    for(auto product:allproduct){
        Productlist.append(product.getdisplayname());
    }
    cout<<Productlist<<endl;
    cout<<"*************************************"<<endl;
    string choicse;
    cin>>choicse;
    for(int i=0;i<allproduct.size();i++){
        if(allproduct[i].getshortname()==choicse){
            return &allproduct[i];
        }
    }
    cout<<"Product not fount!"<<endl;
    return NULL;
}

bool checkout(Cart &cart){

    if(cart.isempty()){
        return false;
    }

    int total=cart.gettotal();
    cout<<"Pay in cash ";
    int paid;
    cin>>paid;
    if(paid>=total){
        if(paid-total>0){
             cout<<"Change "<<paid-total<<endl;
             cout<<"Successfully payed "<<endl;
             cout<<"Thank you for shopping! "<<endl;
        }
        else{
             cout<<"Successfully payed "<<endl;
             cout<<"Thank you for shopping! "<<endl;
        }
        return true;
    }
    else{
        cout<<"Not enough cash ";
        return false;
    }

}

int main(){
    char action;
    Cart cart;
    while(true){
        cout<<endl<<"Select an action -  (a)dd item, (v)iew cart, (c)heckout" <<endl;
        cin>>action;
        if(action=='a'){
             Product*product=chooseproduct();
             if(product!=NULL){
                cout<<"Aaded to cart "<<product->getdisplayname()<<endl;
                cart.addproduct(*product);
             }
        }
        
		
        else if(action=='v'){
              cout<<"*******************"<<endl;
              cout<<cart.viewCart();
              cout<<"*******************"<<endl;
        }
        else{
            cart.viewCart();
            if(checkout(cart)){
                break;
            }
        }
    }
}
