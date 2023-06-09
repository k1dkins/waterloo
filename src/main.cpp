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
		int id = 0;
		std::string line;
		while ( file ) {
			std::getline(file, line);
			++id;
			std::cout << id << ": " << line << std::endl;
		}
		// logging
		char* time = getCurrentTime();
		std::string str = "Successfully wrote to file.";
		log << str << " " << time;
	} else {
		// logging
		std::string str = "Failure, was not able to read from file.";
		log << str << time;
	}
	file.close();
}

int main(){

	int selection;

	// start time
	clock_t start = clock();

	std::ifstream file ("../data/list.txt");
	std::ofstream log ("../data/logs/log.txt", std::ios::app);

	printf("Enter selection: ");
	scanf("%d", &selection);

	switch (selection) {
	case 1: 
		readFile(file, log);
		break;
	case 2:
		std::cout << "Write" << std::endl;
		break;
	default:
		std::cout << "Invalid selection" << std::endl;
	}

	// end time
	clock_t end = clock();
	double elapsed = double(end - start)/CLOCKS_PER_SEC;
	printf("\nTime: %.5f seconds.\n", elapsed);

	return 0;
}