#include <thread>
#include <iostream>
#include <vector>
#include <mutex>
#include <queue>
#include <condition_variable>

using namespace std;

queue<int> resources;
int totalProduced = 0;
int totalConsumed = 0;
const int capacity = 20;
bool productionDone = false;

condition_variable notfull;
condition_variable notempty;
mutex mymutex;
mutex consolemutex;

void Producer()
{
    for (int i = 0; i < 500; i++)
    {
        unique_lock<mutex> lock(mymutex);
        while(resources.size() > capacity)
        {
            notfull.wait(lock);
        }

        resources.push(i);
        lock.unlock();
        consolemutex.lock();
        cout << "Produced:"  << i <<endl;
        consolemutex.unlock();
        totalProduced++; // Be careful with this one multiple threads
        notempty.notify_one(); // Change for multiple threads

        this_thread::sleep_for(chrono::milliseconds(10));
    }
    productionDone = true;
}

void Consumer()
{
    while (!productionDone)
    {
        while (!resources.empty())
        {
            unique_lock<mutex> lock(mymutex);
            while (resources.empty())
            {
                notempty.wait(lock);
            }
            int value = resources.front();
            resources.pop();
            lock.unlock();
            
            consolemutex.lock();
            cout << "Consumed: "  << value << endl;
            consolemutex.unlock();
            notfull.notify_one();
            totalConsumed++;

            this_thread::sleep_for(chrono::milliseconds(10));
        }
    }
}

int main() 
{
    vector<thread> allmyproducers;
    vector<thread> allmyconsumers;

    for (int i = 0; i < 10; i++)
    {
        allmyproducers.push_back(thread(Producer));
        allmyconsumers.push_back(thread(Consumer));
    }

    for (int i = 0; i < 10; i++)
    {
        allmyproducers.at(i).join();
        allmyconsumers.at(i).join();
    }

    cout << "Produced: " << totalProduced << endl;
    cout << "Consumed: " << totalConsumed << endl;
    cout << "Resources " << resources.size() << endl;
    
    cout << "End Program" << endl;
    return 0;
}


// #include <thread>
// #include <iostream>
// #include <vector>
// #include <mutex>
// #include <queue>
// #include <condition_variable>

// using namespace std;

// queue<int> resources;
// int totalProduced = 0;
// int totalConsumed = 0;
// const int capacity = 20;
// bool productionDone = false;

// condition_variable myconditionvariable;
// mutex mymutex;
// mutex consolemutex;

// void Producer()
// {
//     for (int i = 0; i < 500; i++)
//     {
//         unique_lock<mutex> locki(mymutexagain);

//         cout << "Produced" <<endl;
//         resources.push(i);
//         totalProduced++;
//         myconditionvariable.notify_one();

//         }
//         else
//         {
//             myconditionvariable.wait(locki); 
//         }
        
//     }
//     productionDone = true;
// }

// void Consumer()
// {
//     while (!productionDone)
//     {
//         unique_lock<mutex> lock(mymutex);
//         cout << "Consumed" << endl;
//         resources.pop();
//         totalConsumed++;
//         myconditionvariable.notify_all();
//         if (!resources.empty())
//         {
//             myconditionvariable.wait(lock);
//         }
//     }
// }

// int main() 
// {
//     thread producer(Producer);
//     thread consumer(Consumer);
//     producer.join();
//     consumer.join();

//     cout << "Produced: " << totalProduced << endl;
//     cout << "Consumed: " << totalConsumed << endl;
//     cout << "Resources " << resources.size() << endl;
    
//     cout << "End Program" << endl;
//     return 0;
// }

