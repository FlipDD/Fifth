#include <thread>
#include <iostream>
#include <vector>
#include <mutex>

using namespace std;

mutex mymutex;

void ThreadFunction(int id)
{
    for (int i = 0; i < 10; i++)
    {
        mymutex.lock();
        cout << "Thread " << id << " Lap " << i << endl;
        mymutex.unlock();
        this_thread::sleep_for(chrono::milliseconds(rand() % 1000));
    }
    mymutex.lock();
    cout << "We finished boys!" << endl;
    mymutex.unlock();
}

int main() 
{
    vector<thread> allmythreads;
    // vector<thread> *allmythreads = new vector<thread>();
    for (int i = 0; i < 10; i++)
    {
        // allmythreads->push_back(thread(ThreadFunction, i)); // .Add in C#  / -> is for pointers
        allmythreads.push_back(thread(ThreadFunction, i));
    }

    for (int i = 0; i < 10; i++)
    {
        allmythreads.at(i).join();
    }
    
    cout << "End Program" << endl;
    return 0;
}

