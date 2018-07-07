#ifndef BAKEDGOOD_H
#define BAKEDGOOD_H

class BakedGood
{
	public:
		BakedGood();
		~BakedGood();
		virtual void ToString() = 0;
		virtual double GetDiscountedPrice(int) = 0;
	protected:
		double price;
};

#endif