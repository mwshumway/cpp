#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "Grid.h"

using namespace std;

const int BACKGROUND = 1;
const int TEMPORARY = 2;
const int PATH = 3;


bool find_maze_path(Grid& maze, int x, int y, int z, vector<string>& solution) {
    if (x < 0 || y < 0 || z < 0 || x >= maze.height() || y >= maze.width() || z >= maze.depth()) {
        return false; // outside of maze
    }
    else if (maze.at(x, y, z) != 1) {
        return false; // hit a 0, can't move
    }
    else if (maze.at(x, y, z) == TEMPORARY) {
        return false; // been to this spot before
    }
    else if (x == maze.height() - 1 && y == maze.width() -1 && z == maze.depth() - 1) {
        maze.at(x, y, z) == 4;
        solution.insert(solution.begin(), to_string(x) + " " + to_string(y) + " "
                                          + to_string(z));
        return true;
    }
    else {
        // recursive cases
        maze.at(x, y, z) = PATH;
        if (find_maze_path(maze, x-1, y, z, solution)
            || find_maze_path(maze, x+1, y, z, solution)
            || find_maze_path(maze, x, y-1, z, solution)
            || find_maze_path(maze, x, y+1, z, solution)
            || find_maze_path(maze, x, y, z-1, solution)
            || find_maze_path(maze, x, y, z+1, solution)) {
            solution.insert(solution.begin(), to_string(x) + " " + to_string(y) + " "
                                              + to_string(z));
            return true;
        }
        else {
            maze.at(x,y,z) = TEMPORARY;
            return false;
        }
    }
}

vector<string> solveMaze(Grid& maze) {
    vector<string> solution;
    find_maze_path(maze, 0, 0, 0, solution);
    return solution;
}


int main(int argc, char* argv[]) {
    // set up everything
    Grid maze;
    string infile = argv[1];
    string outfile = argv[2];
    ifstream in(infile);
    ofstream out(outfile);
    in >> maze;

    // solve maze
    vector<string> solution = solveMaze(maze);

    // export maze
    ofstream outputFile(outfile);
    if (solution.empty()) {
        outputFile << "NO SOLUTION";
    }
    else {
        outputFile << "SOLUTION" << endl;
        for (const string s : solution) {
            outputFile << s << endl;
        }
    }
    return 0;
}

