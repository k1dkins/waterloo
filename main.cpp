#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

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
	
	return 0;
}