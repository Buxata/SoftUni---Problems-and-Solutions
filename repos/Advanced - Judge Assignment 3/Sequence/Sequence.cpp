#include <iostream>
#include <vector>
#include <string>
#include <sstream>

int main()
{
    using namespace std;

    int amount;
    cin >> amount;

    vector <int> numbers;

    for (size_t i = 0; i < amount; i++)
    {
        int token;
        cin >> token;
        numbers.push_back(token);
    }

    int counter = 1;
    int prevN = *numbers.begin();
    int highestCounter = 0;

    for (auto it = numbers.begin()+1; it != numbers.end(); it++) {
        if (prevN < *it) {
            counter++;
        }
        else counter = 1;
        if (counter > highestCounter) highestCounter = counter;
        prevN = *it;
    }

    cout << highestCounter;
}