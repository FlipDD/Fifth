#include <iostream> 

int numbers[5] = {1, 3, 2, 5, 4};

int main()
{
    int j, element = 0;
    for (int i = 0; i < (sizeof(numbers) / sizeof(int)); i++)
    {
        element = numbers[i];
        j = i - 1;
        while ((j >= 0) && (element < numbers[j]))
        {
            numbers[j+1] = numbers[j];
            j -= 1;
        }
    }
    for (const auto& e : numbers) {
    std::cout << e << std::endl;
}   
}