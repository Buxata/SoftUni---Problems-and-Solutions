#include <iostream>
#include <sstream>
#include <string>

const int INC_LENGTH = 3;
int inc[INC_LENGTH] = { -1, 0, 1 };

char** getArr(int &r, int &c) {
    std::string input;
    getline(std::cin, input);
    std::stringstream str(input);
    str >> r >> c;

    char** output = new char* [r];
    for (int i = 0; i < r; i++) {
        str.clear();
        getline(std::cin, input);
        str.str(input);
        char token;
        char* line = new char[c];
        for (int j = 0; j < c; j++) {
            str >> token;
            line[j] = token;
        }
        output[i] = line;
    }
    return output;
}

void addNumbers(int r, int c, int locR, int locC, int**& arr) {
    for (int i = 0; i < INC_LENGTH; i++) {
        for (int j = 0; j < INC_LENGTH; j++) {
            if (locR + inc[i] < r && locR + inc[i] >= 0 && locC + inc[j] < c && locC + inc[j] >= 0) {
                arr[locR + inc[i]][locC + inc[j]]++;
            }
        }
    }
}

void calculateMines(int r, int c, char**& mines, int**& arr) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if(mines[i][j]=='!') addNumbers(r, c, i, j, arr);
        }
    }
}

void print2dArr(int rows, int cols, int**& arr) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << arr[i][j];
        }
        std::cout << std::endl;
    }
}

int main()
{
    int rows = 0, columns = 0;
    auto minefield = getArr(rows, columns);

    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        int* line = new int[columns] {};
        arr[i] = line;
    }
    calculateMines(rows, columns, minefield, arr);

    print2dArr(rows, columns, arr);
    delete arr;
    delete minefield;
    arr = nullptr;
    minefield = nullptr;
}
