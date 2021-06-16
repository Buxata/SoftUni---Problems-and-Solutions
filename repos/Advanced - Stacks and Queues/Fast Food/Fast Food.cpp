#include <iostream>
#include <string>
#include <sstream>
#include <queue>

std::stringstream lineInput() {
    std::string temp;
    getline(std::cin, temp);
    std::stringstream str(temp);
    return str;
}

std::queue <int> readQueue() {
    std::queue <int> output;
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

void noFoodLeft(std::queue <int> leftovers) {
    std::cout << "Orders left: ";

    while (!leftovers.empty())
    {
        std::cout << leftovers.front();
        leftovers.pop();
        if (!leftovers.empty()) std::cout << " ";
    }
}

void orderCalculation(int total, std::queue <int> &orders) {
    if (orders.empty()) std::cout << "no orders on queue";
    else {
        std::queue <int> leftovers;

        int biggestOrder = INT_MIN;
        while (!orders.empty())
        {
            int front = orders.front();
            if (biggestOrder < front) biggestOrder = front;
            total -= front;
            if (total < 0) leftovers.push(front);
            orders.pop();
        }
        std::cout << biggestOrder << std::endl;
        if (total >= 0) std::cout << "Orders complete";
        else noFoodLeft(leftovers);
    }
}

int main()
{
    int food = readInput();
    std::queue <int> orders = readQueue();

    orderCalculation(food, orders);
    
}
