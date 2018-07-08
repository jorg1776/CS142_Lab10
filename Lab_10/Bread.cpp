#include "stdafx.h"
#include "Bread.h"

Bread::Bread(string variety)
{
	this->variety = variety;
	price = 4.50;
}

Bread::~Bread()
{
}

string Bread::ToString() { return variety + " Bread " + BakedGood::ToString(); }
