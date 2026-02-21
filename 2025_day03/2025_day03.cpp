// 2025_day03.cpp : This file contains the 'main' function. Program execution begins and ends there.

/* Task at hand can be found below:
    https://adventofcode.com/2025/day/2
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

int p1(const std::vector<std::string>& joltline) {
    int total = 0;

    for (const std::string& line : joltline) {
        int maxValue = 0;

        for (size_t i = 0; i < line.size(); ++i) {
            for (size_t j = i + 1; j < line.size(); ++j) {

                int first = line[i] - '0';
                int second = line[j] - '0';

                int value = first * 10 + second;

                if (value > maxValue) {
                    maxValue = value;
                }
            }
        }
        total += maxValue;
    }
    return total;
}

int p2(const std::vector<std::string>& joltline) {
    return 1;
}

int main()
{
    std::cout << "Hello World!\n";

    std::ifstream input("input.txt");
    if (!input.is_open()) {
        std::cerr << "Error: Cannot open file" << std::endl;
        return 1;
    }

    std::vector<std::string> joltline;
    std::string line;
    int jolt = 0;


    while (std::getline(input, line)) {
        joltline.push_back(line);
    }
    input.close();
    
    int resultP1 = p1(joltline);
    std::cout << "The result for part 1 is: " << resultP1 << std::endl;

    int resultP2 = p2(joltline);
    std::cout << "The result for part 2 is: " << resultP2 << std::endl;


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
