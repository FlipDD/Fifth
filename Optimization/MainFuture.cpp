#include <thread>
#include <iostream>
#include <vector>
#include <future>

using namespace std;

int counts = 0;

int ThreadFunction(int x)
{
    this_thread::sleep_for(chrono::milliseconds(1));
    return x * x;
}

int main() 
{
    vector<future<int>> alltasks;

    for (int i = 1; i <= 20; i++)
    {
        alltasks.push_back(async(launch::async, ThreadFunction, i));
    }
    int total = 0;
    for (int i = 0; i < 20; i++)
    {
        total += alltasks.at(i).get();
    }
    
    cout << total << endl;
  
    cout << "End Program" << endl;
    return 0;
}

