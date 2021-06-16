#include <iostream>
#include <stack>
#include <string>
#include <sstream>

const int addEl = 1, removeEl = 2, pMax = 3, pMin = 4;


void printMax(std::stack <int> container) {
    if (!container.empty()) {
        std::stack <int> copy = container;
        int temp = INT_MIN;
        while (!copy.empty()) {
            if (temp < copy.top()) temp = copy.top();
            copy.pop();
        }
        std::cout << temp << std::endl;
    }
}
void printMin(std::stack <int> container) {
    if (!container.empty()) {
        std::stack <int> copy = container;
        int temp = INT_MAX;
        while (!copy.empty()) {
            if (temp > copy.top()) temp = copy.top();
            copy.pop();
        }
        std::cout << temp << std::endl;
    }
}

void executeCommand(int command, int argument, std::stack <int> &container) {
    switch (command)
    {
    case addEl:
        container.push(argument);
        break;
    case removeEl:
        if(!container.empty()) container.pop();
        break;
    case pMax:
        printMax(container);
        break;
    case pMin:
        printMin(container);
        break;
    default:
        std::cout << "not a valid command";
        break;
    }
}
void readInput(int amount, std::stack <int>& container) {

    std::string line;
    getline(std::cin, line);

    std::stringstream str(line);
    str >> amount;

    for (int i = 0; i < amount; i++) {
        int temp = 0;
        int command = 0;
        
        getline(std::cin, line);
        std::stringstream curstr(line);
        if (curstr)
        {
            curstr >> command;
        }
        if (curstr)
        {
            curstr >> temp;
        }
        executeCommand(command, temp, container);
    }
}

void printStack(std::stack <int> &container) {
    std::stack <int> copy = container;
    while (!copy.empty()) {
        std::cout << copy.top();
        copy.pop();
        if (!copy.empty()) std::cout << ", ";
    }
}

int main()
{

    int n = 0;

    std::stack <int> container;

    readInput(n, container);

    printStack(container);
    
}