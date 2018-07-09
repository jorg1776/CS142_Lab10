#ifndef BAKEDGOOD_H
#define BAKEDGOOD_H

#include <string>
using namespace std;

class BakedGood
{
	public:
		BakedGood();
		~BakedGood();
		virtual string ToString();
		float GetPrice();
		virtual float GetDiscountedPrice() = 0;
		string GetType();
	protected:
		float price;
		string goodType;
};

#endif