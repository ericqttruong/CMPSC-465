/**
*File Name: proj2.cpp

*Academic Integrity Statement: I certify that, while others may have assisted me in brainstorming, debugging and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual that it could also result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural Guidelines at: https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelines

*Assisted by and Assisted line numbers: None

*Your Name: Eric Truong

*Your PSU user ID: evt5347

*Course title: CMPSC465 Fall 2025

*Due Time: 11:59 PM, Sunday, September 21, 2025

*Time of Last Modification: 4:56 PM, Sunday, September 21, 2025

*Description: Given n pairs of parentheses, generates all combinations of well-formed parentheses.
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 *recursive function to build parentheses
 *open: number of '(' left
 *close: number of ')' left
 *str: string of parentheses being built
 *result: reference to the vector storing valid combinations
 *returns result string vector
 */
void generateParenthesesHelper(int open, int close, string str, vector<string>& result) {
    //base case: when no parentheses left to place, add str to result
    if (open == 0 && close == 0) {
        result.push_back(str);
        return;
    }
    //if there are remaining open parentheses, call recursive function while decrementing open and appending string
    if (open > 0) {
        generateParenthesesHelper(open - 1, close, str + '(', result);
    }
    //if there are more close than open, call recursive function while decrementing close and appending string
    if (open < close) {
        generateParenthesesHelper(open, close - 1, str + ')', result);
    }
}

//initializes recursive function with n open and close parentheses, returns result string vector
vector<string> generateParentheses(int n) {
    vector<string> result;
    string str = "";
    generateParenthesesHelper(n, n, str, result);
    return result;
}

int main() {
    // asks user to input number of pairs of parentheses
    int n;
    cout << "Enter number of pairs of parentheses: ";
    cin >> n;
    // get result string vector
    vector<string> parentheses = generateParentheses(n);
    //prints each combination in parentheses vector
    for (const string& combination : parentheses) {
        cout << combination << endl;
    }
}
/*
Test Case 1:
Input: 1
Output:
()

Test Case 2:
Input: 2
Output:
(())
()()

Test Case 3:
Input: 3
Output:
((()))
(()())
(())()
()(())
()()()
*/
