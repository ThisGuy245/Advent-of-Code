// 2025_day02.cpp : This file contains the 'main' function. Program execution begins and ends there.

/* Task at hand can be found below:
    https://adventofcode.com/2025/day/2
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>



bool invalidP1(long long id) {
    std::string s = std::to_string(id);
    for (int len = 1; len <= s.length() / 2; ++len) {
        std::string part = s.substr(0, len);
        if (s.substr(len) == part) {
            return true;
        }
    }
    return false;
}



bool invalidP2(long long id) {
    std::string s = std::to_string(id);
    int n = s.length();

    // Try all possible sequence lengths
    for (int len = 1; len <= n / 2; ++len) {
        if (n % len != 0) continue; // must divide evenly
        std::string part = s.substr(0, len);

        bool repeated = true;
        for (int i = len; i < n; i += len) {
            if (s.substr(i, len) != part) {
                repeated = false;
                break;
            }
        }
        if (repeated) return true;
    }
    return false;
}

// Getting all the numbers in the form 00, 000, 0000 etc in a range
std::vector<long long> getOptions(long long start, long long end) {
    std::vector<long long> candidates;

    for (int len = 1; len <= 10; ++len) { // max 10 digits per half should cover long long
        long long power = 1;
        for (int i = 0; i < len; ++i) power *= 10; // 10^len

        long long firstHalfStart = std::max(start / power, 1LL);
        long long firstHalfEnd = std::min(end / power, power - 1);

        for (long long firstHalf = firstHalfStart; firstHalf <= firstHalfEnd; ++firstHalf) {
            long long num = firstHalf * power + firstHalf; 
            if (num >= start && num <= end) {
                candidates.push_back(num);
            }
        }
    }

    return candidates;
}

// Dealing with ranges of ID's
// Separated by , 1stID - lastID
// Invalid = digits repeated 2x or more for Part 2
// example 11-22 (1, 2x and 2, 2x)
// 95-115 ([99] 9, 2x) and 05 (leading 0)
// trips are fine, 1188511880-1188511890 (1188511885 is wrong)
// answer is adding all the invalid ID's together!
long long part1(const std::vector<std::string>& ranges) {
    long long sum = 0;

    for (const auto& r : ranges) {
        size_t dash_pos = r.find('-');
        long long start = std::stoll(r.substr(0, dash_pos));
        long long end = std::stoll(r.substr(dash_pos + 1));

        std::vector<long long> candidates = getOptions(start, end);
        for (long long id : candidates) {
            if (invalidP1(id)) {
                sum += id;
            }
        }
    }

    return sum;
}

// What I had imagined for part 1
// trips and quads etc are NOT fine anymore
// 95-115 ([99] 9, 2x [111] 1, 3x)
long long part2(const std::vector<std::string>& ranges) {
    long long sum = 0;

    for (const auto& r : ranges) {
        size_t dash_pos = r.find('-');
        long long start = std::stoll(r.substr(0, dash_pos));
        long long end = std::stoll(r.substr(dash_pos + 1));

        // We can iterate naively for small ranges, or generate candidates for efficiency
        for (long long id = start; id <= end; ++id) {
            if (invalidP2(id)) {
                sum += id;
            }
        }
    }

    return sum;
}

int main() { // Same as day 1- but using strstream
    std::cout << "Let's Begin!\n";

    std::ifstream input("input.txt");
    std::string line;

    if (!input.is_open()) {
        std::cerr << "Error: could not open file!" << std::endl;
        return 1;
    }

    // Read line from file
    if (std::getline(input, line)) {
        std::vector<std::string> ranges;
        std::stringstream ss(line);
        std::string range;

        // Splitting the line into separate ranges
        while (std::getline(ss, range, ',')) {
            ranges.push_back(range);
        }

        // Part 1
        long long sumPart1 = part1(ranges);
        std::cout << "Part 1: Sum of invalid IDs = " << sumPart1 << std::endl;

        // Part 2
        long long sumPart2 = part2(ranges);
        std::cout << "Part 2: Sum of invalid IDs = " << sumPart2 << std::endl;
    }

    return 0;
}
