#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::stringstream lineInput() {
    std::string temp;
    getline(std::cin, temp);
    std::stringstream str(temp);
    return str;
}

int readInput() {
    std::stringstream str = lineInput();

    int output;
    str >> output;
    return output;
}

std::vector <std::vector <int>> readPetrolStations(int n) {
    std::vector <std::vector <int>> output;
    for (size_t i = 0; i < n; i++)
    {
        std::stringstream str = lineInput();
        std::vector <int> currentLine;
        int temp;
        while (str >> temp) currentLine.push_back(temp);
        output.push_back(currentLine);
    }

    return output;
}

bool fullCircle(std::vector <std::vector <int>> container, int start) {
    int fuel = 0;
    for (size_t i = start; i < container.size(); i++)
    {
        fuel += container[i][0];
        fuel -= container[i][1];
        if (fuel < 0)
        {
            return false;
        }
    }
    for (size_t i = 0; i < start; i++)
    {
        fuel += container[i][0];
        fuel -= container[i][1];
        if (fuel < 0)
        {
            return false;
        }
    }
    return true;
}


int startingPoint(std::vector <std::vector <int>> container) {
    for (size_t i = 0; i < container.size(); i++)
    {
        if (fullCircle(container, i)) return i;
    }
}

int main()
{
    int n = readInput();
    std::vector <std::vector <int>> petrolStations = readPetrolStations(n);

    std::cout << startingPoint(petrolStations);
}