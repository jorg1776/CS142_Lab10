#include "stdafx.h"
#include "LayerCake.h"


LayerCake::LayerCake(string flavor, string frosting, int numLayers)
{
	this->flavor = flavor;
	this->frosting = frosting;
	this->layers = numLayers;
}

LayerCake::~LayerCake()
{
}

string LayerCake::ToString()
{
	return "LayerCake";
}
