#include <iostream>
#include <string>

using namespace std;


void forwards(int start, int end, int divisor) {
    for (start; start <= end; start++) {
        if (start % divisor == 0) {
            cout << start << endl;
        }
    }
}


void backwards(int start, int end, int divisor) {
    // 16 8 4
    for (start; start >= end; start--) {
        if (start % divisor == 0) {
            cout << start << endl;
        }
    }
}


int main(int argc, char const* argv[]) {
    int start = stoi(argv[1]);
    int end = stoi(argv[2]);
    int divisor = stoi(argv[3]);
    if (start < end) {
        forwards(start, end, divisor);
    }
    else {
        backwards(start, end, divisor);
    }


    return 0;
}