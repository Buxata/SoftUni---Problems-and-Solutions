#include <iostream>
#include <string>
#include <sstream>

bool equalityCheck(int**& arr, int size, int cols) {
    int r;
    std::cin >> r;
    if (size == r) {
        int token = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < cols; j++) {
                std::cin >> token;
                if (token != arr[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    else return false;
}

int getInputSize(std::string& input) {
    std::stringstream str(input);
    int counter = 0;
    int token = 0;

    while (str >> token) {
        counter++;
    }
    return counter;
}

int** getArray(int rows,int& cols) {

    int** arr = new int* [rows] {};

    for (int i = 0; i < rows; i++) {
        std::string input;
        getline(std::cin, input);
        int lineSize = getInputSize(input);
        cols = lineSize;

        std::stringstream str(input);
        int* line = new int[lineSize] {};
        int token = 0, counter = 0;
        while (str >> token) {
            line[counter] = token;
            counter++;
        }
        arr[i] = line;
    }

    std::cout.clear();
    return arr;

}

int main()
{
    int r = 0, c = 0;
    std::cin >> r;
    std::cin.ignore();

    int** arr = getArray(r,c);

    if (equalityCheck(arr, r, c)) std::cout << "equal";
    else std::cout << "not equal";


}