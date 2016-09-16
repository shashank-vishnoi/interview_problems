/*
	Now a days merchant provides lot of options to pay the money like Debit card, credite card, net banking, COD etc.
	Customer can choose one of the provided payment methods to pay to seller.
   */
#include<iostream>

using namespace std;

class PaymentMethods{
	public:
		virtual int make_payment(int amount)=0; 
};
class DebitCard:public PaymentMethods{
	public:
		int make_payment(int amount)
		{
			cout<<"Debit card: payment is done for ....\n";
			return true;
		}
};
class CreditCard:public PaymentMethods{
	public:
		int make_payment(int amount)
		{
			cout<<"Credit card: payment is done for ....\n";
			return true;
		}
};

class MakePayment{
	public:
		PaymentMethods *method;
		MakePayment(PaymentMethods* m):method(m)
		{}
		void set_method(PaymentMethods* m)
		{
			method = m;
		}
		int make_payment(int amount)
		{
			return method->make_payment(amount);
		}
};


int main()
{
	MakePayment m1(new CreditCard);
	m1.make_payment(5000);
}
