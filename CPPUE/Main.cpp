#include <iostream>

using namespace std;

const int number = 1;

int main()
{
    cout << "Hello there, n: " << number << endl;
    cout << "Please enter a between 0 and 1000" << endl;
    int input;
    cin >> input;

    if (!cin)
    {
        cout << "You can only enter numbers" << endl;
    }
    else
    {
        if (input > 1000 || input < 0)
        {
            cout << "Your number is out of range" << endl;
        }
        else
        {
            cout << "You entered " << input << endl;    
        }
    }
}