// 2025_day01.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/* Task at hand can be found below:
    https://adventofcode.com/2025/day/1
*/


// Dial 0 - 99, starts at 50
// attached document 
// L +  pos  or R + pos
// example: dial = 11 , R8 -> deal = 19
// example: dial = 19 , L20 -> deal = 99
// we only count the amount of times it has pointed to 0
int part1(const std::vector<std::string>& rotations) {
    int dial = 50;
    int actual = 0;
    for (const auto& line : rotations) {
        char direction = line[0];
        int clicks = std::stoi(line.substr(1));

        if (direction == 'L') {
            dial = (dial - clicks + 100) % 100;
        }
        else if (direction == 'R') {
            dial = (dial + clicks) % 100;
        }
        if (dial == 0) {
            actual++;
        }
    }
    return actual;
}

// This time the number of ANY click that passes 0 
// is registered as the actual amount
int part2(const std::vector<std::string>& rotations) {
    int dial = 50;
    int actual = 0;
    for (const auto& line : rotations) {
        char direction = line[0];
        int clicks = std::stoi(line.substr(1));

        for (int i = 0; i < clicks; ++i) {
            dial = (direction == 'L') ? (dial - 1 + 100) % 100 : (dial + 1) % 100;
            if (dial == 0) {
                actual++;
            }
        }
    }
    return actual;
}

int main() {
    std::cout << "Let's begin!\n" << std::endl;

    // Read the file 'example or input'
    std::ifstream input("input.txt");
    if (!input.is_open()) {
        std::cerr << "Error: Impossible to open file!" << std::endl;
        return 1;
    }

    std::vector<std::string> rotations;
    std::string line;
    while (std::getline(input, line)) {
        rotations.push_back(line);
    }
    input.close();

    // Part 1
    int resultPart1 = part1(rotations);
    std::cout << "Part 1: The dial hit '0', " << resultPart1 << " times!" << std::endl;

    // Part 2
    int resultPart2 = part2(rotations);
    std::cout << "Part 2: The dial hit '0', " << resultPart2 << " times!" << std::endl;

    return 0;
}
