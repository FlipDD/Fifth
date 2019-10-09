#include <thread>
#include <iostream>
#include <vector>
#include <mutex>

using namespace std;

mutex mymutex;

int values[1000];
int valuesmult[1000];
int scalar = 3;

void ThreadFunction(int id)
{
    int mult = 0;
    for (int i = id * 100; i < 100 * (id+1); i++)
    {
        mult = values[i] * scalar;
        valuesmult[i] = mult;
        mymutex.lock();
        cout << "Initial value: " << values[i] << " End value: " << valuesmult[i] << endl;
        mymutex.unlock();
    }
    
    mymutex.lock();
    cout << "We finished boys! Sum: " << mult << " Id: " << id << endl;
    mymutex.unlock();
}

int main() 
{
    vector<thread> allmythreads;
    // vector<thread> *allmythreads = new vector<thread>();
    for (int i = 0; i < sizeof(values) / sizeof(int); i++)
    {
        values[i] = rand() % 100;
    }

    for (int i = 0; i < 10; i++)
    {
        // allmythreads->push_back(thread(ThreadFunction, i));  // .Add in C#  / -> is for pointers
        // allmythreads.push_back(thread(ThreadFunction, i));   // This makes a copy and places it
        allmythreads.emplace_back(thread(ThreadFunction, i));   // This creates it already in place
    }

    for (int i = 0; i < 10; i++)
    {
        allmythreads.at(i).join();
    }
    
    cout << "End Program" << endl;
    return 0;
}

