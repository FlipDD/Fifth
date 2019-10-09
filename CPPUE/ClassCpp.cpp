#include <iostream>
#include <string>
#include "ClassHeader.h"

using namespace std;

bool AskingForInput = true;

bool ClassCpp::IsNameValid(const string &input)
{
    return input.length() > 3;
}

void ClassCpp::Print(string value)
{
    cout << value << endl;
}

string ClassCpp::RequestInput()
{
    string Input;
    cin >> Input;
    AskingForInput = false;
    return Input;
}
