#include <iostream>
#include <string>

using namespace std;

void Print(string value);
string RequestInput();
bool IsNameValid(const string &input);
bool AskingForInput = true;

int main()
{
    Print("Please enter your name");
    string UserValue;
    bool ValidName;

    do
    {
        UserValue = RequestInput();
        Print("Your name is " + UserValue);

        bool ValidName = IsNameValid(UserValue);
        Print(ValidName ?  "Your name is: " + UserValue : "Your name is invalid");
    } while (!ValidName);
    
    return 0;
}

bool IsNameValid(const string &input)
{
    return input.length() > 3;
}

void Print(string value)
{
    cout << value << endl;
}

string RequestInput()
{
    string Input;
    cin >> Input;
    AskingForInput = false;
    return Input;
}
