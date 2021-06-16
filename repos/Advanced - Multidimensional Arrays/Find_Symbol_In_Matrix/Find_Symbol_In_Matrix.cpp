#include <iostream>
#include <vector>
#include <sstream>
#include <string>

std::vector <std::vector<char>> get2DCharMatrix() {
    std::vector <std::vector<char>> output;
    std::vector <int> size;

    std::string sizeLine;
    getline(std::cin, sizeLine);
    std::stringstream str(sizeLine);
    sizeLine.clear();
    int token = 0;
    while (str >> token)
    {
        size.push_back(token);
    }
    for (int i = 0; i < size[0]; i++) {
        std::vector<char> charLine;
        std::string charLineInput;
        getline(std::cin, charLineInput);
        std::stringstream str(charLineInput);
        char token;
        while (str >> token)
        {
            charLine.push_back(token);
        }
        output.push_back(charLine);
    }
    return output;
}

bool matrix2DCharCheck(char check,
                       const std::vector <std::vector<char>> &matrix, 
                       int &x, int &y) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (check == matrix[i][j]) {
                x = i;
                y = j;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    auto matrix = get2DCharMatrix();

    int x = 0, y = 0;
    char token;
    std::cin >> token;
    if (matrix2DCharCheck(token, matrix, x, y)) {
        std::cout << '(' << x << ", " << y << ')';
    }
    else {
        std::cout << token << " does not occur in the matrix";
    }
}
