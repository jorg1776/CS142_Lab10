// Lab_10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BakedGood.h"
#include "Bread.h"
#include <iostream>
using namespace std;

int main()
{
	BakedGood* bread = new Bread("White");
	cout << bread->ToString() << endl;

	system("pause");
    return 0;
}

