#include <iostream>
using namespace std;
typedef unsigned int uint;
void input(string* studentNames, int* gamesPlayed, uint size);
void display(string* studentNames, int* gamesPlayed, uint size);
void displayMostMatches(string* studentNames, int* gamesPlayed, uint size);
void swapStrings(string &a, string &b);
void swapNumbers(int *a, int* b);
void sortStudents(string* studentNames, int* gamesPlayed, uint size);
double mean(int* gamesPlayed, uint size);

int main(void) {
    
    cout << "Enter the number of students that took part in the survey: " << endl;
    int numberOfStudents;
    cin >> numberOfStudents;
    if (numberOfStudents < 0) {
        while(1) {
            cout << "The number of students can't have a negative value, please try again: ";
            cin >> numberOfStudents;
            if (numberOfStudents > 0) 
                break;
        }
    }

    // Dynamically allocate memory for the two arrays that will be used.
    string* studentNames = new string[numberOfStudents];
    int* gamesPlayed = new int[numberOfStudents];
    
    input(studentNames, gamesPlayed, numberOfStudents);
    display(studentNames, gamesPlayed, numberOfStudents);
    displayMostMatches(studentNames, gamesPlayed, numberOfStudents);

    double gamesMean = mean(gamesPlayed, numberOfStudents);
    cout << "On average, each student has played " << gamesMean << " games" << endl;
    cout << "After shorting the students in alphabetical order, the list looks like this: " << endl;
    sortStudents(studentNames, gamesPlayed, numberOfStudents);
    display(studentNames, gamesPlayed, numberOfStudents);

    // The dynamically allocated memory has to be freed.
    delete[] studentNames;
    delete[] gamesPlayed;    
    return 0;
}

// Collects the data regarding the students and the number of games they played by the user input.
void input(string* studentNames, int* gamesPlayed, uint size) {

    cout << "Enter the name of the student and the number of games he played:" << endl;
    for (int i=0; i<size; i++) {
        cin >> studentNames[i];
        cin >> gamesPlayed[i];
        if (gamesPlayed[i] < 0) {
            while(1) {
                cout << "The number of games someone has played can't be a negative number, please try again:" << endl;
                cin >> studentNames[i];
                cin >> gamesPlayed[i];
                if (gamesPlayed[i] >= 0) 
                    break;
            }
        }
    }
    return;
}

// Displays the contents of the two arrays, first the name of the student, ant next the number of games they have played.
void display(string* studentNames, int* gamesPlayed, uint size) {
    cout << endl << "Here is the list of all the students, and the number of games they have played:" << endl;
    for (int i=0; i<size; i++) {
        cout << studentNames[i] << ", games played: " << gamesPlayed[i] << endl;
    }
    cout << endl;
}

// Calculates and prints which student has played the most amount of games.
void displayMostMatches(string* studentNames, int* gamesPlayed, uint size) {
    // Most is firstly set to -1, thus whatever number it faces will be greater.
    int most = -1;
    int index = 0;
    for (int i=0; i<size; i++) {
        if (gamesPlayed[i] > most) {
            most = gamesPlayed[i];
            index = i;
        }
    }
    cout << "The most games have been played from " << studentNames[index] << ", with a total of " << most << endl;
    return;
}

// Calculates and returns the average of the values in the given array.
double mean(int* gamesPlayed, uint size) {
    uint sum = 0;
    for (int i=0; i<size; i++) {
        sum += gamesPlayed[i];
    }
    double mean = (double) sum / size;
    return mean;
}

// Swaps the values of two given integers.
void swapNumbers(int *a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

// Swaps the two strings given by changing their addresses.
void swapStrings(string &a, string &b) {
    string temp = a;
    a = b;
    b = temp;
}

// Sorts the students in alphabetical order, while keeping the array that containts
// the number of games each on has played updated at every point in time.
void sortStudents(string *studentNames, int* gamesPlayed, uint size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (studentNames[j] > studentNames[j + 1]) {
                // Swap the elements if they are out of order.
                swapStrings(studentNames[j], studentNames[j + 1]);
                // Also swaps the numbers corresponding to the games played.
                swapNumbers(&gamesPlayed[j], &gamesPlayed[j+1]);
            }
        }
    }
}