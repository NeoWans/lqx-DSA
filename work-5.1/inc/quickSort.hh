#pragma once
#include <bits/stdc++.h>
template<typename Iterator, typename CompFunc>
inline Iterator _partition(Iterator first, Iterator last, const CompFunc& comp) {
    auto now = *first;
    while(first < last) {
        while(first < last && !comp(*last, now)) {
            --last;
        }
        *first = *last;
        while(first < last && !comp(now, *first)) {
            ++first;
        }
        *last = *first;
    }
    *first = now;
    return first;
}

template<typename Iterator, typename CompFunc>
inline void quickSort(Iterator first, Iterator last, const CompFunc& comp) {
    last --;
    if(first < last) {
        Iterator now = _partition(first, last, comp);
        quickSort(first, now, comp);
        quickSort(now + 1, last + 1, comp);
    }
}