#ifndef LAYERCAKE_H
#define LAYERCAKE_H

#include "Cake.h"

class LayerCake : public Cake
{
	public:
		LayerCake(string flavor = "Na", string frosting = "no", int numLayers = 1);
		~LayerCake();
		virtual string ToString();
		virtual float GetDiscountedPrice(int quantity = 1);
	private:
		int layers;
};

#endif