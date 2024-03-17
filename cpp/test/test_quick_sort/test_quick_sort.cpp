#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "../../src/third/quick_sort.h"

int const SIZE = 10000;

// В данной функции main() создается массив array размером SIZE.
// Далее происходит заполнение массива array случайными числами от 1 до SIZE с помощью функции rand().
// Выводит значения массива array() на экран.
// Затем вызывается функция quickSort(), которая сортирует массив array по возрастанию.
// main() выводит отсортированный массив на экран, рассчитывает и выводит время выполнения quickSort().
// Выводит на экран время, затраченное на сортировку массива в формате "c_: время в тактах процессора" и "t_: время в миллисекундах".

int main()
{
    int array[SIZE];

    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i < SIZE; i++)
    {
        array[i] = rand() % SIZE + 1;
        std::cout << array[i] << std::endl;
    }

    const  std::clock_t c_start = std::clock();
    auto t_start = std::chrono::steady_clock::now();
    quickSort(array, 0, SIZE - 1);
    const  std::clock_t c_end = std::clock();
    auto t_end = std::chrono::steady_clock::now();

    std::cout << "Sorted array:" << std::endl;
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << array[i] << std::endl;
    }

    std::cout << "c_: " << c_end - c_start << std::endl;
    std::cout << "t_: " << std::chrono::duration<double, std::milli>(t_end - t_start).count() << " ms." << std::endl;

    return 0;
}