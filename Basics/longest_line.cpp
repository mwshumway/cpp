#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;


int main(int argc, char const* argv[]) {
    string infile = argv[1];
    ifstream inputFile(infile);

    string maxLine;
    size_t maxLength = 0;
    string line;
    while(getline(inputFile, line)) {
        istringstream iss(line);
        vector<string> elements;
        string element;
        while (iss >> element) {
            elements.push_back(element);
        }
        size_t lineSize = elements.size();
        if (lineSize > maxLength) {
            maxLength = lineSize;
            maxLine = line;
        }
    }
    cout << maxLine + "\n";

    return 0;
}
