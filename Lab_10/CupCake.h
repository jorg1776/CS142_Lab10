#ifndef CUPCAKE_H
#define CUPCAKE_H

#include "Cake.h"
#include <string>
using namespace std;

class CupCake : public Cake
{
	public:
		CupCake();
		~CupCake();
		string ToString();
};

#endif