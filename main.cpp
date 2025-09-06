/**
 *File Name: proj1.cpp
 *Academic Integrity Statement: I certify that, while others may have assisted me in brain storming, debugging and
    validating this program, the program itself is my own work. I understand that submitting code which is the work of
    other individuals is a violation of the course Academic Integrity Policy and may result in a zero credit for the
    assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly
    give my original work to another individual that it could also result in a zero credit for the assignment, or course
    failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural Guidelines at:
    https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelinesLinks
 *Assisted by and Assisted line numbers: N/A
 *Name: Eric Truong
 *PSU user ID: evt5347
 *Course: CMPSC465 Fall 2025
 *Due Time: 11:59 PM, Sunday, September 7, 2025
 *Time of Last Modification: 3:41 PM, Saturday, September 6, 2025
 *Description: This project writes to an output file, verifying if the permutations within the input file is possible
**/

#include <fstream>
#include <stack>
using namespace std;

int main() {
    int totalCars; // keeps track of how many total cars have to enter the station
    int nextCar; // keeps track of the next car from the input file
    int carsLeft; // keeps track of how many cars are left in station
    stack<int> station;

    fstream inputFile("C:/Users/erict/CLionProjects/proj1.cpp/lab1in.txt");
    fstream outputFile("C:/Users/erict/CLionProjects/proj1.cpp/lab1out.txt");

    // extract first couple values from input file
    inputFile >> totalCars;
    inputFile >> nextCar;

    carsLeft = totalCars;

    // loop process until 0 is extracted from input file
    while (nextCar != 0) {
        // this loop puts all the cars from 1 to "count" into the station
        for (int i = 1; i <= totalCars; i++) {
            station.push(i);

            // check if the top car matches the next car to leave the station
            while (station.top() == nextCar) {
                station.pop();
                inputFile >> nextCar;
                carsLeft--;
            }
        }

        // check if all cars have left the station
        if (carsLeft != 0) {
            // extract the rest of the cars, resetting to next code block
            for (int i = 0; i < carsLeft; i++) {
                inputFile >> nextCar;
            }

            outputFile << "No" << "\n";
        } else {
            outputFile << "Yes" << "\n";
        }

        // reset cars left in station after each process
        carsLeft = totalCars;
    }
}

/* Output:
No
Yes
No
No
No
Yes
Yes

*/