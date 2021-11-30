#pragma once
#include <bits/stdc++.h>

template<typename Iterator, typename CompFunc>
inline void _merge(Iterator first, Iterator mid, Iterator last, const CompFunc& comp) {
  using namespace std;
  vector <int> lv(first, mid + 1);
  vector <int> rv(mid + 1, last + 1);
  int l = 0, r = 0;
  lv.insert(lv.end(), numeric_limits<int>::max());
  rv.insert(rv.end(), numeric_limits<int>::max());
  for(auto i = first; i <= last; i ++) {
   if(comp(lv[l], rv[r])) {
     *i = lv[l];
      l ++;
    } else {
     *i = rv[r];
      r ++;
    }
  }
}

template<typename Iterator, typename CompFunc>
inline void mergeSort(Iterator first, Iterator last, const CompFunc& comp) {
  using namespace std;
  if(first >= last) return;
  Iterator mid = (last - first) / 2 + first;
  mergeSort(first, mid, comp);
  mergeSort(mid + 1, last, comp);
  _merge(first, mid, last, comp);
}