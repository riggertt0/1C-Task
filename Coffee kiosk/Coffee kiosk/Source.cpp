#include <iostream>
#include <string>

#include "CommandManager.h"

#include "Admin.h"

int main() {
	teller_manager.AddTeller("Alex");
	teller_manager.AddTeller("John");
	teller_manager.AddTeller("Jax");
	teller_manager.AddTeller("Merri");
	while (true) {
		system_.Start();
	}

	for (size_t i = 0; i < orders.size(); ++i) {
		orders[i].GetOrderInfo();
	}
}