#include "stdafx.h"
#include "LayerCake.h"
#include <iostream>

LayerCake::LayerCake(string flavor, string frosting, int numLayers)
{
	this->flavor = flavor;
	this->frosting = frosting;
	this->layers = numLayers;
	price = 9.00;

	if (frosting == "cream-cheese")
		price += 0.20;

	if (numLayers > 1)
	{
		for (int i = 2; i <= numLayers; i++)
		{
			price += 3.00;
		}
	}
}

LayerCake::~LayerCake()
{
}

string LayerCake::ToString()
{
	return to_string(layers) + "-layer " + flavor + " cake with " + frosting + " frosting " + BakedGood::ToString();
}
