#pragma once

class Stock {
private:
	char* _name = nullptr;
	Product** _products = nullptr;
	size_t _count = 0;

public:
	Stock() = delete;
	Stock(const char* name, Product**& products, size_t count);

	void SetName(const char* name);
	void SetProducts(Product**& products, size_t count);

	inline const char* GetName();
	inline Product** GetProducts();
	inline size_t GetCount();

	void Clear();
	Product* getProductById(int id);
	void PrintDiscountedPrices();

	void print();

	~Stock();

};

void Stock::SetName(const char* name) {
	if (this->_name != nullptr) {
		delete[] this->_name;
	}
	int len = strlen(name);
	this->_name = new char[len + 1];
	strcpy_s(this->_name, len + 1, name);
}

void Stock::SetProducts(Product**& products, size_t count) {
	_products = new Product * [count];
	for (int i = 0; i < count; i++) {
		_products[i] = new Product(products[i]->GetName(), products[i]->GetDescription(), products[i]->GetPrice(), products[i]->GetDiscount());
	}
	_count = count;
}

Stock::Stock(const char* name, Product**& products, size_t count) {
	SetName(name);
	SetProducts(products, count);
}

inline const char* Stock::GetName() {
	return _name;
}

inline Product** Stock::GetProducts() {
	return _products;
}

inline size_t Stock::GetCount() {
	return _count;
}

void Stock::PrintDiscountedPrices() {
	for (size_t i = 0; i < _count; i++) {
		double discountedPrice = _products[i]->getDiscountPrice();
		cout << "Product ID: " << _products[i]->GetId() << " ==> " << discountedPrice << "$" << endl;
	}
}

void Stock::Clear() {
	for (int i = 0; i < _count; i++) {
		delete _products[i];
	}
	delete[] _products;
	_products = NULL;
	_count = 0;
}

Product* Stock::getProductById(int id) {
	for (int i = 0; i < _count; i++) {
		if (id == _products[i]->GetId()) {
			return _products[i];
		}
	}
	return nullptr;
}

void Stock::print() {
	cout << "\tStock Info" << endl;
	cout << "==============================================" << endl;
	cout << "\tName: " << this->_name << endl;
	cout << "==============================================" << endl;
	cout << "\tAll Products" << endl;
	for (int i = 0; i < _count; i++) {
		_products[i]->print();
	}
}

Stock::~Stock() {
	delete[]_name;
	if (_products != NULL) {
		this->Clear();
	}
}
