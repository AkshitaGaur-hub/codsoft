#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main()
{
    srand((unsigned int)time(NULL));
    int guess = 0;
    cout << "Welcome to the Number Guessing Game!" << endl;
    int number = rand() % 100 + 1; /*rand() %100 = 1 - 99 + 1 = 1- 100*/
    int attempts = 0;
    do
    {
        cout << "Enter a guess between 1 and 100: ";
        cin >> guess;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Please enter a number." << endl;
            continue;
        }
        if (guess < 1 || guess > 100)
        {
            cout << "Guess out of range. Please enter a number between 1 and 100." << endl;
        }
        else if (guess < number)
        {
            cout << "It's low! Try again." << endl;
        }
        else if (guess > number)
        {
            cout << "It's high! Try again." << endl;
        }
        else
        {
            cout << "Congratulations! You've guessed the number: " << number << endl;
        }
        attempts++;
        
    } while (guess != number);
    
    cout << "Game Over!" << endl;
    cout << "Thank you for playing!" << endl;
    cout << "Attempts to gusses the actual number is : " << attempts << endl;
    return 0;
}