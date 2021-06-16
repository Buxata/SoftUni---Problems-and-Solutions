#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <iterator>

std::vector<int> interpretLine() {
	std::vector <int> output;
	std::string input;
	getline(std::cin, input);
	std::stringstream str(input);

	int token;
	while (str >> token) {
		output.push_back(token);
	}
	return output;
}

std::vector <std::vector<int>> getMatrix() {
	std::vector <std::vector<int>> matrix;
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

std::vector <std::string> checkPositionsOf(int compare, const std::vector <std::vector<int>> &matrix) {
	int xSize = matrix.size();
	int ySize = matrix[0].size();

	std::vector <std::string> output;
	for (size_t i = 0; i < xSize; i++)
	{
		for (size_t j = 0; j < ySize; j++)
		{
			if (matrix[i][j] == compare) {
				output.push_back(std::to_string(i) + " " + std::to_string(j));
			}
		}
	}
	return output;
}

void printStringVector(std::vector<std::string> arr) {
	if (arr.size() == 0) std::cout << "not found";
	else {
		auto end = arr.end();
		for (auto it = arr.begin(); it != end; it++) {
			std::cout << *it << std::endl;
		}
	}
}

int main()
{
	auto arr = getMatrix();

	int toCompare;
	std::cin >> toCompare;
	
	std::vector <std::string> positions = checkPositionsOf(toCompare ,arr);

	printStringVector(positions);

	return 1;
}
