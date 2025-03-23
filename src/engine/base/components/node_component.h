#pragma once
#include <string>
#include "../component.h"


class name : public Component {
public:
	std::string GetName();

private:
	std::string name_;
};
