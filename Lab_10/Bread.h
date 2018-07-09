#ifndef BREAD_H
#define BREAD_H

#include "BakedGood.h"

class Bread : public BakedGood
{
	public:
		Bread(string variety = "Na");
		~Bread();
		virtual string ToString();
		virtual float GetDiscountedPrice();
	private:
		string variety;
};

#endif