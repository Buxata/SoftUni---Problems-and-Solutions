#include <iostream>
#include <string>
#include <sstream>

int getInputSize(std::string &input) {
	std::stringstream str(input);
	int counter = 0;
	int token = 0;

	while (str >> token) {
		counter++;
	}
	return counter;
}

int* getArrFromInput(std::string& input) {
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

void dobiGetsASock(int*& dynamic) {
	if(dynamic==nullptr)
	delete dynamic;
	dynamic == nullptr;
}

void gaussTrick(int size, int*& arr) {
	int halfSize = size / 2;
	bool isArrEvenSize = size % 2 == 0 ? true : false;

	for (int i = 0; i < halfSize; i++) {
		std::cout << arr[i] + arr[size-i-1] << " ";
	}
	if (!isArrEvenSize) std::cout << arr[halfSize];
}

int main()
{
	std::string input;
	getline(std::cin, input);

	int size = getInputSize(input);
	int* arr = getArrFromInput(input);

	gaussTrick(size, arr);

	dobiGetsASock(arr);
}
