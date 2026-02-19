// 2025_day02.cpp : This file contains the 'main' function. Program execution begins and ends there.

/* Task at hand can be found below:
    https://adventofcode.com/2025/day/1
*/

#include <iostream>
#include <string>
#include <fstream>

// Dealing with ranges of ID's
// Separated by , 1stID - lastID
// Invalid = digits repeated 2x or leading 0's
// example 11-22 (1, 2x and 2, 2x)
// 95-115 ([99] 9, 2x) and 05 (leading 0)
// trips are fine, 1188511880-1188511890 (1188511885 is wrong)
// answer is adding all the invalid ID's together!

int main()
{
    std::cout << "Let's Begin!\n";

    std::ifstream input("input.txt");
    std::string range;

    if (!input.is_open()) {
        std::cerr << "Error: could not open file!" << std::endl;
    }


}
