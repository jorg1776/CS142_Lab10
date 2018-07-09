#include "stdafx.h"
#include "Bread.h"

Bread::Bread(string variety)
{
	this->variety = variety;
	price = 4.50;
	goodType = "Bread";
}

Bread::~Bread()
{
}

string Bread::ToString() { return variety + " Bread " + BakedGood::ToString(); }

float Bread::GetDiscountedPrice(int itemNumber)
{
	if (itemNumber % 3 == 0)
		return 0.0;
	else
		return price;
}
