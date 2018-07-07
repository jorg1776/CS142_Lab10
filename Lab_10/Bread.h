#ifndef BREAD_H
#define BREAD_H

#include "BakedGood.h"

class Bread : public BakedGood
{
	public:
		Bread();
		~Bread();
		virtual void ToString();
};

#endif