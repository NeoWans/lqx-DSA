#pragma once
#include <bits/stdc++.h>

template<typename Iterator, typename CompFunc>
inline void heapify(Iterator base, Iterator first, Iterator last, const CompFunc& comp) {
  using namespace std;
  Iterator fa = first;
  Iterator son = (fa - base) * 2 + 1 + base;
  while(son <= last) {
    if(son + 1 <= last && comp(*son, *(son + 1)))  son ++;
    if(comp(*son, *fa))  return;
    else {
      swap(*fa, *son);
      fa = son;
      son = (fa - base) * 2 + 1 + base;
    }
  }
}

template<typename Iterator, typename CompFunc>
inline void heapSort(Iterator first, Iterator last, const CompFunc& comp) {
  using namespace std;
  int len = last - first;
  for(auto i = len / 2 - 1 + first; i >= first; i --)
    heapify(first, i, last - 1, comp);
  for(auto i = last - 1; i != first; i --) {
    swap(*first, *i);
    heapify(first, first, i - 1, comp);
  }
}