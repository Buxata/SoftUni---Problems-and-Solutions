#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <cctype>

std::set <std::string> getMessage() {
	std::string input;
	getline(std::cin, input);

	for (auto it = input.begin(); it != input.end(); it++) {
		if (ispunct(*it)) *it = ' ';
	}

	std::stringstream str(input);

	std::string token;
	std::set <std::string> output;
	while (str >> token)
	{
		output.insert(token);
	}

	return output;
}


bool readAndOutput(char token, const std::set <std::string>& words) {
	bool output = false;
	char tokenConv = ' ';
	if (islower(token)) tokenConv = toupper(token);
	if (isupper(token)) tokenConv = tolower(token);

	for (auto word : words) {
		for (auto it = word.begin(); it != word.end(); it++) {
			if (token == *it || tokenConv == *it) {
				std::cout << word << ' ';
				output = true;
				break;
			}
		}
	}

	return output;
}

int main()
{
	auto words = getMessage();

	char token;
	while (std::cin >> token && token != '.') {
		if (readAndOutput(token, words)) std::cout << '\n';
		else std::cout << "---" << '\n';
	}
}