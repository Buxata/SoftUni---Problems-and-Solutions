#include <iostream>
#include <string>
#include <stack>
#include <sstream>

std::string copyMethod(int begin, int end, const std::string& input) {
    auto leftindex = input.find_last_of(' ', begin) + 1;
    auto rightIndex = input.find(' ', end);
    if (rightIndex == std::string::npos)
    {
        rightIndex = input.size();
    }
    return  input.substr(leftindex,rightIndex - leftindex);
}

void pasteMethod(int pos, std::stack <std::string>& clipBoard, std::string& input) {
    if (!clipBoard.empty()) {
        if (input[pos] == ' ') {
            std::string addingSpaces = ' ' + clipBoard.top();
            input.insert(pos, addingSpaces);
            clipBoard.pop();
        }
        else
        {
            input.insert(pos, clipBoard.top());
            clipBoard.pop();
        }
    }
}

int main()
{
    std::string input;
    getline(std::cin, input);

    std::stack <std::string> clipBoard;
    std::string command;

    while (getline(std::cin, command)) {
        std::stringstream line(command);
        std::string word;
        line >> word;
        if (word == "end") break;
        else if (word == "copy") {
            int beginPos, endPos;
            line >> beginPos >> endPos;
            clipBoard.push(copyMethod(beginPos, endPos, input));
        }
        else if (word == "paste") {
            int pos;
            line >> pos;
            pasteMethod(pos, clipBoard, input);
        }
    }

    std::cout << input;
}
