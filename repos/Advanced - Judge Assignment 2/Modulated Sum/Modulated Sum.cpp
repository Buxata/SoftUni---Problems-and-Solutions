#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector <std::vector<int>> get2DMatrix() {
    std::vector <std::vector<int>> output;
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
        std::vector<int> intLine;
        while (str >> token) {
            intLine.push_back(token);
        }
        output.push_back(intLine);
    }
    return output;
}

std::vector <int> getColumnsMod(const std::vector <std::vector<int>>& matrix, int mod) {
    std::vector <int> output;
    output.reserve(matrix[0].size());
    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix[0].size(); j++)
        {
            if (output.size() <= j) output.push_back(0);
            output[j] += matrix[i][j];
        }
    }

    for (size_t i = 0; i < output.size(); i++)
    {
        output[i] = abs(output[i] % mod);
    }
    return output;
}

void printVector(std::vector <int> vec) {
    
    for (int el : vec)
    {
        std::cout << el << ' ';
    }
}

int main()
{
    auto matrix = get2DMatrix();
    int mod = 0;
    std::cin >> mod;
    auto colByMod = getColumnsMod(matrix, mod);
    printVector(colByMod);

    return 0;
}