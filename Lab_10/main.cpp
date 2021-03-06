/*
Jordan Gruenewald, Test-Out, jorgruenewald@gmail.com

Test case 1: Testing Order Confirmation output and Bread discount
Input: "Bread White 3", "Bread Wheat 2", "Bread White 1", "done"
Expected output: 
	Order Confirmations: White bread ($4.50), White bread ($4.50), White bread ($4.50), Wheat bread ($4.50), White bread ($4.50)
	Invoice:
		White bread ($4.50) Quantity: 4 Total: 13.50
		Wheat bread ($4.50) Quantity: 2 Total: 9.00
		Totals Quantity: 6 Total: 22.50

Test case 2: Testing cream-cheese addition, and Cupcake discounts
Input: "Cupcake Chocolate cream-cheese red 1", "Cupcake Chocolate vanilla blue 1", "Cupcake Vanilla chocolate pink 2",
		"Cupcake Red-velvet vanilla red 4", "done"
Expected output:
	Order Confirmations: 
		Chocolate cupcake with cream-cheese frosting and red sprinkles ($2.15)
		Chocolate cupcake with vanilla frosting and blue sprinkles ($1.95)
		Vanilla cupcake with chocolate frosting and pink sprinkles ($1.95) x2
		Red-velvet cupcake with vanilla frosting and red sprinkles ($1.95) x4
	Invoice:
		Chocolate cupcake with cream-cheese frosting and red sprinkles ($2.15) Quantity: 1 Total: 2.15
		Chocolate cupcake with vanilla frosting and blue sprinkles ($1.95) Quantity: 1 Total: 1.95
		Vanilla cupcake with chocolate frosting and pink sprinkles ($1.95) Quantity 2: Total: 3.30
		Red-velvet cupcake with vanilla frosting and red sprinkles ($1.95) Quantity: 4 Total: 6.20
		Totals Quantity: 8 Total: 13.60

Test case 3: Testing additional pricing for cream-cheese and layers, and discount for 3 or more purchased
Input: "Layer-cake Vanilla cream-cheese 3 1", "Layer-cake Chocolate chocolate 1 4", "done"
Expected output:
	Order Confirmations:
		3-layer Vanilla cake with cream-cheese frosting ($18.00)
		1-layer Chocolate cake with chocolate frosting ($9.00) x4
	Invoice:
		3-layer Vanilla cake with cream-cheese frosting ($18.00) Quantity: 1 Total: 18.00
		1-layer Chocolate cake with chocolate frosting ($9.00) Quantity: 4 Total: 28.00
		Totals Quantity: 5 Total: 46.00
*/

#include "stdafx.h"
#include "Bread.h"
#include "CupCake.h"
#include "LayerCake.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <iterator>
#include <vector>
using namespace std;

float CalculateTotal(BakedGood* item, int quantity)
{
	float itemsTotal = 0.0;

	if (item->GetType() == "Bread")
	{
		for (int i = 0; i < quantity; i++)
		{
			float discountedPrice = item->GetDiscountedPrice(i + 1);
			itemsTotal += discountedPrice;
		}
	}
	else //Both Cupcake and Layer-cake will enter here
	{
		float discountedPrice = item->GetDiscountedPrice(quantity);

		for (int i = 0; i < quantity; i++)
		{
			itemsTotal += discountedPrice;
		}

	}
	
	return itemsTotal;
}

void AddOrIncrementItem(BakedGood* item, vector<BakedGood*> &uniqueGoods, vector<int> &itemQuantites)
{
	bool isUnique = true;

	if (uniqueGoods.size() > 0)
	{
		for (int i = 0; i < uniqueGoods.size(); i++)
		{
			if (item->ToString() == uniqueGoods.at(i)->ToString()) //if item is already on the list, increment count by 1
			{
				isUnique = false;
				itemQuantites.at(i) += 1;
			}
		}
	}

	if (isUnique)
	{
		uniqueGoods.push_back(item);
		itemQuantites.push_back(1);
	}
}

