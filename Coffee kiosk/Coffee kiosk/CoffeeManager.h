#pragma once
#include <vector>

#include "Coffee.h"

class CoffeeManager {
public:
	void Show() {
		for (size_t i = 0; i < coffee_base.size(); ++i) {
			std::cout << coffee_base[i].GetName() << ' ' << coffee_base[i].GetPrice() << "$\n";
		}
		std::cout << '\n';
	}
} coffee_manager;