#include <iostream>
#include <queue>

void readInput(int amount, std::queue <int> &container) {
    for (int i = 0; i < amount; i++) {
        int temp;
        std::cin >> temp;
        container.push(temp);
    }
}

void removeElements(int amount, std::queue <int> &container) {
    for (size_t i = 0; i < amount; i++)
    {
        if (!container.empty()) container.pop();
    }
}

void printContainer(int element, std::queue <int> container) {
    if (!container.empty()) {
        int temp = INT_MAX;
        bool checkForElement = false;
        while (!container.empty())
        {
            if (container.front() == element) {
                std::cout << "true";
                checkForElement = true;
                break;
            }
            else if (temp > container.front()) temp = container.front();
            container.pop();
        }
        if (!checkForElement)
        {
            std::cout << temp;
        }
    }
    else std::cout << 0;
}

int main()
{
    int n, s, x;
    std::cin >> n >> s >> x;

    std::queue <int> container;

    readInput(n, container);
    removeElements(s, container);
    printContainer(x, container);
}
