#include <thread>
#include <iostream>
#include <vector>
#include <future>
#include <condition_variable>

using namespace std;

int producedData q= 0;

condition_variable myconditionvar;
mutex mymutex;
mutex mymutexagain;

void ThreadProducer()
{
    this_thread::sleep_for(chrono::milliseconds(1));
    producedData = 42;
    myconditionvar.notify_one();
}

void ThreadConsumer()
{
    unique_lock<mutex> lock(mymutex);
    myconditionvar.wait(lock);
    cout << producedData << endl;
}

int main() 
{
    thread producer(ThreadProducer);
    thread consumer(ThreadConsumer);
    producer.join();
    consumer.join();

    cout << "End Program" << endl;
    return 0;
}

