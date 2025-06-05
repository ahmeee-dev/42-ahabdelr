#include "iostream"
#include "string.h"



class Harl {
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

public:
	struct comandoAzione {
		const char *azione;
		void (Harl::*functionPtr)();
	};
	void complain(std::string level);
};