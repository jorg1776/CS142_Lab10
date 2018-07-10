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
		const float LAYERCAKE_PRICE = 9.00;
		const float CREAMCHEESE_PRICE = 1.00;
		const float EXTRA_LAYER_PRICE = 3.00;
};

#endif