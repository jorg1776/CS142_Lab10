#include "stdafx.h"
#include "Bread.h"

Bread::Bread(string variety)
{
	this->variety = variety;
}

Bread::~Bread()
{
}

string Bread::ToString() { return variety + " Bread"; }
