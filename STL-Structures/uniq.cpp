#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>


std::vector<std::string> sort_vector(std::vector<std::string> lines) {
    std::vector<std::string> newLines;
    for (std::string& value : lines) {

        // add the value of lines to the new vector if not yet in the vector.
        bool found = false;
        for (std::string newLine : newLines) {
            if (value == newLine) {
                found = true;
                break;
            }
        }
        if (!found) {
            newLines.push_back(value);

            // add all occurrences of the value in lines to the new vector
            for (std::string& line : lines) {
                if (value == line) {
                    newLines.push_back(value);
                }
            }
        }
    }
    return newLines;
}


int main(int argc, char const* argv[]) {
    // handle when give file
    if (argc > 1) {
        std::string infile = argv[1];
        std::ifstream inputFile(infile);

        if (!inputFile.is_open()) {
            std::cerr << "ERROR: can't open " << infile;
            return 1;
        }

        // read lines into a vector
        std::vector<std::string> lines;
        std::string line;
        while (getline(inputFile, line)) {
            lines.push_back(line);
        }

        // sort the vector first
        lines = sort_vector(lines);

        // filter lines from vector
        auto it = std::unique(lines.begin(), lines.end());

        lines.resize(std::distance(lines.begin(), it));


        // output lines
        for (it = lines.begin(); it!=lines.end(); it++) {
            std::cout << *it << std::endl;
        }

    }
    else {
        std::vector<std::string> lines;
        std::string line;
        while (std::getline(std::cin, line)) {
            lines.push_back(line);
        }

        // sort the vector first
        lines = sort_vector(lines);

        // filter lines from vector
        auto it = std::unique(lines.begin(), lines.end());

        lines.resize(std::distance(lines.begin(), it));


        // output lines
        for (it = lines.begin(); it!=lines.end(); it++) {
            std::cout << *it << std::endl;
        }

    }

    return 0;
}
