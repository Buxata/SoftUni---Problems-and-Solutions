#include <iostream>
#include <vector>
#include <sstream>
#include <string>

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



int main()
{
	std::vector <std::vector<int>> arr1 = getMatrix();
	std::vector <std::vector<int>> arr2 = getMatrix();

	if (arr1 == arr2) std::cout << "equal";
	else std::cout << "not equal";

	return 1;
}
