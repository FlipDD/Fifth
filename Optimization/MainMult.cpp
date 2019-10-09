#include <thread>
#include <iostream>
#include <vector>
#include <mutex>
#include <atomic>

using namespace std;

mutex mymutex;
int counts = 0;

atomic<int> total(0);

void ThreadFunction(int x)
{
    mymutex.lock();
    counts += x * x;
    mymutex.unlock();
}

void ThreadFunctionNoMutex(int x)
{
    counts += x * x;
}


int main() 
{
    vector<thread> allmythreads;
    // vector<thread> *allmythreads = new vector<thread>();
    for (int i = 1; i <= 20; i++)
    {
        // allmythreads->push_back(thread(ThreadFunction, i)); // .Add in C#  / -> is for pointers
        allmythreads.push_back(thread(ThreadFunctionNoMutex, i));
    }

    for (int i = 0; i < 20; i++)
    {
        allmythreads.at(i).join();
    }
    cout << counts << endl; 
    cout << "End Program" << endl;
    return 0;
}

