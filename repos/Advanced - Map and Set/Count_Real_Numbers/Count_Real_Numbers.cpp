#include <iostream>
#include <sstream>
#include <string>
#include <map>

std::string getInput() {
    std::string output;
    getline(std::cin, output);

    return output;
}

void processOutput(std::map <double, int>& numbers) {
    for (const auto number : numbers) {
        std::cout << number.first << " -> " << number.second << std::endl;
    }
}

int main()
{
    std::string input = getInput();

    std::map <double, int> numbers;
    std::stringstream str(input);
    double token;
    while (str >> token) {
        if (numbers.find(token) != numbers.end()) numbers[token] ++;
        else numbers[token] = 1;
    }

    processOutput(numbers);
}