#include "stdafx.h"
#include "BakedGood.h"
#include <sstream>
#include <iomanip>

BakedGood::BakedGood()
{
}


BakedGood::~BakedGood()
{
}

string BakedGood::ToString()
{
	ostringstream priceAsString;
	priceAsString << setprecision(2) << fixed << price; //sets price precision to two decimal places
	return " ($" + priceAsString.str() + ")";
}
