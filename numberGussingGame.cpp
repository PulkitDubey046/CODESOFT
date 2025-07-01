#include <iostream>
#include <cstdlib> 
#include <ctime>  
using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(0))); // random number generator

    char playAgain = 'y';

    while (playAgain == 'y' || playAgain == 'Y')
    {
        int secretNumber = rand() % 100 + 1; //range: 1 to 100
        int playerGuess = 0;
        int numberOfTries = 0;
        const int maxTries = 7;

        cout << "\n=== Welcome to the Number Guessing Game! ===" << endl;
        cout << "I'm thinking of a number between 1 and 100." << endl;
        cout << "You have " << maxTries << " chances to guess it!" << endl;

        while (numberOfTries < maxTries)
        {
            cout << "\nTry " << (numberOfTries + 1) << ": Enter your guess: ";
            cin >> playerGuess;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Please enter a valid number!" << endl;
                continue;
            }

            numberOfTries++;

            if (playerGuess < secretNumber)
            {
                cout << "Too low!";
            }
            else if (playerGuess > secretNumber)
            {
                cout << "Too high!";
            }
            else
            {
                cout << ":-) Congratulations !! You guessed it in " << numberOfTries << " tries!" << endl;
                cout<<"The number was " << secretNumber << "." << endl;
                break;
            }
        }

        if (playerGuess != secretNumber)
        {
            cout << "\nYou have used all your tries. The number was " << secretNumber << "." << endl;
        }

        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;

    }

    cout << "\nThanks for playing! Goodbye!" << endl;
    return 0;
}
