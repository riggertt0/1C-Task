#pragma once
#include "Teller.h"
#include "Admin.h"

class System {
private:
	const int teller_key = 1;
	const int admin_key = 2;
	const int close_key = 3;
public:
	void Start() {
		int custom_key = 0;
		std::string custom_key_str = "";
		std::cout << "Hello,\nenter \"1\" if you are a teller:\nenter \"2\" if you are an admin:\nenter \"3\" to close:\n";
		std::cin >> custom_key_str;
		custom_key = atoi(custom_key_str.c_str());
		if (custom_key == teller_key) {

			teller_manager.Work();
		}
		else if (custom_key == admin_key) {
			admin_manager.Work();
		}
		else  if (custom_key == close_key) {
			exit(0);
		} else {
			std::cout << "Bad number\n\n";
			return;
		}
	}
} system_;