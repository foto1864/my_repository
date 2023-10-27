#include <iostream>
using namespace std;
typedef unsigned int uint;
void input(string* studentNames, int* gamesPlayed, uint size);
void display(string* studentNames, int* gamesPlayed, uint size);
void displayMostMatches(string* studentNames, int* gamesPlayed, uint size);
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

    string* studentNames = new string[numberOfStudents];
    int* gamesPlayed = new int[numberOfStudents];
    
    input(studentNames, gamesPlayed, numberOfStudents);
    display(studentNames, gamesPlayed, numberOfStudents);
    displayMostMatches(studentNames, gamesPlayed, numberOfStudents);

    double gamesMean = mean(gamesPlayed, numberOfStudents);
    cout << "On average, each student has played " << gamesMean << " games" << endl;
    return 0;

}

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

void display(string* studentNames, int* gamesPlayed, uint size) {
    cout << endl << "Here is the list of all the students, and the number of games they have played:" << endl;
    for (int i=0; i<size; i++) {
        cout << studentNames[i] << ", games played: " << gamesPlayed[i] << endl;
    }
    cout << endl;
}

void displayMostMatches(string* studentNames, int* gamesPlayed, uint size) {
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

double mean(int* gamesPlayed, uint size) {
    uint sum = 0;
    for (int i=0; i<size; i++) {
        sum += gamesPlayed[i];
    }
    double mean = (double) sum / size;
    return mean;
}