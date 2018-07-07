#ifndef CUPCAKE_H
#define CUPCAKE_H

#include "Cake.h"

class CupCake : public Cake
{
	public:
		CupCake();
		~CupCake();
		virtual void ToString();
};

#endif