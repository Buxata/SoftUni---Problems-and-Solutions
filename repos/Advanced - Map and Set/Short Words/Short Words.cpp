#include <iostream>
#include <sstream>
#include <string>
#include <set>

std::string toLower(std::string& input) {

    std::string wordConversion = input;
    for (int i = 0; i < wordConversion.size(); i++) {
        wordConversion[i] = std::tolower(wordConversion[i]);
    }

    return wordConversion;
}

std::set <std::string> fillWordsSet() {
    std::set <std::string> output;

    std::string input;
    getline(std::cin, input);

    std::stringstream str(input);
    std::string token;
    while (str >> token) {
        if(token.size() < 5) output.insert(toLower(token));
    }
    return output;
}

void printOutput(std::set <std::string>& words) {
    auto commaCounter = words.end();
    commaCounter--;
    for (auto it = words.begin(); it != words.end(); it++) {
        std::cout << *it;
        if (it != commaCounter) std::cout << ", ";
    }
}

int main()
{
    std::set <std::string> words = fillWordsSet();

    printOutput(words);
}
