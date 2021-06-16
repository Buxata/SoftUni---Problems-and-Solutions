#include <iostream>
#include <sstream>
#include <string>
#include <stack>


std::stringstream lineInput() {
    std::string temp;
    getline(std::cin, temp);
    std::stringstream str(temp);
    return str;
}

bool bracketCheck(char stringBack, char comparison) {
    switch (comparison)
    {
    case ')':
        if (stringBack == '(') return true;
    case ']':
        if (stringBack == '[') return true;
    case '}':
        if (stringBack == '{') return true;
    default:
        return false;
    }
}

std::stack <char> readBrackets (){
    std::stack <char> output;

    std::stringstream str = lineInput();
    char currentChar;

    while (str >> currentChar) {
        if (!output.empty() && bracketCheck(output.top(), currentChar)) {
            output.pop();
        }
        else output.push(currentChar);
    }
    return output;
}


int main()
{
    std::stack <char> brackets = readBrackets();

    if (brackets.empty()) std::cout << "YES";
    else std::cout << "NO";
}