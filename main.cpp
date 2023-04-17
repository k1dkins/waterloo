#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

char* getCurrentTime(){
	time_t now = time(0);
	char* date_time = ctime(&now);
	return date_time;
}

void readFile(std::ifstream &file, std::ofstream &log) {

	if ( file.is_open() && log.is_open() ) {
		char ch;
		while ( file ) {
			ch = file.get();
			std::cout << ch;
		}
		// logging
		char* time = getCurrentTime();
		std::string str = "\nSuccessfully wrote to file.";
		log << time << str;
	} else {
		// logging
		std::string str = "\nFailure, was not able to read from file.";
		log << time << str;
	}
	file.close();
}

int main(){

	// start time
	clock_t start = clock();

	std::ifstream file ("list.txt");
	std::ofstream log ("log.txt", std::ios::app);

	int selection = 1;

	switch (selection) {
	case 1: 
		std::cout << "Read" << std::endl;
		readFile(file, log);
		break;
	case 2:
		std::cout << "Write" << std::endl;
		break;
	default:
		std::cout << "Invalid selection" << std::endl;
	}

	std::cout << "You selected option " << selection << std::endl;

	// end time
	clock_t end = clock();
	double elapsed = double(end - start)/CLOCKS_PER_SEC;
	printf("Time: %.5f seconds.\n", elapsed);

	return 0;
}