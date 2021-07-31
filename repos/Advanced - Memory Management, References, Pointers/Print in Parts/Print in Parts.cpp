#include <iostream>
#include <string>
#include <sstream>

void getCoords(int& a, int& b) {
    std::string input;
    getline(std::cin, input);

    std::stringstream str(input);
    str >> a >> b;
}

int** getArr(int &r,int &c) {
    std::stringstream str;
    std::string input;

	int** arr = new int* [r];
    for (int i = 0; i < r; i++) {
        int* line = new int[c] {};
        str.clear();
        getline(std::cin, input);
        str.str(input);
        int token = 0, counter = 0;
        while (str >> token) {
            line[counter] = token;
            counter++;
        }
        arr[i] = line;
    }
    
    return arr;
}

void print2dArr(int rows, int cols, int**& arr) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << arr[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

int main()
{
    int rows = 0, columns = 0;
    getCoords(rows, columns);
    int** arr = getArr(rows, columns);


    int a = 0, b = 0;
    getCoords(a, b);
    if (a <= rows && b <= columns) print2dArr(a, b, arr);
    else std::cout << "Print coordinates out of bounds";
}

