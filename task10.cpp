#include <iostream>
#include <fstream>
#include <string>
#include <vector>


int main ()
{
	std::ofstream output ("ListOfNames.txt");
	if (!output.is_open()) {
		std::cout << "Invalid file";
		return 0;
	}

	std::vector<std::string> names = {"Mark", "Hayk", "Sona", "Ashot", "Nea", "Mia"};
	for (const std::string& n : names) {
		output << n << std::endl;
	}

	output.close();
	std::string str;
	std::ifstream input ("ListOfNames.txt");
	if (!input.is_open()) {
		std::cout << "Invalid file";
		return 0;
	}

	std::cout << "here are the names you inputed" << std::endl;
	while (std::getline (input, str)) {
		std::cout << str << " ";
	}

	input.close();

}
