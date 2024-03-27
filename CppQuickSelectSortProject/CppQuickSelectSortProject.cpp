#include <iostream>

struct Tuple
{
    int first;
    int second;
};

void ArrayPrint(int* array, int begin, int end);
void Swap(int& a, int& b);

void ArrayPartitionOld(int* array, int begin, int end, int index);
Tuple ArrayPartition(int* array, int begin, int end, int index);
int ArrayQuickSelect(int* array, int begin, int end, int index);
void ArraySortBubble(int* array, int size);

int main()
{
    srand(time(nullptr));

    int size{ 21 };
    int* array = new int[size];
    int* array1 = new int[size];

    for (int i{}; i < size; i++)
    {
        int item = rand() % 100;
        array[i] = item;
        array1[i] = item;
    }

    ArraySortBubble(array1, size);
        

    ArrayPrint(array, 0, size - 1);

    std::cout << "select = " << ArrayQuickSelect(array, 0, size - 1, 5) << "\n";
    std::cout << "control = " << array1[5] << "\n";

    ArrayPrint(array, 0, size - 1);
    ArrayPrint(array1, 0, size - 1);
    
}

void ArrayPrint(int* array, int begin, int end)
{
    for (int i{ begin }; i <= end; i++)
        std::cout << array[i] << " ";
    std::cout << "\n";
}

void Swap(int& a, int& b)
{
    int temp{ a };
    a = b;
    b = temp;
}

void ArrayPartitionOld(int* array, int begin, int end, int index)
{
    int left{ begin };
    int right{ end };
    int pivot{ array[index] };

    std::cout << "pivot = " << pivot << "\n";

    do
    {
        while (array[left] < pivot) left++;
        while (array[right] > pivot) right--;

        if (left <= right)
            Swap(array[left++], array[right--]);

    } while (left <= right);
}

Tuple ArrayPartition(int* array, int begin, int end, int index)
{
    int left{ begin };
    int right{ end };

    int pivot{ array[index] };
    Swap(array[begin], array[index]);
    int current{ begin };

    while (current <= right)
    {
        if (array[current] < pivot)
            Swap(array[current++], array[left++]);
        else if (array[current] > pivot)
            Swap(array[current], array[right--]);
        else
            current++;
    }

    /*std::cout << "pivot = " << pivot << "\n";
    std::cout << "left = " << left << "\n";
    std::cout << "right = " << right << "\n";*/

    return Tuple{ left, right };
}

int ArrayQuickSelect(int* array, int begin, int end, int index)
{
    if (begin == end) return array[begin];

    int pivotIndex = begin + rand() % (end - begin + 1);
    auto result = ArrayPartition(array, begin, end, pivotIndex);
    if (index >= result.first && index <= result.second)
        return array[index];
    if (index < result.first)
        return ArrayQuickSelect(array, begin, result.first - 1, index);
    if (index > result.second)
        return ArrayQuickSelect(array, result.second + 1, end, index);
}

void ArraySortBubble(int* array, int size)
{
    for (int top{}; top < size; top++)
        for (int i{ size - 1 }; i > top; i--)
            if (array[i] < array[i - 1])
                Swap(array[i], array[i - 1]);
}
