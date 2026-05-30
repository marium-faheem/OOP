#include <iostream>
using namespace std;

template <typename T>
int searchElement(T arr[], int size, T element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    throw "Element not found!";
}

int main()
{
    float arr[] = {1.1, 2.2, 3.3, 4.4};
    int size = 4;
    try
    {
        int index = searchElement(arr, size, 3.3f);
        cout << "Found at index: " << index << endl;
    }
    catch (const char *e)
    {
        cout << e << endl;
    }
    char ch[] = {'a', 'b', 'c', 'd'};
    int size2 = 4;
    try
    {
        int index = searchElement(ch, size2, 'c');
        cout << "Found at index: " << index << endl;
    }
    catch (const char *e)
    {
        cout << e << endl;
    }
    return 0;
}