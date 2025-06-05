#include "Harl.hpp"

void Harl::debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
void Harl::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}
void Harl::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
	static const Harl::comandoAzione tabella[] = {
		{"DEBUG", &Harl::debug},
		{"INFO", &Harl::info},
		{"WARNING", &Harl::warning},
		{"ERROR", &Harl::error}
	};
	int descriptor = 0;
	if (level == "DEBUG")
		descriptor = 0;
	else if (level == "INFO")
		descriptor = 1;
	else if (level == "WARNING")
		descriptor = 2;
	else if (level == "ERROR")
		descriptor = 3;
	switch (descriptor)
	{
	case 0:
		(this->*tabella[0].functionPtr)();
	case 1:
		(this->*tabella[1].functionPtr)();
	case 2:
		(this->*tabella[2].functionPtr)();
	case 3:
		(this->*(tabella[3].functionPtr))();
		break;
	}
}
