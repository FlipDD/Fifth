#include "ClassHeader.h"

int main()
{
    ClassCpp c;

    c.Print("Please enter your name");
    string UserValue;
    bool ValidName;

    do
    {
        UserValue = c.RequestInput();
        bool ValidName = c.IsNameValid(UserValue);
        c.Print(ValidName ?  "Your name is: " + UserValue : "Your name is invalid");
    } while (!ValidName);
    
    return 0;
}