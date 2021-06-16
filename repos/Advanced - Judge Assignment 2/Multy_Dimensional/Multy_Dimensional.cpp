#include <iostream>
#include <string>
#include <sstream>
#include <vector>

std::vector <std::vector<char>> get2DMatrix() {
    std::vector <std::vector<char>> output;
    std::string lineInput;
    getline(std::cin, lineInput);

    std::stringstream str(lineInput);
    int token;
    std::vector<int> size2D;
    while (str >> token) {
        size2D.push_back(token);
    }
    for (int i = 0; i < size2D[0]; i++) {
        getline(std::cin, lineInput);
        str.clear();
        str.str(lineInput);
        char c;

        std::vector<char> intLine;
        while (str >> c) {
            intLine.push_back(c);
        }
        output.push_back(intLine);
    }
    return output;
}



void printMatrix(std::vector <std::vector<char>>& matrix) {
    int xLength = matrix.size();
    int yLength = matrix[0].size();
    for (size_t i = 0; i < xLength; i++)
    {
        for (size_t j = 0; j < yLength; j++)
        {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << "\n";

    }
}

void paintChar(char c, char change, int x, int y, std::vector <std::vector<char>>& matrix) {
    std::cout << "\n";
    printMatrix(matrix);
    
    std::cout << "\n";

    int xLength = matrix[0].size();
    int yLength = matrix.size();
    int x1 = x + 1 < xLength  ? x + 1 : x;
    int x2 = x - 1 >= 0 ? x - 1 : x;
    int y1 = y + 1 < yLength ? y + 1 : y;
    int y2 = y - 1 >= 0 ? y - 1 : y;
    matrix[x][y] = c;
    std::cout << "\nx,y = " << x << ", " << y << "\n";
    if (change == matrix[x1][y] && x1!=x)paintChar(c, change, x1, y, matrix);
    if (change == matrix[x2][y] && x2!=x)paintChar(c, change, x2, y, matrix);
    if (change == matrix[x][y1] && y1!=y)paintChar(c, change, x, y1, matrix);
    if (change == matrix[x][y2] && y2!=y)paintChar(c, change, x, y2, matrix);
}

void paintChar(char c, int x, int y, std::vector <std::vector<char>>& matrix) {
    std::cout << "\n";
    printMatrix(matrix);
    std::cout << "\n";

    int xLength = matrix[0].size();
    int yLength = matrix.size();
    char change = matrix[x][y];
    int x1 = x + 1 < xLength ? x + 1 : x;
    int x2 = x - 1 >= 0 ? x - 1 : x;
    int y1 = y + 1 < yLength ? y + 1 : y;
    int y2 = y - 1 >= 0 ? y - 1 : y;
    matrix[x][y] = c;
    if (change == matrix[x1][y] && x1 != x)paintChar(c, change, x1, y, matrix);
    if (change == matrix[x2][y] && x2 != x)paintChar(c, change, x2, y, matrix);
    if (change == matrix[x][y1] && y1 != y)paintChar(c, change, x, y1, matrix);
    if (change == matrix[x][y2] && y2 != y)paintChar(c, change, x, y2, matrix);

    
    
}


int main()
{
    auto matrix = get2DMatrix();

    char c;
    int x, y;
    std::cin >> c >> y >> x;

    paintChar(c, x, y, matrix);

    printMatrix(matrix);

    return 0;
}
