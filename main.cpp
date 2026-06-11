// ------------- FILE HEADER -------------
// Author ✅: 
// Assignment ✅:
// Date ✅:
// Citations: 


// ------------- ZYBOOKS SCORES -------------
// Chapter ✅: 
// Participation ✅: 
// Challenge ✅:
// Labs ✅:


// ------------- DISCORD POSTS -------------
// https://discord.com/invite/URYKKf8YHm
// Count ✅:
// Links (Optional): 


// ------------- DESIGN DOCUMENT -------------
// A. INPUT ✅: 
// B. OUTPUT ✅:
// C. CALCULATIONS ✅:
// D. LOGIC and ALGORITHMS ✅:
//    (Optional) flow chart link or file name: 


// ------------- TESTING -------------
// PASS ALL GIVEN SAMPLE RUN TESTS ✅: 
// (Optional) Additional tests count:   


// ------------- CODE -------------
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>

using namespace std;

// Function prototypes (if any)


// Main function
// https://en.cppreference.com/w/cpp/language/main_function.html
const int MIN_ASSIGNMENTS = 0;
const int MAX_ASSIGNMENTS = 10;

const double MIN_SCORE = 0.0;
const double MAX_SCORE = 4.0;

const double ASSIGNMENT_WEIGHT = 0.60;
const double MIDTERM_WEIGHT = 0.20;
const double FINAL_WEIGHT = 0.20;

void welcome();
int readInt(string prompt);
void readScore(string prompt, double &num);
double assignAverage(int numAssigns);
void getInput(double &midtermScore, double &finalExamScore);
double calcFinalScore(double assignAvg, double midterm, double final);
void calcLetterGrade(double finalScore, char &letter);

int main() {
    int numAssigns = 0;
    double assignAvg = 0.0;
    double midtermScore = 0.0;
    double finalExamScore = 0.0;
    double finalScore = 0.0;
    char letterGrade = ' ';

    welcome();

    numAssigns = readInt("Enter the number of assignments (0 to 10): ");

    while (numAssigns < MIN_ASSIGNMENTS || numAssigns > MAX_ASSIGNMENTS) {
        cout << "Illegal Value! Please try again!!" << endl;
        numAssigns = readInt("Enter the number of assignments (0 to 10): ");
    }

    assignAvg = assignAverage(numAssigns);

    getInput(midtermScore, finalExamScore);

    finalScore = calcFinalScore(assignAvg, midtermScore, finalExamScore);

    calcLetterGrade(finalScore, letterGrade);

    cout << fixed << setprecision(1);
    cout << endl;
    cout << "Your Final Numeric score is " << finalScore << endl;
    cout << "Your Final Grade is " << letterGrade << endl;
    cout << endl;
    cout << "Thank you for using my Grade Calculator!" << endl;

    return 0;
}

void welcome() {
    cout << "Welcome to my Final Grade Calculator!" << endl;
    cout << "Please enter the following information and I will calculate your" << endl;
    cout << "Final Numerical Grade and Letter Grade for you!" << endl;
    cout << "The number of assignments must be between 0 and 10." << endl;
    cout << "All scores entered must be between 0 and 4." << endl;
    cout << endl;
}

int readInt(string prompt) {
    int num = 0;

    cout << prompt;
    cin >> num;

    while (!cin) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Illegal Value! Please try again!!" << endl;
        cout << prompt;
        cin >> num;
    }

    return num;
}

void readScore(string prompt, double &num) {
    cout << prompt;
    cin >> num;

    while (!cin || num < MIN_SCORE || num > MAX_SCORE) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Illegal Score! Please try again!" << endl;
        cout << prompt;
        cin >> num;
    }
}

double assignAverage(int numAssigns) {
    double score = 0.0;
    double sum = 0.0;
    double average = 0.0;

    for (int i = 1; i <= numAssigns; i++) {
        readScore("Enter score " + to_string(i) + ": ", score);
        sum = sum + score;
    }

    if (numAssigns > 0) {
        average = sum / numAssigns;
    }

    return average;
}

void getInput(double &midtermScore, double &finalExamScore) {
    cout << endl;
    readScore("Enter your midterm exam score: ", midtermScore);
    readScore("Enter your final exam score: ", finalExamScore);
}

double calcFinalScore(double assignAvg, double midterm, double final) {
    return assignAvg * ASSIGNMENT_WEIGHT
         + midterm * MIDTERM_WEIGHT
         + final * FINAL_WEIGHT;
}

void calcLetterGrade(double finalScore, char &letter) {
    if (finalScore >= 3.3) {
        letter = 'A';
    } else if (finalScore >= 2.8) {
        letter = 'B';
    } else if (finalScore >= 2.0) {
        letter = 'C';
    } else if (finalScore >= 1.2) {
        letter = 'D';
    } else {
        letter = 'F';
    }
}


// Function implementations (if any)


// ------------- DESIGN -------------
/* 
Program Name:

Program Description:

Design:
A. INPUT
Define the input variables including name data type. 

B. OUTPUT
Define the output variables including data types. 

C. CALCULATIONS
Describe calculations used by algorithms in step D.  
List all formulas. 
If there are no calculations needed, state there are no calculations.

D. LOGIC and ALGORITHMS
Design the logic of your program using pseudocode or flowcharts. 
Use conditionals, loops, functions or array constructs.
List the steps in transforming inputs into outputs. 
https://github.com/Glen-Sasek-PCC-Instructor/2025-06-22/blob/main/Pseudocode-Reference.txt


SAMPLE RUNS
Copy from assignment document.

*/
