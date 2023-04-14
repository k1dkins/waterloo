#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

	int selection = 1;

	switch (selection) {
	case 1: 
		std::cout << "Read" << std::endl;
		break;
	case 2:
		std::cout << "Write" << std::endl;
		break;
	default:
		std::cout << "Invalid selection" << std::endl;
	}

	std::cout << "You selected option " << selection << std::endl;

	/*

	// open file
	std::ifstream file ("list.txt");

	if ( file.is_open() ) {
		char ch;
		while ( file ) {
			ch = file.get();
			std::cout << ch;
		}
	} else {
		std::cout << "Couldn't open file\n";
	}
	
	*/

	return 0;
}