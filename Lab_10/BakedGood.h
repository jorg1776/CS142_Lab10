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
	protected:
		float price;
};

#endif