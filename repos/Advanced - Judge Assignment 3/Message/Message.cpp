#include <iostream>
#include <map>
#include <list>

void processInput(std::map <std::string, int>& words) {
    std::list <std::string> acceptedWords;

    int occurences, place;
    std::cin >> occurences >> place;

    for (auto word : words) {
        if (word.second == occurences) acceptedWords.push_back(word.first);
    }
    if (!acceptedWords.empty()) {
        acceptedWords.sort();
        auto wordForPrint = acceptedWords.begin();
        std::advance(wordForPrint, place);
        std::cout << *wordForPrint << std::endl;
    }
    else {
        acceptedWords.push_back(".");
        auto wordForPrint = acceptedWords.begin();
        std::cout << *wordForPrint << std::endl;
    }

}

int main()
{
    std::map <std::string, int> words;

    std::string token;
    while (std::cin >> token && token != ".") {
        words[token]++;
    }

    int inputTimes = 0;
    std::cin >> inputTimes;
    for (int i = 0; i < inputTimes; i++) {
        processInput(words);
    }
}
