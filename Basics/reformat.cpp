#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>


using namespace std;

int main(int argc, char const* argv[]) {
    string infile = argv[1];
    string outfile = argv[2];
    ifstream inputFile(infile);
    ofstream outputFile(outfile);
    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        vector<string> elements;
        string element;
        while (iss >> element) {
            elements.push_back(element);
        }
        string first = elements[0];
        string last = elements[1];
        int score = stoi(elements[2]);
        float factor = stof(elements[3]);
        outputFile << last << ", " << first << ": " << score * factor << endl;
    }


    return 0;
}
