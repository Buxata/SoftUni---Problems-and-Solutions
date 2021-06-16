#include <iostream>
#include <stack>

void lookForEl(int el ,std::stack <int> c) {
    bool check = false;
    int temp = INT_MAX;
    if (c.empty())
    {
        std::cout << "0";
    }
    else
    {
        
        while (!c.empty()) {
            if (el == c.top()) {
                std::cout << "true";
                check = true;
                break;
            }
            else {
                if (temp > c.top()) temp = c.top();
                c.pop();
            }
        }
        if (!check) std::cout << temp;
    }

}

void addElements(int amount, std::stack <int>& container) {
    for (int i = 0; i < amount; i++) {
        int temp;
        std::cin >> temp;
        container.push(temp);
    }
}

void removeElements(int amount, std::stack<int>& container) {
    if (!container.empty()) {
        for (int i = 0; i < amount; i++) {
            container.pop();
        }
    }
    else std::cout << "container is empty...";
}

int main()
{
    int n, s, x;
    std::cin >> n >> s >> x;

    std::stack <int> container;
    
    addElements(n, container);
    removeElements(s, container);
    lookForEl(x, container);
}
