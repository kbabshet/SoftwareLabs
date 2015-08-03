#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;

int main()
{
    int genNumber, guessedNumber;
    srand (time(NULL));
    genNumber = rand() % 100 + 1;
    
    cout<<genNumber;
    
    for (int i = 1; i <= 5; i++)
    {
        cout<<"\nGuess a number between 1 and 100\n";
        cin>>guessedNumber;
        if (guessedNumber < 1 || guessedNumber > 100)
        {
            cout<<"\nInvalid guess. Please try game again later.\n";
            break;
        }
        
        else if (guessedNumber == genNumber)
        {
            cout<<"\nYou win!\n";
            break; //Break loop since the number was guessed correctly 
        }
        else if (guessedNumber < genNumber)
        {
            //Check if it's the last round before telling them how to guess for next round
            if (i != 5)
            {
                cout<<"\nGuess higher.\n";
            }
        }
        else 
        {
            //Check if it's the last round before telling them how to guess for next round
            if (i != 5)
            {
                cout<<"\nGuess lower.\n";
            }
        }
    }

}