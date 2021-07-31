#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <unordered_map>

static std::map <std::string, int> players;

std::unordered_map <std::string, std::vector <std::string>> getTeam (){

	int numberOfTeams = 0;
	std::cin >> numberOfTeams;
	std::cin.ignore();	

	std::unordered_map <std::string, std::vector <std::string>> output;

	for (size_t i = 0; i < numberOfTeams; i++)
	{
		std::string input;
		getline(std::cin, input);
		std::stringstream str(input);

		std::string team;
		int numberOfPlayers;
		str >> team >> numberOfPlayers;
		for (int i = 0; i < numberOfPlayers; i++) {
			std::string token;
			str >> token;
			output[team].push_back(token);
			players[token] = 0;
		}
	}
		
	return output;
}

void printPlayers(std::map <std::string, int> &playersMap) {
	
	for (auto it = playersMap.begin(); it != playersMap.end(); it++) {
		std::cout << it->second << ' ';
	}
}


int main()
{
	std::cin.sync_with_stdio(false); 
	std::cout.sync_with_stdio(false);

	auto teams = getTeam();

	int matches = 0;
	std::cin >> matches;
	std::cin.ignore();

	for (int i = 0; i < matches; i++) {
		std::string input;
		std::cin >> input;

		for (auto player : teams[input])
		{
			players[player]++;
		}
	}

	printPlayers(players);
}