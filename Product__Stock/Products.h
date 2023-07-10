#pragma once

class Product {
private:
    char* _name;
    char* _description;
    double _price;
    short _discount;
    int _id;
    static int static_id;

public:
    Product();
    Product(const char* name, const char* description, double price, short discount);

    // Get methods
    inline const char* GetName()const;
    inline const char* GetDescription()const;
    inline double GetPrice()const;
    inline short GetDiscount()const;
    inline int GetId()const;
    inline static int GetStatic_Id();

    // Set Methods
    void SetName(const char* name);
    void SetDescription(const char* description);
    void SetPrice(double price);
    void SetDiscount(short discount);

    double getDiscountPrice();
    void print();

    ~Product();
};

int Product::static_id = 1;

Product::Product() {
    _name = nullptr;
    _description = nullptr;
    _price = 0.0;
    _discount = 0;
    _id = static_id++;
}

void Product::SetName(const char* name) {
    if (this->_name != nullptr) {
        delete[] this->_name;
    }
    int len = strlen(name);
    this->_name = new char[len + 1];
    strcpy_s(_name, len + 1, name);
}

void Product::SetDescription(const char* description) {
    if (this->_description != nullptr) {
        delete[] this->_description;
    }
    int len = strlen(description);
    this->_description = new char[len + 1];
    strcpy_s(this->_description, len + 1, description);
}

void Product::SetPrice(double price) {
    this->_price = price;
}

void Product::SetDiscount(short discount) {
    if (discount >= 0 && discount <= 100) {
        this->_discount = discount;
        return;
    }
    assert(!"Incorrect discount!!");
}

Product::Product(const char* name, const char* description, double price, short discount) : Product() {
    SetName(name);
    SetDescription(description);
    SetPrice(price);
    SetDiscount(discount);
}

inline const char* Product::GetName()const {
    return this->_name;
}

inline const char* Product::GetDescription()const {
    return this->_description;
}

inline double Product::GetPrice()const {
    return this->_price;
}

inline short Product::GetDiscount()const {
    return this->_discount;
}

inline int Product::GetId()const {
    return this->_id;
}

inline int Product::GetStatic_Id() {
    return static_id;
}

double Product::getDiscountPrice() {
    double discount_Price = this->_price - (this->_price * this->_discount / 100);
    return discount_Price;
}

void Product::print() {
    cout << "-------------------------------------------------------------" << endl;
    cout << "\tID: " << _id << endl;
    cout << "Name: " << (_name != nullptr ? _name : "NULL") << endl;
    cout << "Description: " << (_description != nullptr ? _description : "NULL") << endl;
    cout << "Price: " << _price << "$" << endl;
    cout << "Discount: " << _discount << "%" << endl;
    cout << "-------------------------------------------------------------" << endl;
}

Product::~Product() {
    delete[] _name;
    delete[] _description;
}
