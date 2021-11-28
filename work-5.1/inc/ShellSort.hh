#pragma once
#include <iostream>
template<typename Iterator>
void shellSort(Iterator first, Iterator last) {
  int len = last - first, step;
  while (step < len / 3)
    step = 3 * step + 1;
  while (step >= 1) {
    for (auto i = step; i < len; i++)
      for (auto j = i; j >= step && comp(*(first + j), *(first + (j - step))); j -= step)
        swap(*(first + j), *(first + (j - step)));
    step = step / 3;
  }
}
