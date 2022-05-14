#include<iostream>
#include<cassert>
#include<iomanip>

using namespace std;

#include"Product.h"
#include"Stock.h"

int main() {

	Product* product = new Product("Iphone", "SE", 100, 10);
	Product* product1 = new Product("Iphone", "SE", 100, 10);
	Product* product2 = new Product("Iphone", "SE", 100, 10);
	Stock* stock = new Stock("CompTell");


	stock->append(product);
	stock->append(product1);
	stock->append(product2);

	//stock->remove_by_id(0);

	stock->print();

	delete stock;
}