#ifndef HACK_INTERFACE_H
#define HACK_INTERFACE_H
#include "question.h"

class Interface {
private:
	Question question;
public:
	Interface() {
		question = Question();
	}
};
#endif