void PrintInvoice(vector<BakedGood*> &bakedGoods)
{
	vector<BakedGood*> uniqueGoods;
	vector<int> itemQuantites;
	float totalCost = 0.0;
	int totalQuantity = bakedGoods.size();

	for (int i = 0; i < bakedGoods.size(); i++)
	{
		AddOrIncrementItem(bakedGoods.at(i), uniqueGoods, itemQuantites);
	}

	cout << "Invoice:" << endl;

	//for formatting invoice properly into aligned columns
	int goodsColumnSize = 75;
	int quantityColumnSize = 9;
	int totalsColumnSize = 9;

	// "left"/"right" aligns text in column. "setw()" sets column width.
	cout << left << setw(goodsColumnSize) << "Baked Good";
	cout << right << setw(quantityColumnSize) << "Quantity";
	cout << right << setw(totalsColumnSize) << "Total" << endl;

	float itemsTotal;
	ostringstream itemsCostAsString;
	
	for (int j = 0; j < uniqueGoods.size(); j++)
	{
		itemsTotal = CalculateTotal(uniqueGoods.at(j), itemQuantites.at(j));
		itemsCostAsString << setprecision(2) << fixed << itemsTotal; //formats price to two decimal places
		totalCost += itemsTotal;

		cout << left << setw(goodsColumnSize) << uniqueGoods.at(j)->ToString();
		cout << right << setw(quantityColumnSize) << itemQuantites.at(j);
		cout << right << setw(totalsColumnSize) << itemsCostAsString.str();
		itemsCostAsString.str(""); //clears itemsCostAsString for next item
		cout << endl;
	}

	cout << left << setw(goodsColumnSize) << "Totals";
	cout << right << setw(quantityColumnSize) << totalQuantity;
	cout << right << setw(totalsColumnSize) << setprecision(2) << fixed << totalCost << endl;
}

void CreateOrder(string order, vector<BakedGood*> &bakedGoods)
{
	//splits up order string for parsing
	istringstream orderStream(order);
	vector<string> splitOrder((istream_iterator<string>(orderStream)), istream_iterator<string>());
	string goodType = splitOrder.at(0);
	int numOfGoods = stoi(splitOrder.at(splitOrder.size() - 1)); //gets number of goods at end of string

	for (int i = 0; i < numOfGoods; i++)
	{
		if (goodType == "Bread")
		{
			int varietyIndex = 1;
			string variety = splitOrder.at(varietyIndex);
			bakedGoods.push_back(new Bread(variety));
		}
		else if (goodType == "Cupcake")
		{
			int flavorIndex = 1;
			int frostingIndex = 2;
			int sprinkleIndex = 3;

			string flavor = splitOrder.at(flavorIndex);
			string frostingFlavor = splitOrder.at(frostingIndex);
			string sprinkleColor = splitOrder.at(sprinkleIndex);
			bakedGoods.push_back(new CupCake(flavor, frostingFlavor, sprinkleColor));
		}
		else if (goodType == "Layer-cake")
		{
			int flavorIndex = 1;
			int frostingIndex = 2;
			int layersIndex = 3;

			string flavor = splitOrder.at(flavorIndex);
			string frostingFlavor = splitOrder.at(frostingIndex);
			int numLayers = stoi(splitOrder.at(layersIndex));
			bakedGoods.push_back(new LayerCake(flavor, frostingFlavor, numLayers));
		}
	}
}

int main()
{
	cout << "**Bread and Cakes Bakery**" << endl << endl;

	vector<BakedGood*> bakedGoods;
	string order;
	cout << "Enter sub-order (enter \"done\" to finish)" << endl;

	do
	{
		cout << "Sub-order: ";
		getline(cin, order);

		if (order != "done")
		{
			CreateOrder(order, bakedGoods);
		}
	} while (order != "done");

	cout << endl << "Order Confiramtions:" << endl;
	for (int i = 0; i < bakedGoods.size(); i++)
		cout << bakedGoods.at(i)->ToString() << endl;

	cout << endl;
	PrintInvoice(bakedGoods);
	cout << "Good Bye" << endl;

	system("pause");
    return 0;
}

