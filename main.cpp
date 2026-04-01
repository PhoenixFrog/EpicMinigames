#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <ctime>
//#include <cctype>
using namespace std;

void FizzBuzz(const bool inputMode)
{
    int i;
    int limit;
    cout << "what number would you like to go up to?" << endl;
    cin >> limit;
    if (inputMode)
    {
        int incorrect = 0;
        string answer;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Go!" << endl;
        for (i = 1; i < limit + 1; i++)
        {
            string correctAnswer;

            getline(cin, answer);
            answer.erase(remove_if(answer.begin(), answer.end(), [](char c)
            {return c == ' ';}), answer.end());
            transform(answer.begin(), answer.end(), answer.begin(), ::tolower );
            //cout << answer << endl;

            if (i % 3 == 0 and i % 5 == 0)
                correctAnswer = "fizzbuzz";
            else if (i % 5 == 0)
                correctAnswer = "buzz";
            else if (i % 3 == 0)
                correctAnswer = "fizz";
            else correctAnswer = to_string(i);

            if (answer != correctAnswer)
            {
                cout << "WRONGGG. [insert loud incorrect buzzer]" << endl;
                ++incorrect;
            }
        }
        int percent = (incorrect*100)/limit;
        cout << "Finished!" <<endl;
        cout << "You got " << incorrect << " wrong answers." << endl;
        if (percent > 33) cout << "how are you BAD at FizzBuzz???" << endl;
        else if (percent == 0) cout << "Perfect score!" << endl;
        else cout << "Pretty good!" << endl;
    }
    else //auto mode
    {
        for ( i = 1; i < limit + 1; i++)
        {
            if (i % 3 == 0 and i % 5 == 0)
                cout << "FizzBuzz" << endl;
            else if (i % 5 == 0)
                cout << "Buzz" << endl;
            else if (i % 3 == 0)
                cout << "Fizz" << endl;
            else cout << i << endl;
        }
    }
}

void RandomNumberGuesser()
{
    srand(time(nullptr));
    int guess;
    int guesses = 0;
    int number = rand() % 100;
    bool guessed = false;

    cout << "Take a guess!" << endl;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    while (!guessed)
    {
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        cin >> guess;

        if (guess < 0 || guess > 100) cout << "That guess is out of bounds!" << endl;
        else if (guess < number)
        {
            cout << "Higher" << endl;
            ++guesses;
        }
        else if (guess > number)
        {
            cout << "Lower" << endl;
            ++guesses;
        }
        else
        {
            guessed = true;
            ++guesses;
        }
    }
    cout << number << " is correct!" << endl;
    cout << "It took you " << guesses << " guesses" << endl;

}

int main()
{
    bool playing = true;
    while (playing == true)
    {
        int game;
        cout << "what would you like to play?" << endl;
        cout << "1.FizzBuzz" << endl <<
            "2.Random Number Guesser" << endl;
        cin >> game;

        if (game == 1)
        {
            int mode;
            cout << "1.Input mode" << endl << "2.Output mode" << endl;
            cin >> mode;
            if (mode ==1 ) FizzBuzz(true);
            else if (mode == 2) FizzBuzz(false);
        }
        else if (game == 2)
        {
            RandomNumberGuesser();
        }
        char repeat;
        cout << "Would you like to play another game? [y/n]" << endl;
        cin >> repeat;
        if (tolower(repeat) == 'n')
        {
            cout << "Thanks for playing!" << endl;
            playing = false;
        }
    }
    return 0;
}
