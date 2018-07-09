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
		string GetType();
	protected:
		float price;
		string goodType;
};

#endif