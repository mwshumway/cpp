#include <iostream>
#include <string>

using namespace std;

std::string input(std::string prompt) {
    std::cout << prompt;
    std::cout.flush();
    std::string response;
    std::getline(std::cin, response);
    return response;
}


bool check_if_valid(string op) {

    if(op == "add" || op == "subtract" || op == "multiply" || op ==
                                                              "divide" || op == "mod"){
        return true;
    }
    else{
        cout << op << " isn't a valid operation" << endl;
        return false;
    }
}

int perform_operation(string op, int left, int right) {
    if (op == "add") {
        return left + right;
    }
    else if (op == "subtract") {
        return left - right;
    }
    else if (op == "multiply") {
        return left*right;
    }
    else if (op == "divide") {
        return left / right;
    }
    else {
        return left % right;
    }
}


int main(int argc, char const* argv[]) {
    while(true) {
        string op = input("operation: ");
        if (op.empty()){
            return 0;
        }
        if (check_if_valid(op)){
            int left = stoi(input("left operand: "));
            int right = stoi(input("right operand: "));
            int final = perform_operation(op, left, right);
            cout << final << endl;
        }
    }
}
