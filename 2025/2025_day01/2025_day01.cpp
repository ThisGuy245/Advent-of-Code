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

int main()
{
    std::cout << "Let's begin!\n" << std::endl;

    int dial = 50;
    int actual = 0;
    std::ifstream input("input.txt");
    std::string line;

    // Error handling
    if (!input.is_open())
    {
        std::cerr << "Erreur: Impossible d'ouvrir le fichier!" << std::endl;
        return 1;
    }

    // Logic
    while (std::getline(input, line))
    {
        char direction = line[0]; // Gets me first letter [L/R]
        int clicks = std::stoi(line.substr(1)); // Makes the rest of the line into an int [13..]

        if (direction == 'L') {
            dial = (dial - clicks + 100) % 100; // Modulo always keeps +ve
        }
        else if (direction == 'R') {
            dial = (dial + clicks) % 100;
        }
        if (dial == 0) {
            actual += 1;
        }
    }

    input.close();
    std::cout << "The dial hit '0', " << actual << " times!" << std::endl;

}



