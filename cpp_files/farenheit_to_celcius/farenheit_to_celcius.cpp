#include <iostream>
using namespace std;

int main(void) {

    char choice;
    double farenheit_deg;
    double celcius_deg;

    cout << "This is a program that converts farenheit to celcius and vice-versa!" << endl;
    cout << "Choose which convertion you want, press 'F' for farenheit to celcius or 'C' for celcius to farenheit" << endl;

    while (1) {
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
                break;
        }
        cout << "Do you want to repeat the process? Press 'Y' for yes or 'N for no." << endl;
        char repeat;
        cin >> repeat;
        if (repeat == 'Y') {
            cout << "Choose which convertion you want, press 'F' for farenheit to celcius or 'C' for celcius to farenheit" << endl;
            continue;
        }    
        else if (repeat == 'N') {
            cout << "Understandable, have a nice day!" << endl;
            break;
        }    
        else { 
            cout << "The character you entered is non valid." << endl;
            break; 
        }  
    }      
    return 0;
}