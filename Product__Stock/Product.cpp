#include <iostream>
#include <cassert>

using namespace std;

#include"Products.h"
#include"Stock.h"

int main() {
    Product** products = new Product * [3];

    products[0] = new Product("Product 1", "Description 1", 10.0, 20);
    products[1] = new Product("Product 2", "Description 2", 15.0, 10);
    products[2] = new Product("Product 3", "Description 3", 20.0, 5);

    Stock stock("My Stock", products, 3);

    stock.print();
    stock.PrintDiscountedPrices();


    return 0;
}