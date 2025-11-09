/**
*File Name: proj6.cpp
*Academic Integrity Statement: I certify that, while others may have assisted me in brainstorming, debugging and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual that it could also result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural Guidelines at: https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelines
*Assisted by and Assisted line numbers: None
*Your Name: Eric Truong
*Your PSU user ID: evt5347
*Course title: CMPSC 465 Fall 2025
*Due Time: 11:59 PM, Thursday, November 6, 2025
*Time of Last Modification: Sunday, November 9, 2025, 3:40 PM
*Description: Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

// Computes the largest square of 1s in a binary matrix
int maximalSquare(const vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> dp(rows, vector<int>(cols, 0));
    int maxSide = 0;

    // traverse each cell to build DP table
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == 1) {
                // apply recurrence relation
                if (i == 0 || j == 0)
                    dp[i][j] = 1; // edge cells
                else
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                maxSide = max(maxSide, dp[i][j]);
            }
        }
    }

    return maxSide * maxSide; // return area
}

int main() {
    ifstream infile("input.txt");
    string line;
    vector<vector<int>> matrix;
    int rows = 0, cols = 0;

    while (getline(infile, line)) {
        if (line == "0") break; // end of input

        if (line.empty()) continue; // skip empty lines

        stringstream ss(line);
        int r, c;
        if (ss >> r >> c) {
            // start of new test case
            rows = r;
            cols = c;
            matrix.clear();
            for (int i = 0; i < rows; ++i) {
                getline(infile, line);
                stringstream rowStream(line);
                vector<int> row;
                int val;
                while (rowStream >> val) {
                    row.push_back(val);
                }
                matrix.push_back(row);
            }
            // compute and print result for this test case
            cout << maximalSquare(matrix) << endl;
        }
    }

    return 0;
}

/*
output:
4
9
*/
