#include <iostream>
#include <map>
#include <string>
#include <sstream>


std::string getWords() {
    std::string input;
    getline(std::cin, input);


    for (int i = 0; i < input.size(); i++) {
        if (std::ispunct(input[i])) input[i] = ' ';
    }
    return input;
}

std::map <std::string, double>  getConditions() {
    std::map <std::string, double>  output;

    std::string input;
    getline(std::cin, input);

    std::stringstream str(input);
    std::string token;
    str >> token;
    double key;
    str >> key;

    key /= 100;

    output[token] = key;
    return output;
}

int main()
{
    std::string input = getWords();
    std::map <std::string, double>  conditions = getConditions();

    int counter = 0;

    std::stringstream str(input);
    std::string token;
    while (str >> token) {
        int similarity = 0;
        std::string temp = conditions.begin()->first;
        if (token.size() == temp.size()) {
            for (int i = 0; i < token.size(); i++) {
                if (token[i] == temp[i]) similarity++;
            }
        }
        double check = (double)similarity / (double)token.size();
        if (check > conditions[temp]) counter++;
    }

    std::cout << counter;
}
