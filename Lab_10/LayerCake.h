#ifndef LAYERCAKE_H
#define LAYERCAKE_H

#include "Cake.h"

class LayerCake : public Cake
{
	public:
		LayerCake();
		~LayerCake();
		virtual void ToString();
};

#endif