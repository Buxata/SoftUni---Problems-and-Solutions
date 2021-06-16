#include <iostream>
#include <vector>
#include <cmath>

std::vector<int> interpretLine(int cols) {
	std::vector <int> output;
	for (int i = 0; i < cols; i++) {
		int token;
		std::cin >> token;
		output.push_back(token);
	}
	return output;
}


int mainDiag(std::vector <std::vector<int>> arr) {
	int localSum = 0;
	int cols = arr[0].size(), rows = arr.size();
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			if (i == j) localSum += arr[i][j];
		}
	}
	return localSum;
}

int secondDiag (std::vector <std::vector<int>> arr) {
	int localSum = 0;
	int cols = arr[0].size(), rows = arr.size();
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			bool secondDiagChecker = (i + j) == arr.size() - 1;
			if (secondDiagChecker) localSum += arr[i][j];
		}
	}
	return localSum;
}
// 0  1  2  3
//-7 14 9 -20 x = 0 y = 3
// 3  4 9  21 x = 1 y = 2
//-14 6 8  44 x = 2 y = 1
// 30 9 7 -14 x = 3 y = 0


int main()
{
	std::vector <std::vector<int>> arr;

	int rows;
	std::cin >> rows;

	for (int i = 0; i < rows; i++) {
		arr.push_back(interpretLine(rows));
	}
	int result = abs(mainDiag(arr) - secondDiag(arr));
	
	std::cout << result;
}