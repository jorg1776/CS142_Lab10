#include "stdafx.h"
#include "CupCake.h"

CupCake::CupCake(string flavor, string frosting, string sprinklesColor)
{
	this->flavor = flavor;
	this->frosting = frosting;
	this->sprinklesColor = sprinklesColor;
	price = 1.95;
	if (frosting == "cream-cheese")
		price += 0.20;
}

CupCake::~CupCake()
{
}

string CupCake::ToString()
{
	return flavor + " cupcake with " + frosting + " frosting and " + sprinklesColor + " sprinkles " + BakedGood::ToString();
}
