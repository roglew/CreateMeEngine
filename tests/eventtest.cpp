#include "../src/objectevent.hpp"
#include <iostream>

void response()
{
	std::cout << "Responding\n";
}

int main(int argc, const char *argv[])
{
	bool trigger = false;

	ObjectEvent event(&trigger, response);

	std::cout << "Processing with trigger=false\n";
	event.process();

	std::cout << "Processing with trigger=true\n";
	trigger = true;
	event.process();
	return 0;
}

