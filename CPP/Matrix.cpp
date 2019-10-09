#include <thread>
#include <iostream>
#include <vector>
#include <mutex>

using namespace std;

mutex mymutex;
int mymatrix[5][5] = {{10, 20, 30, 40, 50}, 
                    {60, 70, 80, 90, 100}, 
                    {110, 120, 130, 140, 150}, 
                    {160, 170, 180, 190, 200}, 
                    {5, 15, 25, 35, 45}};

                    //size of, divide by array


void ThreadFunction(int id)
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        // mymutex.lock();
        sum += mymatrix[id][i];
        // cout << sum << endl;
        // mymutex.unlock();
    }
    
    mymutex.lock();
    cout << "We finished boys! Sum: " << sum << " Id: " << id << endl;
    mymutex.unlock();

    // Get each one into an array with the id
}

int main() 
{
    vector<thread> allmythreads;
    // vector<thread> *allmythreads = new vector<thread>();
    for (int i = 0; i < 5; i++)
    {
        // allmythreads->push_back(thread(ThreadFunction, i)); // .Add in C#  / -> is for pointers
        allmythreads.push_back(thread(ThreadFunction, i));
    }

    for (int i = 0; i < 5; i++)
    {
        allmythreads.at(i).join();
    }
    
    cout << "End Program" << endl;
    return 0;
}

