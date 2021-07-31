#include <iostream>
#include <string>
#include <cctype>

char* lowerCase(const std::string &input) {
	int size = input.size();
	char* output = new char [size+1] {};
	for (int i = 0; i < size; i++) {
		if (islower(input[i])) {
			output[i] = input[i];
		}
		else {
			output[i] = tolower(input[i]);
		}
	}
	output[size] = '\0';

	return output;
}

char* upperCase(const std::string& input) {
	int size = input.size();
	char* output = new char[size + 1]{};
	for (int i = 0; i < size; i++) {
		if (isupper(input[i])) {
			output[i] = input[i];
		}
		else {
			output[i] = toupper(input[i]);
		}
	}
	output[size] = '\0';

	return output;
}

void printCharArr(char*& arr) {
	int counter = 0;
	while (arr[counter] != '\0') {
		std::cout << arr[counter];
		counter++;
	}
}

int main()
{
	std::string input;
	getline(std::cin, input);

	char* lower = lowerCase(input);
	printCharArr(lower);
	std::cout << '\n';
	char* upper = upperCase(input);
	printCharArr(upper);
}
