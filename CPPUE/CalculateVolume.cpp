#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

void Print(string value);
float RequestInput();

int main()
{
    Print("Welcome to the volume calculator");
    Print("Please enter the length of your cube");
    float UserValue = RequestInput();
    if (UserValue == 0)
    {
        Print("Where did you find a cube like that?");
    }
    else
    {
        stringstream ss;
        float Result = UserValue * UserValue * UserValue;
        setprecision(2);
        ss << "Your cube has " << to_string( Result) << " volume"; 
        Print(ss.str());
    }
    
    return 0;
}

void Print(string value)
{
    cout << value << endl;
}

float RequestInput()
{
    float Input;
    cin >> Input;
    return Input;
}

