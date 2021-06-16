#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <iterator>


std::vector<char> interpretLine() {
	std::vector <char> output;
	std::string input;
	getline(std::cin, input);
	std::stringstream str(input);

	char token;
	while (str >> token) {
		output.push_back(token);
	}
	return output;
}

std::vector <std::vector<char>> getMatrix() {
	std::vector <std::vector<char>> matrix;
	std::string input;
	getline(std::cin, input);
	std::stringstream str(input);
	int rows;
	str >> rows;
	for (int i = 0; i < rows; i++) {
		matrix.push_back(interpretLine());
	}

	return matrix;
}

int checkForSquare(const std::vector <std::vector<char>> &matrix) {
	int counter = 0;
	int xSize = matrix.size() - 1;
	int ySize = matrix[0].size() - 1;
	for (int i = 0; i < xSize; i++) {
		for (int j = 0; j < ySize; j++) {
			char c = matrix[i][j];
			if (c == matrix[i + 1][j] &&
				c == matrix[i][j + 1] &&
				c == matrix[i + 1][j + 1]) 
			{
				counter++;
			}
		}
	}
	return counter;
}

int main()
{
	auto arr = getMatrix();


	std::cout << checkForSquare(arr);
}
