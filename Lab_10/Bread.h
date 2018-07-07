#ifndef BREAD_H
#define BREAD_H

#include "BakedGood.h"
#include <string>
using namespace std;

class Bread : public BakedGood
{
	public:
		Bread(string variety = "Na");
		~Bread();
		string ToString();
	private:
		string variety;
};

#endif