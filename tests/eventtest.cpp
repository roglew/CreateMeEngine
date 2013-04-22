#include "../src/objectevent.hpp"
#include <iostream>

void response()
{
	std::cout << "Responding\n";
}

void responsenum(int number)
{
	std::cout << "Number is: " << number << "\n";
}

int main(int argc, const char *argv[])
{
	bool trigger = false;
	ObjectEvent<> event(&trigger, response);
	ObjectEvent<int> eventarg(&trigger, responsenum);
	std::cout << "Processing with trigger=false\n";
	event.process();
	eventarg.process(5);
	std::cout << "Processing with trigger=true\n";
	trigger = true;
	event.process();
	eventarg.process(6);
	
	return 0;
}

