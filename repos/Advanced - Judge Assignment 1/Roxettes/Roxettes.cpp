#include <iostream>
#include <unordered_set>
#include <string>

int main()
{
	std::cin.sync_with_stdio(false);
	std::cout.sync_with_stdio(false);

	char token = ' ';

	std::unordered_set <std::string> dnaSet;

	std::string roxette;
	while (token != '.') {
		std::cin >> token;
		roxette += token;

		if (roxette.size() == 5) {
			if (dnaSet.find(roxette) != dnaSet.end()) dnaSet.erase(roxette);
			else dnaSet.insert(roxette);
			roxette = "";
		}
	}

	std::cout << *dnaSet.begin();
}