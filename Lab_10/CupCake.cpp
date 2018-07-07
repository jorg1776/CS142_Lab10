#include "stdafx.h"
#include "CupCake.h"

CupCake::CupCake(string flavor, string frosting, string sprinklesColor)
{
	this->flavor = flavor;
	this->frosting = frosting;
	this->sprinklesColor = sprinklesColor;
}

CupCake::~CupCake()
{
}

string CupCake::ToString()
{
	return "CupCake";
}
