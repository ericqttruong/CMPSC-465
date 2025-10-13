/**
*File Name: proj4.cpp
*Academic Integrity Statement: I certify that, while others may have assisted me in brain storming, debugging and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual that it could also result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural GuidelinesLinks to an external site. at:  https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelinesLinks to an external site.
*Assisted by and Assisted line numbers: None
*Your Name: Eric Truong
*Your PSU user ID: evt5347
*Course title: CMPSC 465 Fall 2025
*Due Time: 11:59 PM, Sunday, October 12, 2025
*Time of Last Modification: 10:30 PM, Sunday, October 12, 2025
*Description: Computes the shortest number of knight moves between two squares on a chessboard using BFS.
*/

#include <bits/stdc++.h>
using namespace std;

// structure for storing a cell's data
struct cell {
    int x, y, dis;
    cell() : x(0), y(0), dis(0) {}
    cell(int x, int y, int dis) : x(x), y(y), dis(dis) {}
};

// Utility method to check if (x, y) is inside the board
bool isInside(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

// Convert chess notation (e.g., "a1") to board coordinates
pair<int, int> toCoord(const string& pos) {
    return {pos[0] - 'a', pos[1] - '1'};
}

// Method to return the minimum steps to reach target
int minSteps(pair<int, int> knightPos, pair<int, int> targetPos, int n) {
    
    // x and y direction where a knight can move
    int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
    int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };

    // queue for storing knight's states
    queue<cell> q;

    // push starting position of knight with 0 distance
    q.push(cell(knightPos.first, knightPos.second, 0));

    cell t;
    int x, y;

    // Visit array initialized to false
    vector<vector<bool>> visit(n, vector<bool>(n, false));

    // visit starting position
    visit[knightPos.first][knightPos.second] = true;

    // loop until queue is empty
    while (!q.empty()) {
        t = q.front();
        q.pop();

        // if target is reached, return the distance
        if (t.x == targetPos.first && t.y == targetPos.second)
            return t.dis;

        // explore all reachable positions
        for (int i = 0; i < 8; i++) {
            x = t.x + dx[i];
            y = t.y + dy[i];

            // if the position is valid and not visited, push it to queue
            if (isInside(x, y, n) && !visit[x][y]) {
                visit[x][y] = true;
                q.push(cell(x, y, t.dis + 1));
            }
        }
    }

    // if no path found, return -1
    return -1;
}

int main() {
    ifstream infile("input.txt");
    string from, to;
    int boardSize = 8;

    while (infile >> from >> to) {
        pair<int, int> start = toCoord(from);
        pair<int, int> end = toCoord(to);
        int moves = minSteps(start, end, boardSize);
        cout << "To get from " << from << " to " << to << " takes " << moves << " knight moves." << endl;
    }

    return 0;
}

/*
Sample Output:
To get from e2 to e4 takes 2 knight moves.
To get from a1 to b2 takes 4 knight moves.
To get from b2 to c3 takes 2 knight moves.
To get from a1 to h8 takes 6 knight moves.
To get from a1 to h7 takes 5 knight moves.
To get from h8 to a1 takes 6 knight moves.
To get from b1 to c3 takes 1 knight moves.
To get from f6 to f6 takes 0 knight moves.
*/
