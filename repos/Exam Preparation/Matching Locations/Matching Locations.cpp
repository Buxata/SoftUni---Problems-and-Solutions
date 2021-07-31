#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>

std::unordered_map <std::string, std::pair <std::string, std::string>> getLocations(std::vector <std::string> &indexVector) {
    std::unordered_map <std::string, std::pair <std::string, std::string>> output;

    std::string input;
    getline(std::cin, input);


    while (input != ".") {
        std::stringstream str(input);

        std::string city = "", latitude = "", longitude = "";
        getline(str, city, ',');
        getline(str, latitude, ',');
        getline(str, longitude, ',');


        output[city].first = latitude;
        output[city].second = longitude;

        indexVector.push_back(city);

        getline(std::cin, input);
    }
    
    return output;
}

void processQuery(std::vector<std::string> indexVector, const std::string& input,const std::unordered_map <std::string, std::pair <std::string, std::string>> &cities) {
    std::stringstream str(input);

    std::string token;
    int counter = 0;
    while (str >> token) {
        counter++;
    }
    if (counter > 1) {
        str.clear();
        str.str(input);
        
        std::string latitude, longitude;
        str >> latitude >> longitude;

        auto location = std::make_pair (latitude, longitude);
        for (auto it = indexVector.begin(); it != indexVector.end(); it++ ) {
            auto city = cities.find(*it);
            if (city != cities.end() && city->second.first == location.first && city->second.second == location.second) {
                std::cout << city->first << ',' << city->second.first << ',' << city->second.second << '\n';
            }
        }
    }
    else
    {
        for (auto it = indexVector.begin(); it != indexVector.end(); it++) {
            if (*it == token) {
                auto city = cities.find(*it);
                if (city != cities.end()) {
                    std::cout << city->first << ',' << city->second.first << ',' << city->second.second << '\n';
                }
            }
        }
    }
}

int main()
{
    std::vector <std::string> citiesIndex;
    auto cities = getLocations(citiesIndex);

    std::string input;
    getline(std::cin, input);
    while (input != ".")
    {
        processQuery(citiesIndex, input, cities);
        getline(std::cin, input);
    }
}