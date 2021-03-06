#ifndef CUPCAKE_H
#define CUPCAKE_H

#include "Cake.h"

class CupCake : public Cake
{
	public:
		CupCake(string flavor = "Na", string frosting = "no", string sprinklesColor = "no");
		~CupCake();
		virtual string ToString();
		virtual float GetDiscountedPrice(int quantity = 1);
	private:
		string sprinklesColor;
		const float CUPCAKE_PRICE = 1.95;
		const float COST_OF_CREAMCHEESE = 0.20;
};

#endif