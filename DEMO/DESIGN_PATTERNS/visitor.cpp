#include<iostream>

using namespace std;



class Product{

	
};

class Book:public Product{
	public:
		int get_cost(){return 10;}
};

class DVD: public Product{
	public:
		int get_cost(){return 20;}
	
};

class Tshirts::public Product{
	public:
		int get_cost(){return 50;}
};

