#include <iostream>
#include <string>
#include <chrono>

using namespace std;

int elements[10] = {2, 1, 3, 5, 4, 8, 0, 9, 7, 6};
int elementscopy[10];
int elements2copy[20];
int elements3copy[5];

int elements2[20] = {7, 5, 9, 4, 8, 6, 0, 3, 2, 1, 3, 8, 1, 0, 2, 7, 4, 5, 6, 9};
int elements3[5] = {2, 1, 6, 4, 9};

void InsertionSort(int array[], int size);
void InsertionSort(string &phrase);
void BubbleSortAlternative(int array[], int size);
void PrintArray(int array[], int size, string arrayname);
void PrintArray(string phrase, int size, string arrayname);

int main()
{
    copy(begin(elements), end(elements), begin(elementscopy));
    copy(begin(elements2), end(elements2), begin(elements2copy));
    copy(begin(elements3), end(elements3), begin(elements3copy));

    cout << "INSERTION SORT" << endl;
    PrintArray(elements, 10, "Elements1(before)");
    InsertionSort(elements, 10);
    PrintArray(elements, 10, "Elements1(after)");
    cout << endl;
    PrintArray(elements2, 20, "Elements2(before)");
    InsertionSort(elements2, 20);
    PrintArray(elements2, 20, "Elements2(after)");
    cout << endl;
    PrintArray(elements3, 5, "Elements3(before)");
    InsertionSort(elements3, 5);
    PrintArray(elements3, 5, "Elements3(after)");
    cout << "END OF INSERTION SORT" << endl;
    cout << endl;
    cout << "BEGINING BUBBLESORT" << endl;
    PrintArray(elementscopy, 10, "Elements1(before)");
    BubbleSortAlternative(elementscopy, 10);
    PrintArray(elementscopy, 10, "Elements1(after)");
    cout << endl;
    PrintArray(elements2copy, 20, "Elements2(before)");
    BubbleSortAlternative(elements2copy, 20);
    PrintArray(elements2copy, 20, "Elements2(after)");
    cout << endl;
    PrintArray(elements3copy, 5, "Elements3(before)");
    BubbleSortAlternative(elements3copy, 5);
    PrintArray(elements3copy, 5, "Elements3(after)");

    cout << endl << "BEGINING OF STRING SORT" << endl;
    string s = "HelloPeople";
    PrintArray(s, 10, "Elements1(before)");
    InsertionSort(s);
    PrintArray(s, 10, "Elements1(after)");
}

void InsertionSort(int array[], int size)
{
    auto start = chrono::steady_clock::now();
    int key, j;
    for (int i = 1; i < size; i++)
    {
        key = array[i];
        j = i;

        while (j > 0 && array[j-1] >= key)
        {
            array[j] = array[j-1];
            j -= 1;
        }
        array[j] = key;
    }
    

    auto end = chrono::steady_clock::now();
    cout << "Elapsed time in nanoseconds: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;  
}

void InsertionSort(string &phrase)
{
    auto start = chrono::steady_clock::now();
    int key, j;
    for (int i = 1; i < phrase.length(); i++)
    {
        key = phrase[i];
        j = i;

        while (j > 0 && phrase[j-1] >= key)
        {
            phrase[j] = phrase[j-1];
            j -= 1;
        }
        phrase[j] = key;
    }
    

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

void PrintArray(string phrase, int size, string arrayname)
{
    cout << arrayname << " ---" << phrase;
    cout << endl;
}