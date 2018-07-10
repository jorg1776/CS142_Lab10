#include "stdafx.h"
#include "CupCake.h"

CupCake::CupCake(string flavor, string frosting, string sprinklesColor)
{
	this->flavor = flavor;
	this->frosting = frosting;
	this->sprinklesColor = sprinklesColor;
	price = CUPCAKE_PRICE;

	if (frosting == "cream-cheese")
		price += COST_OF_CREAMCHEESE;

	goodType = "Cupcake";
}

CupCake::~CupCake()
{
}

string CupCake::ToString()
{
	return flavor + " cupcake with " + frosting + " frosting and " + sprinklesColor + " sprinkles " + BakedGood::ToString();
}

float CupCake::GetDiscountedPrice(int quantity)
{
	const float FOUR_OR_MORE_DISCOUNT = 0.40;
	const float TWO_OR_MORE_DISCOUNT = 0.30;
	float discount;

	if (quantity >= 4)
		discount = FOUR_OR_MORE_DISCOUNT;
	else if (quantity >= 2)
		discount = TWO_OR_MORE_DISCOUNT;
	else
		discount = 0.0;

	return price - discount;
}
