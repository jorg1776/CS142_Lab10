#ifndef BREAD_H
#define BREAD_H

#include "BakedGood.h"

class Bread : public BakedGood
{
	public:
		Bread(string variety = "Na");
		~Bread();
		virtual string ToString();
		virtual float GetDiscountedPrice(int itemNumber = 1);
	private:
		string variety;
		const float BREAD_PRICE = 4.50;
};

#endif