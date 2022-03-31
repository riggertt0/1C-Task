#pragma once
#include <stdlib.h>

class AdminManager {
private:

public:
	void Work() {
		std::cout << "Enter the cashier as the first argument, \nthe teller as the second \nand then all types of coffee separated by a space for which toy want to get information.\n";
		std::cout << "Put as the last argument \"..\"\n";
		std::cout << "If filtering by some argument is not needed, set \"-\"\n\n";
		std::string shift_number = "-";
		std::string teller_name = "-";
		std::string coffee_name;
		std::vector<std::string> coffee_type(1);
		std::cin >> shift_number >> teller_name >> coffee_type[0];
		std::cin >> coffee_name;
		coffee_type.push_back(coffee_name);
		while (coffee_type[coffee_type.size() - 1] != "..") {
			std::cin >> coffee_name;
			coffee_type.push_back(coffee_name);
		}

		for (size_t i = 0; i < orders.size(); ++i) {
			if (shift_number != "-" && atoi(shift_number.c_str()) != orders[i].GetNumb())
				continue;
			if (teller_name != "-" && teller_name != orders[i].GetTellerName())
				continue;
			if (coffee_type[0] == "-") {
				orders[i].GetOrderInfo();
				continue;
			}
			bool ok = true;
			for (size_t j = 0; j < coffee_type.size() - 1; ++j) {
				if (orders[i].order_list[coffee_type[j]] == 0) {
					ok = false;
					break;
				}
			}
			if (ok == false)
				continue;
			orders[i].GetOrderInfo();
		}
	}
	
} admin_manager;