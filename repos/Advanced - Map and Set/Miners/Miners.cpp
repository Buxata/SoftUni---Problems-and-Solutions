#include <iostream>
#include <unordered_map>
#include <string>
#include <deque>

void printUnorderedMap(std::unordered_map <std::string, int> &map, std::deque <std::string>& commands) {

	while (!commands.empty()) {
		std::cout << commands.front() << " -> " << map[commands.front()] << std::endl;
		commands.pop_front();
	}
}

bool checkExists(std::deque <std::string>& v, std::string& check) {
	for (auto word : v) {
		if (word == check) return false;
	}
	return true;
}

void fillMap(std::unordered_map <std::string, int> &map, std::deque<std::string> &commands) {
	std::string command;
	while (std::cin >> command && command != "stop") {
		if (checkExists(commands, command)) commands.push_back(command);
		int amount;
		std::cin >> amount;
		map[command] += amount;
	}
}

int main()
{
	std::cin.sync_with_stdio(false);
	std::cout.sync_with_stdio(false);

    std::unordered_map <std::string, int> minersAudit;
	std::deque <std::string> commands;

	fillMap(minersAudit, commands);

	printUnorderedMap(minersAudit, commands);

	return 0;
}