/*

  */

class vendingMachine{
	public:
	MoneyHandler
	FrontPanel *fp;
	Product

	vendingMachine():fp(new FrontPanle("Vending Machine is ready..."\n;))
};

class MoneyHandler{
	public:
		getCost(Product *p);
		isAmountRecieved()
		refundAmount()
};

class FrontPanle{
	public:
		display();
		getCoin();
		validateCoin();
		selectOption();

};


class ProductFactory{
	Product *p;
	public:
	Product* get_product(int pCode)
	{
		switch(pCode)
		{
			case 1:
				return new ProductA;
			case 2:
				return new ProductB;
			default:
				return 0;
		}
	}
};
class Product{
	public:
		makeProduct();
		getCost();
};

class ProductA:public Product{
	public:
	void makeProduct(){cout<<"Product A is being prepared...wait\n"; }
	int getCost(){return 20;}
};
class ProductB:public Product{
	public:
	void makeProduct(){cout<<"Product B is being prepared...wait\n"; }
	int getCost(){return 30;}
};
