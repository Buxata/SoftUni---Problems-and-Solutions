#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <cctype>

const int AMOUNT_OF_COLORS = 2;

std::string numberToHex(int number) {
	std::string initial;

	if (number == 0) initial = "00";
	else {
		while (number != 0) {
			int temp = number % 16;

			if (temp < 10) {

				char token = temp + '0';
				initial.insert(initial.begin(), token);
			}
			else {
				char token = temp + 'W';
				initial.insert(initial.begin(), token);
			}

			number = number / 16;
		}
	}
	return initial;
}


int charToDigit(char hex) {
	if (isdigit(hex))
	{
		return hex - '0';
	}
	else {
		return hex - 'W';
	}
}

std::string convertToHEX(std::map <std::string, int> color) {
	std::string output = "#";
	output += numberToHex(color["red"]);
	output += numberToHex(color["green"]);
	output += numberToHex(color["blue"]);

	return output;
}

void getSingleColor(int colorPicker, char& token, std::stringstream& str, std::map <std::string, int>& colorMap) {
	std::string color;
	switch (colorPicker)
	{
	case 1:
		color = "red";
		break;
	case 2:
		color = "green";
		break;
	case 3:
		color = "blue";
		break;
	default:
		break;
	}
	int colorVal = charToDigit(token) * 16;
	str >> token;
	colorVal += charToDigit(token);
	colorMap[color] = colorVal;
}

std::map <std::string, int> convertFromHEX(std::string input) {
	std::map <std::string, int> output;
	std::stringstream str(input);
	char token;
	int colorPicker = 0;
	while (str >> token)
	{
		if (token == '#') colorPicker = 0;
		else {
			colorPicker++;
			getSingleColor(colorPicker, token, str, output);
		}
	}
	return output;
}

std::map <std::string, int> calculateAverage (std::map <std::string, int> c1, std::map <std::string, int> c2) {
	std::map < std::string, int> average;

	average["red"] = (c1["red"] + c2["red"]) / AMOUNT_OF_COLORS;
	average["green"] = (c1["green"] + c2["green"]) / AMOUNT_OF_COLORS;
	average["blue"] = (c1["blue"] + c2["blue"]) / AMOUNT_OF_COLORS;
	
	return average;
}



void getInput(int amount, std::vector <std::string>& input) {
	for (int i = 0; i < amount; i++) {
		std::string token;
		std::cin >> token;
		input.push_back(token);
	}
}

int main()
{
	std::map <std::string, int> firsC, secondC, averageColor;
	std::vector <std::string> input;

	getInput(AMOUNT_OF_COLORS, input);

	firsC = convertFromHEX(input[0]);
	secondC = convertFromHEX(input[1]);

	averageColor = calculateAverage(firsC, secondC);

	std::cout << convertToHEX(averageColor);
}