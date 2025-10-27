/**
*File Name: proj5.cpp
*Academic Integrity Statement: I certify that, while others may have assisted me in brain storming, debugging and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual that it could also result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural Guidelines at: https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelines
*Assisted by and Assisted line numbers: None
*Your Name: Eric Truong
*Your PSU user ID: evt5347
*Course title: CMPSC465 Fall 2025
*Due Time: 11:59 PM, Sunday, October 26, 2025
*Time of Last Modification: 11:45 PM, Sunday, October 26, 2025
*Description: This program reads multiple test cases from an input file and counts the number of inversions
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

// Merges two sorted halves of the array and counts inversions
int mergeAndCount(vector<int>& arr, int left, int mid, int right) {
    // Create temporary subarrays for left and right halves
    vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

    // Merge the two halves while counting inversions
    int i = 0, j = 0, k = left, invCount = 0;
    while (i < leftArr.size() && j < rightArr.size()) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++]; // no inversion
        } else {
            arr[k++] = rightArr[j++]; //inversion found
            invCount += leftArr.size() - i; // Count how many elements in leftarr is greater
        }
    }

    // copy remaining elements from left and right array
    while (i < leftArr.size()) arr[k++] = leftArr[i++];
    while (j < rightArr.size()) arr[k++] = rightArr[j++];

    return invCount;
}

// Recursively sorts the array and counts inversions using merge sort
int mergeSortAndCount(vector<int>& arr, int left, int right) {
    if (left >= right) return 0; // base case one element
    int mid = left + (right - left) / 2;
    // Count inversions in left half, right half, and during merge
    int invLeft = mergeSortAndCount(arr, left, mid);
    int invRight = mergeSortAndCount(arr, mid + 1, right);
    int invMerge = mergeAndCount(arr, left, mid, right);
    return invLeft + invRight + invMerge;
}

int main() {
    ifstream inputFile("input.txt");

    string line;
    getline(inputFile, line);
    int testCases = stoi(line);

    // read and store numbers in vector
    for (int t = 0; t < testCases; ++t) {
        getline(inputFile, line);
        stringstream ss(line);
        vector<int> sequence;
        int num;
        while (ss >> num) {
            sequence.push_back(num);
        }
        // count inversions and then output
        int inversionCount = mergeSortAndCount(sequence, 0, sequence.size() - 1);
        cout << "The sequence has " << inversionCount << " inversions." << endl;
    }

    return 0;
}

/*
Sample Output:
The sequence has 3 inversions.
The sequence has 7 inversions.
The sequence has 5 inversions.
*/
