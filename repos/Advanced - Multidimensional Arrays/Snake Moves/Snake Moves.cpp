#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <iterator>

std::vector<std::deque<char>> mekASnek(int N, int M, std::string &snek) {
    std::vector<std::deque<char>> snekMatrix;

    bool isRight = true;

    auto it = snek.begin();
    auto end = snek.end();

    for (size_t i = 0; i < N; i++)
    {
        std::deque <char> line;
        if (isRight)
        {
            for (size_t j = 0; j < M; j++)
            {
                if (it != end) {
                    line.push_back(*it);
                    it++;
                }
                else {
                    it = snek.begin();
                    line.push_back(*it);
                    it++;
                }
            }
            isRight = false;
        }
        else
        {
            for (size_t j = 0; j < M; j++)
            {
                if (it != end) {
                    line.push_front(*it);
                    it++;
                }
                else {
                    it = snek.begin();
                    line.push_front(*it);
                    it++;
                }
            }
            isRight = true;
        }
        snekMatrix.push_back(line);
    }
    return snekMatrix;
}

void printASnek(int N, int M, const std::vector<std::deque<char>>& snekMatrix) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cout << snekMatrix[i][j];
        }
        std::cout << std::endl;
    }
}

int main(std::vector<std::vector<char>>)
{

    int N, M;
    std::string snake;

    std::cin >> N >> M >> snake;

    auto snek = mekASnek(N, M, snake);

    printASnek(N, M, snek);

}
