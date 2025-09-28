/**
*File Name: proj3.cpp
*Academic Integrity Statement: I certify that, while others may have assisted me in brainstorming, debugging and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual that it could also result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural Guidelines at: https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelines
*Assisted by and Assisted line numbers: None
*Your Name: Eric Truong
*Your PSU user ID: evt5347
*Course title: CMPSC465 Fall 2025
*Due Time: 11:59 PM, Sunday, September 28, 2025
*Time of Last Modification: 4:41 PM, Sunday, September 28, 2025
*Description: This program reads a 2D board from input.txt, captures all regions surrounded by 'X', and prints the resulting board to the console.
 */

#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

// recursive function to mark 'O's on and next to the border
void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &mat, int delrow[], int delcol[]) {
    // marks current cell as visited
    vis[row][col] =1;
    // gets matrix dimensions
    int n = mat.size();
    int m = mat[0].size();

    // checks top, right, bottom, left of current cell
    for (int i = 0; i<4; i++) {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        // checks if neighboring cell is valid, unvisited, and an 'O' before visiting
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 'O' )
            dfs(nrow, ncol, vis, mat, delrow, delcol);
    }
}

// takes matrix dimensions and returns modified board
vector<vector<char>> fill(int n, int m, vector<vector<char>> mat) {
    // directions array for depth first search traversal
    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, 1, 0, -1};
    // initializes visited matrix
    vector<vector<int>> vis(n, vector<int>(m, 0));
    // checks first and last row for 'O's on and next to border
    for (int j = 0; j<m; j++) {
        //first row
        if (!vis[0][j] && mat[0][j] == 'O')
            dfs(0, j, vis, mat, delrow, delcol);

        // last row
        if (!vis[n-1][j] && mat[n-1][j] == 'O')
            dfs(n-1, j, vis, mat, delrow, delcol);
    }

    // checks first and last columns for 'O's on and next to border
    for (int i = 0; i<n; i++) {
        //first column
        if (!vis[i][0] && mat[i][0] == 'O')
            dfs(i, 0, vis, mat, delrow, delcol);
        if (!vis[i][m-1] && mat[i][m-1] == 'O')
            dfs(i, m-1, vis, mat, delrow, delcol);
    }

    //converts all unvisited 'O's to 'X'
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (!vis[i][j] && mat[i][j] == 'O')
                mat[i][j] = 'X';
        }
    }

    // returns modified matrix
    return mat;
}

int main() {
    ifstream infile("input.txt");

    // reads the first character for matrix size
    int n;
    infile >> n;
    infile.ignore(); // skip newline

    // reads each line and builds matrix
    vector<vector<char>> mat;
    string line;
    while (getline(infile, line)) {
        stringstream ss(line);
        vector<char> row;
        string cell;
        while (ss >> cell) {
            row.push_back(cell[0]);
        }
        mat.push_back(row);
    }

    // gets column count from first row and then get surrounded regions
    int m = mat[0].size();
    vector<vector<char>> result = fill(n, m, mat);

    // prints board to console
    for (const auto &row : result) {
        for (char ch : row)
            cout << ch << " ";
        cout << endl;
    }
}

/*
Sample input:
6
X X X X X O
X O X O O X
X X O O O X
X X X O X X
X O X X O O
X X X X X X

Sample Output:
X X X X X O
X X X X X X
X X X X X X
X X X X X X
X X X X O O
X X X X X X
*/
