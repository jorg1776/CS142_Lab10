#ifndef LAYERCAKE_H
#define LAYERCAKE_H

#include "Cake.h"

class LayerCake : public Cake
{
	public:
		LayerCake();
		~LayerCake();
		string ToString();
	private:
		int layers;
};

#endif