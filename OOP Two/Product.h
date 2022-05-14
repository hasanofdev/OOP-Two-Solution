#pragma once

typedef unsigned short ushort;

class Product
{
private:
	static ushort static_id;
	ushort _id;
	char* _name = nullptr;
	char* _description = nullptr;
	double _price = 0;
	short _discount = 0;// 0-100%


public:
	Product() { _id = ++static_id; }


	Product(const char* name) :Product() { set_name(name); }


	Product(const char* name, const char* description) :Product(name) { set_description(description); }


	Product(const char* name, const char* description, double price) :Product(name, description) { set_price(price); }


	Product(const char* name, const char* description, double price, short discount) :Product(name, description, price) { set_discount(discount); }


	ushort get_id() { return _id; }


	const char* get_name() { return _name; }


	const char* get_description() { return _description; }


	double get_price() { return _price; }


	short get_discount() { return _discount; }


	double get_discount_price() { return _price - ((_price * _discount / 100)); }


	void set_name(const char* name);


	void set_description(const char* description);


	void set_price(double price);


	void set_discount(short discount);


	void print();


	~Product()
	{
		if (_description != nullptr)
			delete[] _description;
		if (_name != nullptr)
			delete[] _name;
	}
};


ushort Product::static_id = 0;


void Product::set_discount(short discount) {
	if (discount >= 0 && discount <= 100)
		_discount = discount;
	else
		assert(!"The İnterest Should Be Between Zero And One Hundred");
};


void Product::set_price(double price) {
	if (price < 0)
		assert(!"The Price Must Be At Least Zero");

	_price = price;
}


void Product::set_description(const char* description) {

	if (description == nullptr)
		assert(!"Argument Does Not Accept Nullptr");

	if (_description != nullptr)
		delete[] _description;

	size_t len = strlen(description) + 1;
	_description = new char[len];
	strcpy_s(_description, len, description);
}


void Product::set_name(const char* name) {
	if (name == nullptr)
		assert(!"Argument Does Not Accept Nullptr");

	if (_name != nullptr)
		delete[] _name;

	size_t len = strlen(name) + 1;
	_name = new char[len];
	strcpy_s(_name, len, name);
}


void Product::print() {
	cout << right << endl;
	cout << setw(17) << "ID: " << _id << endl;
	cout << setw(17) << "Product Name: " << (_name ? _name : "_NULL_") << endl;
	cout << setw(17) << "Description: " << (_description ? _description : "_NULL_") << endl;
	cout << setw(17) << "Price: " << _price << "$" << endl;
	cout << setw(17) << "Discount: " << _discount << endl << endl;
}