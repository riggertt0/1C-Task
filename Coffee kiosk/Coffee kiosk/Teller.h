#pragma once
#include <map>

#include "CoffeeManager.h"
#include "Order.h"

class Teller {
private:
	std::string teller_name;
public:
	Teller(std::string teller_name_ = "name not specified") : teller_name(teller_name_) {}
	std::string GetName() { return teller_name; }
};

size_t shift_index = 0;
bool shift_open = false;

class CommandClass{
public:
	virtual bool Use(Teller* teller) {
		return true;
	}
};

class OpenClass : public CommandClass {
public:
	bool Use(Teller* teller) {
		shift_open = true;//
		coffee_manager.Show();
		return false;
	}
};

class CloseClass : public CommandClass {
public:
	bool Use(Teller* teller) {
		shift_open = false;
		shift_index++;
		return true;
	}
};

std::vector<Order> orders;

class SellClass : public CommandClass {
public:
	bool Use(Teller* teller) {
		if (shift_open == false) {
			std::cout << "Shift not open!\n";
			return false;
		}
		Order order(shift_index, teller->GetName());
		std::string coffee_name = "";
		std::cout << "Enter coffee type:\n";
		std::cin >> coffee_name;
		while (true) {
			std::cout << "Enter quantity:\n";
			std::string quantity_str = "0";
			std::cin >> quantity_str;
			int quantity = atoi(quantity_str.c_str());
			if (quantity == 0) {
				std::cout << "Bad coffee quantity\n";
				return false;
			}
			if (!order.AddCoffee(coffee_name, quantity))
			{
				std::cout << "Bad coffee name\n";
				return false;
			} 

			std::cout << "To order more coffee enter its type, else print \"..\" \n";
			std::cin >> coffee_name;
			if (coffee_name == "..")
				break;
		}
		orders.push_back(order);
		return false;
	}
};

class TellerManager {
private:
	std::map<std::string, Teller*> teller_base;
	std::map<std::string, CommandClass*> command_base;
public:
	TellerManager() {
		CommandInitialization();
	}

	void AddTeller(std::string teller_name) {
		if (teller_base[teller_name] == nullptr)
			teller_base[teller_name] = new Teller(teller_name);
	}

	void CommandInitialization() {
		command_base["Open"] = new OpenClass;
		command_base["Close"] = new CloseClass;
		command_base["Sell"] = new SellClass;
	}

	void Work() {
		std::string command;
		std::string name;
		std::cout << "Enter name:\n";
		std::cin >> name;
		if (teller_base[name] == nullptr) {
			std::cout << "Bad name\n";
			Work();
			return;
		}
		std::cout << "Instruction:\nEnter \"Open\" to open shift:\nEnter \"Close\" to close shift:\nEnter \"Sell\" to shop:";
		while (true) {
			std::cout << "Enter command:\n";
			std::cin >> command;
			if (command_base[command]) {
				if (command_base[command]->Use(teller_base[name])) {
					break;
				}
			}
			else {
				std::cout << "Bad command\n";
			}
		}
	}
} teller_manager;