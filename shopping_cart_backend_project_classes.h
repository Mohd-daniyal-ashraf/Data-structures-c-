#include<string>
#include<unordered_map>
using namespace std;
class Item;
class Cart;

class Product{
    int id;
    string name;
    int price;

public:
    Product(){

   }
    Product(int U_id,string name,int price){
        U_id=id;
        this->name=name;
        this->price=price;
    }

   string getdisplayname(){
       return "\n"+name +" : Rs "+to_string(price);
   }
   string getshortname(){
       return name.substr(0,1);
   }
   friend class Item;
   friend class Cart;

};

class Item{
	Product product;
	int quantity;

public:
	//Constructor using a Init List
	Item(){}
	Item(Product p, int q):product(p), quantity(q){}

	int getItemprice(){
		return quantity * product.price;
	}
	string getIteminfo(){
		return to_string(quantity) + " x " + product.name + " Rs. " + to_string(quantity * product.price) + "\n";
	}

	friend class Cart;
};
	   

class Cart{
    unordered_map<int,Item> items;
public:
    void addproduct(Product product){
        if(items.count(product.id)==0){
            Item newItem(product,1);
            items[product.id]=newItem; 
        }
        else{
           items[product.id].quantity+=1;
        }
    }

    int gettotal(){
        int total=0;
        for(auto itempair:items){
            auto item=itempair.second;
            total+=item.getItemprice();
        }
        return total;
    }
   
	

    string viewCart(){
		if(items.empty()){
			return "Cart is empty";	
		}
		string itemizedList;
		int cart_total = gettotal();

		for(auto itemPair : items){
			auto item = itemPair.second;
			itemizedList.append(item.getIteminfo());
		}

		return itemizedList + "\n Total Amount : Rs. " + to_string(cart_total) + '\n';
	}
    

    bool isempty(){
        return items.empty();
    }
};



