#include "stdafx.h"
#include "LayerCake.h"
#include <iostream>

LayerCake::LayerCake(string flavor, string frosting, int numLayers)
{
	this->flavor = flavor;
	this->frosting = frosting;
	this->layers = numLayers;
	price = LAYERCAKE_PRICE;

	if (frosting == "cream-cheese")
		price += CREAMCHEESE_PRICE * numLayers;

	if (numLayers > 1)
	{
		for (int i = 2; i <= numLayers; i++)
		{
			price += EXTRA_LAYER_PRICE;
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

float LayerCake::GetDiscountedPrice(int quantity)
{
	const float THREE_OR_MORE_DISCOUNT = 2.00;
	float discount;

	if (quantity >= 3)
		discount = THREE_OR_MORE_DISCOUNT;
	else
		discount = 0;

	return price - discount;
}
