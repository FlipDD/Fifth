#include <iostream>
#include <string>
#include <chrono>

using namespace std;

int elements[10] = {2, 1, 3, 5, 4, 8, 0, 9, 7, 6};
int elements2[20] = {7, 5, 9, 4, 8, 6, 0, 3, 2, 1, 3, 8, 1, 0, 2, 7, 4, 5, 6, 9};
int elements3[5] = {2, 1, 6, 4, 9};

void BubbleSort(int array[], int size);
void BubbleSortAlternative(int array[], int size);
void PrintArray(int array[], int size, string arrayname);

int main()
{
    // PrintArray(elements, 10, "Elements1(before)");
    // BubbleSort(elements, 10);
    // PrintArray(elements, 10, "Elements1(after)");
    // cout << endl;
    // PrintArray(elements2, 20, "Elements2(before)");
    // BubbleSort(elements2, 20);
    // PrintArray(elements2, 20, "Elements2(after)");
    // cout << endl;
    // PrintArray(elements3, 5, "Elements3(before)");
    // BubbleSort(elements3, 5);
    // PrintArray(elements3, 5, "Elements3(after)");
    // cout << endl;
    // cout << endl;
    PrintArray(elements, 10, "Elements1(before) ALTERNATIVE");
    BubbleSortAlternative(elements, 10);
    PrintArray(elements, 10, "Elements1(after) ALTERNATIVE");
    cout << endl;
    PrintArray(elements2, 20, "Elements2(before) ALTERNATIVE");
    BubbleSortAlternative(elements2, 20);
    PrintArray(elements2, 20, "Elements2(after) ALTERNATIVE");
    cout << endl;
    PrintArray(elements3, 5, "Elements3(before) ALTERNATIVE");
    BubbleSortAlternative(elements3, 5);
    PrintArray(elements3, 5, "Elements3(after) ALTERNATIVE");
    cout << endl;
}

void BubbleSort(int array[], int size)
{
    auto start = chrono::steady_clock::now();

    bool swapped = false;

    do
    {
        swapped = false;

        for (int i = 0; i < size; i++)
        {
            if (array[i-1] > array[i])
            {
                swap(array[i-1], array[i]);
                swapped = true;
            }
        } 
    } while (swapped);

    auto end = chrono::steady_clock::now();
    cout << "Elapsed time in nanoseconds: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;  
}

void BubbleSortAlternative(int array[], int size)
{
    auto start = chrono::steady_clock::now();

    bool swapped;
    int n = size;
    int tmpn;
    do
    {
        swapped = false;

        for (int i = 0; i < n; i++)
        {
            if (array[i-1] > array[i])
            {
                tmpn = i;
                swap(array[i-1], array[i]);
                swapped = true;
            }
        }
        n = tmpn;
    } while (swapped);

    auto end = chrono::steady_clock::now();
    cout << "Elapsed time in nanoseconds: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;   
}

void PrintArray(int array[], int size, string arrayname)
{
    cout << arrayname << " ---";
    for (int i = 0; i < size; i++)
    {
        cout << " - " << array[i];
    }
    cout << endl;
    
}