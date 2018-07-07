#ifndef BAKEDGOOD_H
#define BAKEDGOOD_H

#include <string>
using namespace std;

class BakedGood
{
	public:
		BakedGood();
		~BakedGood();
		virtual string ToString() = 0;
		//virtual double GetDiscountedPrice(int);
	protected:
		double price;
};

#endif