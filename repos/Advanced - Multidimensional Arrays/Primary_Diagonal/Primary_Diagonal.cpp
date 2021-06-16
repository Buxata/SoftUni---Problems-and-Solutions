#include <iostream>
#include <vector>



std::vector<int> interpretLine(int cols) {
	std::vector <int> output;
	for (int i = 0; i < cols; i++) {
		int token;
		std::cin >> token;
		output.push_back(token);
	}
	return output;
}

void printMaxColSum(const std::vector <std::vector<int>>& arr) {
	int maxSum = INT_MIN;
	int colIndex = 0;
	int cols = arr[0].size(), rows = arr.size();
	for (size_t i = 0; i < cols; i++)
	{
		int localSum = 0;
		for (size_t j = 0; j < rows; j++)
		{
			localSum += arr[j][i];
		}
		if (maxSum < localSum) {
			maxSum = localSum;
			colIndex = i;
		}
	}
	std::cout << colIndex;
}

int printMainDiag(std::vector <std::vector<int>> arr) {
	int localSum = 0;
	int cols = arr[0].size(), rows = arr.size();
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			if (i == j) localSum += arr[i][j];
		}
	}
	localSum;
}


int main()
{
	std::vector <std::vector<int>> arr;

	int rows;
	std::cin >> rows;

	for (int i = 0; i < rows; i++) {
		arr.push_back(interpretLine(rows));
	}

	std::cout << printMainDiag(arr);

}
