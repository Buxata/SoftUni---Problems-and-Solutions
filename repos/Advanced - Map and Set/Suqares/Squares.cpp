#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <cmath>

bool checkIfSquare(int number) {

	long double x = number;

	// Find floating point value of  
	// square root of x. 

	long double sr = sqrt(x);
	// If square root is an integer 
	return ((sr - floor(sr)) == 0);
}

std::map <int, int> getSquareNumbersFrominput() {
	std::map <int, int> numbers;
	std::string input;
	getline(std::cin, input);

	std::stringstream str(input);
	int token;
	while (str >> token) {
		if (checkIfSquare(token)) numbers[token]++;
	}

	return numbers;
}

void printNumbers(std::map <int, int> &numbers) {
	for (auto it = numbers.rbegin(); it != numbers.rend(); it++) {
		for (size_t i = 0; i < it->second; i++)
		{
			std::cout << it->first << " ";
		}
	}
}

int main()
{
	std::map <int, int> numbers = getSquareNumbersFrominput();

	printNumbers(numbers);

}