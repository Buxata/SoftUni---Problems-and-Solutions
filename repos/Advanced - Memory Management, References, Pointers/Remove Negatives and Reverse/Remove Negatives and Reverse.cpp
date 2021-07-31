#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

int getInputSize(const std::string& input) {
	std::stringstream str(input);
	int counter = 0;
	int token = 0;
	
	while (str >> token) {
		counter++;
	}
	return counter;
}

int* getArrFromInput(const std::string& input) {
	int* arr = new int[getInputSize(input)];
	std::stringstream str(input);
	int token = 0;
	int counter = 0;
	while (str >> token) {
		arr[counter] = token;
		counter++;
	}

	return arr;
}

int countNegativeNumbers(int size, int*& arr) {
	int counter = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] < 0) counter++;
	}
	return counter;
}

int* removeNegativeNumbers(int size, int*& arr) {
	int negativeNumbers = countNegativeNumbers(size, arr);
	int* positiveArr = new int[size - negativeNumbers];
	int counter = 0;

	for (int i = 0; i < size; i++) {
		if (arr[i] >= 0) {
			positiveArr[counter] = arr[i];
			counter++;
		}
	}

	return positiveArr;
}

int* reverseArr(int size, int*& arr) {
	int* reverse = new int[size];
	for (int i = 0; i < size; i++)
	{
		reverse[i] = arr[size - i - 1];

	}

	return reverse;
}


void dobiGetsASock(std::unordered_map <std::string, int*> elfDrawer) {
	for (auto elf : elfDrawer)
	{
		if (elf.second != nullptr) {
			delete elf.second;
			elf.second = nullptr;
		}
	}
}

void printArr(int size, int*& arr) {
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << ' ';
	}
}

int main()
{
	std::string input;
	getline(std::cin, input);

	std::unordered_map <std::string, int*> elfDrawer;

	int size = getInputSize(input);
	int* arr = getArrFromInput(input);
	elfDrawer["arr"] = arr;

	std::cout << arr;

	int positiveSize = size - countNegativeNumbers(size, arr);
	int* positiveArr = removeNegativeNumbers(size, arr);
	elfDrawer["positiveArr"] = positiveArr;

	int* reversePositiveArr = reverseArr(positiveSize, positiveArr);
	elfDrawer["revesrsePositiveArr"] = reversePositiveArr;
	
	if (positiveSize > 0) {

		printArr(positiveSize, reversePositiveArr);
	}
	else std::cout << "empty";

	dobiGetsASock(elfDrawer);
}