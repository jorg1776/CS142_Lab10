#ifndef CUPCAKE_H
#define CUPCAKE_H

#include "Cake.h"

class CupCake : public Cake
{
	public:
		CupCake(string flavor = "Na", string frosting = "no", string sprinklesColor = "no");
		~CupCake();
		string ToString();
		virtual float GetDiscountedPrice();
	private:
		string sprinklesColor;
};

#endif