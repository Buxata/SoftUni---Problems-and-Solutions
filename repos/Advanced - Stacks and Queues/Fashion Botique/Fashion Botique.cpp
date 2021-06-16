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

std::stack <int> readStack() {
    std::stack <int> output;
    std::stringstream str = lineInput();
    int currentOrder;
    while (str >> currentOrder) {
        output.push(currentOrder);
    }

    return output;
}

int readInput() {
    std::stringstream str = lineInput();

    int output;
    str >> output;
    return output;
}


int calculateRacks(int rack, std::stack <int>& container) {
    int output = 1;
    if (container.empty()) std::cout << "conatiner is empty";
    else {
        int rackCopy = rack;
        int top;
        while (!container.empty()) {
            top = container.top();
            rackCopy -= top;
            if (rackCopy < 0)
            {
                output++;
                rackCopy = rack;
                rackCopy -= top;
            }
            container.pop();
        }
    }
    return output;
}

int main()
{
    std::stack <int> box = readStack();

    int rack = readInput();

    std::cout << calculateRacks(rack, box);
}

