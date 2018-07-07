#ifndef CAKE_H
#define CAKE_H

#include "BakedGood.h"

class Cake : public BakedGood
{
	public:
		Cake();
		~Cake();
		virtual string ToString() = 0;
	protected:
		string flavor;
		string frosting;
};

#endif