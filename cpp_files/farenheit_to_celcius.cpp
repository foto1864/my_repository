#include <iostream>
using namespace std;

int main(void) {

    char choice;
    double farenheit_deg;
    double celcius_deg;

    cout << "This is a program that converts farenheit to celcius and vice-versa!" << endl;
    cout << "Choose which convertion you want, press 'F' for farenheit to celcius or 'C' for celcius to farenheit" << endl;

    cin >> choice;

    switch (choice) {
        case 'F': 
            cout << "Enter a value in Farenheit to be converted to celcius: ";
            cin >> farenheit_deg;
            celcius_deg = (5.0/9.0) * (farenheit_deg - 32);
            cout << "The value in celcius is: " << celcius_deg << endl;
            break;
        case 'C':
            cout << "Enter a value in Celcius to be converted to farenheit: ";
            cin >> celcius_deg;
            farenheit_deg = (9.0/5.0) * celcius_deg + 32;
            cout << "The value in farenheit is " << farenheit_deg << endl;
            break;
        default: 
            cout << "The character you entered is non valid." << endl;
    }
    return 0;
}