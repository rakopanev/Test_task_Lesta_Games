#pragma once

#ifndef QUICK_SORT_H_
#define QUICK_SORT_H_

// Алгоритм работает рекурсивно, разделяя массив на две части относительно центрального элемента (pivot), затем сортирует эти две части отдельно.

void quickSort(int* array, int left, int right)
{
    int temp;

    if (left < right)
    {
        int pivot = array[(left + right) / 2];
        int l = left - 1;
        int r = right + 1;

        while (true)
        {
            do
            {
                l++;
            }
            while (array[l] < pivot);

            do
            {
                r--;
            }
            while (array[r] > pivot);

            if (l >= r)
            {
                break;
            }

            temp = array[l];
            array[l] = array[r];
            array[r] = temp;
        }

        quickSort(array, left, r);
        quickSort(array, r + 1, right);
    }
}

#endif