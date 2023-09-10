#include <iostream>
#include <string>
#include <queue>

using namespace std;


std::string input2(std::string prompt) {
    std::cout << prompt;
    std::cout.flush();
    std::string response;
    std::getline(std::cin, response);
    return response;
}

void doAdd (priority_queue<string>& pq) {
    string name = input2("Name: ");
    string priority = input2("Priority: ");
    if (0 <= stoi(priority) && stoi(priority) <= 9) {
        priority =  "0" + priority;
    }
    string toQueue = priority + " - " + name;
    pq.push(toQueue);
}

void doTake (priority_queue<string>& pq) {
    if (!pq.size()) {
        cout << "There are no more people in line" << endl;
        return;
    }
    else {
        string toOutput = pq.top();
        pq.pop();
        cout << toOutput << endl;
    }
}

int main(int argc, char const* argv[]) {
    priority_queue<string> pq;
    while (1) {
        string prompt = "What do you want to do? ";
        string operation = input2(prompt);
        if (!operation.size()) {break; }
        if (operation == "add") {
            doAdd(pq);
        }
        else if (operation == "take") {
            doTake(pq);
        } else {
            cout << operation << " isn't a valid operation" << endl;
        }
    }
    return 0;
}
