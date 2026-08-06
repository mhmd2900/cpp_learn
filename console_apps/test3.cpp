#include <iostream>
using namespace std;

void guess(int secret, int attempts) {
    int userGuess;
    cout << "Attempt " << attempts << " → Enter your guess: ";
    cin >> userGuess;

    if (userGuess == secret) {
        cout << "Correct! You got it in " << attempts << " attempts!" << endl;
    }   
    else {
        cout << "Try ." << endl;
        guess(secret, attempts + 1);   // try again
    }
}

int main() {
    int secret = 42;   // change this to make it harder
    cout << "Guess the number (between 1 and 100)!" << endl;
    guess(secret, 1);
    return 0;
}
