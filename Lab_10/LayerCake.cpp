#include "stdafx.h"
#include "LayerCake.h"
#include <iostream>

LayerCake::LayerCake(string flavor, string frosting, int numLayers)
{
	this->flavor = flavor;
	this->frosting = frosting;
	this->layers = numLayers;
	price = 9.00;

	const float costOfCreamCheese = 1.00;
	if (frosting == "cream-cheese")
		price += costOfCreamCheese * numLayers;

	if (numLayers > 1)
	{
		const float costOfLayer = 3.00;

		for (int i = 2; i <= numLayers; i++)
		{
			price += costOfLayer;
		}
	}

	goodType = "Layer-cake";
}

LayerCake::~LayerCake()
{
}

string LayerCake::ToString()
{
	return to_string(layers) + "-layer " + flavor + " cake with " + frosting + " frosting " + BakedGood::ToString();
}
