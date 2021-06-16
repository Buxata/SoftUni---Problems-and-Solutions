#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <deque>

std::string toLower(std::string& input) {

    std::string wordConversion = input;
    for (int i = 0; i < wordConversion.size(); i++) {
        wordConversion[i] = std::tolower(wordConversion[i]);
    }

    return wordConversion;
}

std::string getInput() {
    std::string initial;
    getline(std::cin, initial);

    std::stringstream str(initial);
    std::string token;

    std::string output = "";
    while (str >> token) {
        output += toLower(token);
        output += " ";
    }

    return output;
}

bool checkExists(std::deque <std::string> &v, std::string &check) {
    for (auto word : v) {
        if (word == check) return false;
    }
    return true;
}


std::deque <std::string> fillQueue(std::string input) {
    std::deque<std::string> output;

    std::stringstream str(input);
    std::string token;
    while (str >> token) {
        if(checkExists(output, token)) output.push_back(token);
    }

    return output;
}

std::unordered_map <std::string, int> fillMap(std::string input) {
    std::unordered_map <std::string, int> wordCount;

    std::stringstream str(input);
    std::string token;
    while (str >> token) {
        wordCount[token] ++;
    }

    return wordCount;
}

void processOutput(std::unordered_map <std::string, int>& wordCount, std::deque <std::string>& wordQueue) {
    
    while (!wordQueue.empty())
    {
        if (wordCount.find(wordQueue.front())->second % 2 != 0) {
            std::cout << wordCount.find(wordQueue.front())->first;
            wordQueue.pop_front();
            if (wordQueue.size() > 0) std::cout << ", ";
        }
        else
        {
            wordQueue.pop_front();
        }
    }
}

int main()
{
    std::string input = getInput();

    auto wordCount = fillMap(input);
    auto orderOfAppearance = fillQueue(input);

    processOutput(wordCount, orderOfAppearance);
    
}
