#pragma once

class Order {
private:
	int shift_number;
	std::string teller_name;
public:
	std::map<std::string, int> order_list;

	Order(int number = 0, std::string name = "") : shift_number(number), teller_name(name) {}

	bool AddCoffee(std::string coffee_name, int value) {
		bool ok = false;
		for (size_t i = 0; i < coffee_base.size(); i++) {
			if (coffee_name == coffee_base[i].GetName())
			{
				ok = true;
				break;
			}
		}
		order_list[coffee_name] += value;
		return ok;
	}

	int GetNumb() { return shift_number; }
	std::string GetTellerName() { return teller_name; }
	void GetOrderInfo() {
		std::cout << "Shift number: " << GetNumb() << '\n';
		std::cout << "Teller's name: " << GetTellerName() << '\n';
		for (size_t i = 0; i < coffee_base.size(); i++) {
			std::cout << coffee_base[i].GetName() << ' ' << order_list[coffee_base[i].GetName()] <<"\n";
		}
		std::cout << '\n';
	}
};