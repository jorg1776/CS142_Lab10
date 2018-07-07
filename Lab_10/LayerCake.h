#ifndef LAYERCAKE_H
#define LAYERCAKE_H

#include "Cake.h"

class LayerCake : public Cake
{
	public:
		LayerCake(string flavor = "Na", string frosting = "no", int numLayers = 1);
		~LayerCake();
		string ToString();
	private:
		int layers;
};

#endif