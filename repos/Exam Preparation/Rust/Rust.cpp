#include <iostream>
#include <array>
#include <list>
#include <string>
#include <sstream>

const int MATRIX_SIZE = 10;

static char matrix[MATRIX_SIZE][MATRIX_SIZE] = {};



void collectMatrixInput() {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        std::string input;
        getline(std::cin, input);
        std::stringstream str(input);

        char token = ' ';
        int j = 0;
        while (str >> token) {
            matrix[i][j] = token;
            j++;
        }
    }
}

bool canExpand(int i, int j) {
    if (i < MATRIX_SIZE &&
        j < MATRIX_SIZE &&
        i >= 0 &&
        j >= 0 &&
        matrix[i][j] != '#' &&
        matrix[i][j] != '!' ) {
        return true;
    }
    else return false;
}

void expandRust(int i, int j) {
    if (canExpand(i + 1, j)) matrix[i + 1][j] = '!';
    if (canExpand(i - 1, j)) matrix[i - 1][j] = '!';
    if (canExpand(i, j + 1)) matrix[i][j + 1] = '!';
    if (canExpand(i, j - 1)) matrix[i][j - 1] = '!';
}

void printMatrixOutput() {
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            std::cout << matrix[i][j];
        }
        std::cout << '\n';
    }
}

bool presentInCoordList(std::list <std::pair<int, int>>& coordinatesList, std::pair <int, int> &coordinates) {
    for (auto coord : coordinatesList) {
        if (coord == coordinates) return true;
    }
    return false;
}

void progressRustTurn(std::list <std::pair<int, int>> &coordinatesList) {
    
    std::list <std::pair<int, int>> newCoords;

    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            if (matrix[i][j] == '!') {
                std::pair <int, int> coordinates;
                coordinates.first = i;
                coordinates.second = j;
                if (presentInCoordList(coordinatesList, coordinates)) {
                    continue;
                }
                else newCoords.push_back(coordinates);
            }
        }
    }

    for (auto coord : newCoords) {
        expandRust(coord.first, coord.second);
        coordinatesList.push_back(coord);
    }
}



int main()
{
    collectMatrixInput();
 
    std::list <std::pair<int, int>> coordinatesList;

    int rustTurns = 0;
    std::cin >> rustTurns;
    for (int i = 0; i < rustTurns; i++) {
        progressRustTurn(coordinatesList);
        
    }

    printMatrixOutput();
}
