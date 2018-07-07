#ifndef CAKE_H
#define CAKE_H

#include "BakedGood.h"

class Cake : public BakedGood
{
	public:
		Cake();
		~Cake();
		virtual void ToString() = 0;
};

#endif