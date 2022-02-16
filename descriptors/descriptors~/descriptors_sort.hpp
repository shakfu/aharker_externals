
/*
 *  descriptors_sort.hpp
 *
 *	A header file for the sort routines in the descriptors~ and descriptorsrt~ objects.
 *	This code deals with various sorting operations in the descriptors~ and descriptorsrt~ objects.
 *
 *  Copyright 2010 Alex Harker. All rights reserved.
 *
 */

#ifndef _DESCRIPTORS_SORT_HPP_
#define _DESCRIPTORS_SORT_HPP_

#include <algorithm>

// Sorting Routines

// Convenience for altering swap flags

template <class T>
static bool swap(T& a, T& b)
{
    std::swap(a, b);
    return true;
}

// Gap Update

static inline long update_gap(long gap)
{
    if (gap > 1)
    {
        gap = (gap * 10) / 13;
        gap = (gap == 9 || gap == 10) ? 11 : gap;
    }
    
    return std::max(1L, gap);
}

// An ascending order sort (combsort11 algorithm)

template <class Compare, class T>
void sort(T& values, long size)
{
    bool swaps = true;
    
    for (long gap = size; gap > 1 || swaps; )
    {
        gap = update_gap(gap);
        
        for (long i = 0, swaps = false; i + gap < size; i++)
            if (Compare()(values[i], values[i + gap]))
                swaps = swap(values[i], values[i + gap]);
    }
}

// An ascending order index sort (combsort11 algorithm)

template <class Compare, class T, class U>
void sort(T& indices, const U& values, long size)
{
    bool swaps = true;
    
    for (long gap = size; gap > 1 || swaps; )
    {
        gap = update_gap(gap);
        
        for (long i = 0, swaps = false; i + gap < size; i++)
            if (Compare()(values[indices[i]], values[indices[i + gap]]))
                swaps = swap(indices[i], indices[i + gap]);
    }
}

template <class T>
void sort_ascending(T *data, unsigned long size)
{
    sort<std::greater<T>>(data, size);
}

template <class T>
void sort_descending(T *data, unsigned long size)
{
    sort<std::less<T>>(data, size);
}

template <class T, class U>
void sort_ascending(T& indices, const U *data, unsigned long size)
{
    sort<std::greater<U>>(indices, data, size);
}

template <class T, class U>
void sort_descending(T& indices, const U *data, unsigned long size)
{
    sort<std::less<U>>(indices, data, size);
}

#endif	/* _DESCRIPTORS_SORT_HPP_ */
