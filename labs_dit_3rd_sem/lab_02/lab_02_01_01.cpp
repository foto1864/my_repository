#include <iostream>
using namespace std;
typedef unsigned int uint;
bool IsPrime(uint n);
void PrintArray(uint* Array, uint size);

int main(void) {
    
    cout << "Please the upper limit of the range in which primes will be searched: " << endl;
    uint UpperLimit;
    cin >> UpperLimit;

    // This array will be used to store the odd prime numbers
    uint* OddArray = new uint(0);

    // This array will be used to store the even prime numbers [A.K.A only the number 2]
    uint* EvenArray = new uint(1);
    EvenArray[0] = 2;
    
    // This counter variable will be used to store how many numbers are in the OddArray
    uint count = 0;

    // This loop will over the numbers from 1,2,3..UpperLimit, searching for primes
    for (uint n = 1; n <= UpperLimit; n++) {
        if (IsPrime(n)) {
            // Memory is allocated for the temporary array
            uint* TempArray = new uint(count);        
            
            // After this loop, the contents of the OddArray will have been copied to the TempArray
            for (int i=0; i<count; i++) {
                TempArray[i] = OddArray[i];
            }
            
            // Memory of the OddArray is now freed
            delete[] OddArray;
            // And then it is reallocated, but this time will contain one more slot for a number to be inserted
            OddArray = new uint(count+1);
            
            // After this loop, the contents of the TempArray will have been copied to the OddArray
            for (int i=0; i<count; i++) {
                OddArray[i] = TempArray[i];
            }
            
            // And finally the prime number is inserted at the end of the array
            OddArray[count++] = n;
            // Memory of the TempArray is now freed
            delete[] TempArray;
        }   
    }

    cout << "The odd primes found in the selected range are: " << endl;
    PrintArray(OddArray, count);

    cout << "The even primes found in the selected range are: " << endl;
    PrintArray(EvenArray, 1);

    delete[] EvenArray;
    delete[] OddArray;
    return 0;
}

// This function returns true if the number entered is prime and false if it is not
bool IsPrime(uint n) {
    for (int i=2; i*i <= n; i++) {
        if (n % i == 0) 
            return false;
    }
    return true;
}

// This function prints the contents of a 1D array given the array and its size
void PrintArray(uint* Array, uint size) {
    uint numbers_counter = 0;
    for (int i=0; i<size; i++) {
        cout << Array[i] << "\t";
        numbers_counter++;
        if (numbers_counter % 5 == 0) {
            cout << endl;
        }
    }
    cout << endl;
}

