#pragma once


class Stock
{
private:
	char* _name = nullptr;
	Product** _products = nullptr; // dynamic array
	size_t _count = 0;
public:
	Stock() = default;


	Stock(const char* name) :Stock() { set_name(name); }


	void set_name(const char* name);


	Product* get_product_by_id(int id);


	void append(Product* product);


	void remove_by_id(int id);


	void clear();


	void print(); 


	~Stock()
	{
		delete[] _name;
		for (size_t i = 0; i < _count; i++)
		{
			delete _products[i];
		}
		delete[] _products;

		_products = nullptr;
		_name = nullptr;
	}
};


void Stock::set_name(const char* name) {
	if (name == nullptr)
		assert(!"Argument Does Not Accept Nullptr");

	if (_name != nullptr)
		delete[] _name;

	size_t len = strlen(name) + 1;
	_name = new char[len];
	strcpy_s(_name, len, name);
}


void Stock::print() {
	cout << "Stock Name: " << _name << endl;

	cout << "=========Products=========" << endl;
	for (size_t i = 0; i < _count; i++)
		_products[i]->print();
	cout << "=========THE  END=========" << endl;
}


Product* Stock::get_product_by_id(int id) {
	system("cls");
	for (size_t i = 0; i < _count; i++)
	{
		if (id == i) {
			return _products[i];
		}
	}
	assert(!"The ID Must Be At Least Zero And");
}


void Stock::append(Product* product) {
	if (product == nullptr)
		assert(!"Product Is nullptr");

	Product** temp = new Product * [_count + 1];
	for (size_t i = 0; i < _count; i++) {
		if (_products[i]->get_id() == product->get_id())
			assert(!"This ID Allready Exists");
		temp[i] = _products[i];
	}

	temp[_count++] = product;
	delete[] _products;
	_products = temp;
}


void Stock::clear() {
	delete[] _products;
	_count = 0;

	_products = nullptr;
}


void Stock::remove_by_id(int id) {
	Product** temp = new Product * [_count - 1];
	for (size_t i = 0; i < _count; i++)
	{
		if (i >= id)
			temp[i] = _products[i + 1];
		else
			temp[i] = _products[i];
	}

	_count--;
	delete[] _products;
	_products = temp;
}
