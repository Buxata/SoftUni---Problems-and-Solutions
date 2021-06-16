#include <iostream>
#include <sstream>
#include <string>
#include <set>


std::set <int> fillNumbersSet() {
    std::set <int> output;

    std::string input;
    getline(std::cin, input);

    std::stringstream str(input);
    int token;
    while (str >> token) {
        output.insert(token);
    }
    return output;
}

void printSet(std::set <int> set) {
    auto topBound = set.end();
    topBound--;
    for (auto it = set.begin(); it != set.end(); it++) {
        std::cout << *it;
        if (it != topBound) std::cout << " <= ";
    }
}

int main()
{
    const auto numbers = fillNumbersSet();
    printSet(numbers);

}

