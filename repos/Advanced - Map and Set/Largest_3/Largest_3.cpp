#include <iostream>
#include <sstream>
#include <string>
#include <set>

std::set <double> fillNumbersSet() {
    std::set <double> output;
    
    std::string input;
    getline(std::cin, input);

    std::stringstream str(input);
    double token;
    while (str >> token) {
        output.insert(token);
    }
    return output;
}

void printFirstThree(std::set <double> set) {
    auto lowBound = set.rbegin();
    for (int i = 0; i < 3; i++) {
        if (lowBound != set.rend())
        {
            lowBound++;
        }
    }
    for (auto it = set.rbegin(); it != lowBound; it++) {
        std::cout << *it << " ";
    }
}

int main()
{
    const auto numbers = fillNumbersSet();

    printFirstThree(numbers);
}
