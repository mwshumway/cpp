#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;


int main(int argc, char const* argv[]) {
    // check if user inputted a file and number of lines
    if (argc == 3) {
        string infile = argv[2];
        ifstream inputFile(infile);

        // check if file exists
        if (!inputFile.is_open()) {
            cerr << "ERROR: can't open " << infile;
            return 1;
        }

        // get line number
        int numLines = stoi(argv[1]) * -1;

        string line;
        int count = 0;
        while (getline(inputFile, line) && count < numLines) {
            cout << line << endl;
            count ++;
        }
    }
        // either number of lines or file
    else if (argc == 2) {
        // figure out what we have
        string unknown = argv[1];
        size_t l = unknown.length();
        if (l >= 5) {
            if (unknown.substr(l - 3) == "txt") {
                ifstream inputFile(unknown);

                // check if file exists
                if (!inputFile.is_open()) {
                    cerr << "ERROR: can't open " << unknown;
                    return 1;
                }
                string line;
                for (int i = 0; i < 10; i++) {
                    getline(inputFile, line);
                    cout << line << endl;
                }
            }
        }
            // else we have only num lines
        else {
            string lines;
            string get_line;
            while (getline(cin, get_line)) {
                lines += get_line + '\n';
            }
            istringstream iss(lines);
            string line;

            // get line number
            int numLines = stoi(argv[1]) * -1;
            int count = 0;

            while (getline(iss, line) && count < numLines) {
                cout << line << endl;
                count ++;
            }
        }
    }
        // else we have nothing, accept input and read all lines?
    else {
        string lines;
        string get_line;
        while (getline(cin, get_line)) {
            lines += get_line + '\n';
        }
        istringstream iss(lines);
        string line;

        while (getline(iss, line)) {
            cout << line << endl;
        }
    }
    return 0;
}
