#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;


void insertSort (vector<string>& lines) {
    for (int i = 1; i < lines.size(); i++) {
        string compareMe = lines[i];
        int j = i - 1;
        while (lines[i] < lines[j]) {
            if (j > 0) {
                j--;
            }
            else {
                break;
            }
        }
        lines.insert(lines.begin() + j, lines[i]);
        if (lines[j+1] < lines[j]) {
            swap(lines[j+1], lines[j]);
        }
        lines.erase(lines.begin() + i + 1);
    }

    for (string s : lines) {
        cout << s << endl;
    }
}

int main(int argc, char const* argv[]) {
    // check if input file
    if (argc > 1) {
        string infile = argv[1];
        ifstream is(infile);
        vector<string> lines;
        string line;
        while (getline(is, line)) {
            lines.push_back(line);
        }
        insertSort(lines);
    }
    else {
        vector<string> lines;
        string line;
        while (getline(cin, line)) {
            lines.push_back(line);
        }
        insertSort(lines);
    }

    return 0;
}
