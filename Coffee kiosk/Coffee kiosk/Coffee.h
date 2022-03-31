#pragma once
#include <string>

class AbstractCoffee {
private:
	std::string coffee_name;
	double price;
public:
	AbstractCoffee(std::string name = "error: Name not specified", double price_ = 0.0) : 
		coffee_name(name), price(price_) {}

	double GetPrice() { return price; }
	std::string GetName() { return coffee_name; }
};

class Cappuccino : public AbstractCoffee {
public:
	Cappuccino(std::string name = "Cappuccino", double price_ = 40.0) :
		AbstractCoffee(name, price_) {}
};

class Americano : public AbstractCoffee {
public:
	Americano(std::string name = "Americano", double price_ = 45.0) :
		AbstractCoffee(name, price_) {}
};

class Latte : public AbstractCoffee {
public:
	Latte(std::string name = "Latte", double price_ = 52.0) :
		AbstractCoffee(name, price_) {}
};

std::vector<AbstractCoffee> coffee_base{ Americano(), Cappuccino(), Latte()};