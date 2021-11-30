#include <bits/stdc++.h>
#include "radixSort.hh"
#include "shellSort.hh"
#include "quickSort.hh"
#include "heapSort.hh"
#include "mergeSort.hh"
using namespace std;
#define endl '\n'
class Solution {
public:
  int n;
  vector<int> v[5];
  const string sorts[5] = {"radixSort", "shellSort", "quickSort", "mergeSort", "heapSort"};
  void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      int x; cin >> x;
      v[0].push_back(x);
    }
    for (int i = 1; i < 5; ++i)
      v[i] = v[0];
    uint64_t compCnt = 0;
    vector<uint64_t> vc;
    auto comp = [&compCnt](const int& x, const int& y) {
      ++compCnt;
      return x < y;
    };
    // radixSort(v[0].begin(), v[0].end(), comp);
    vc.push_back(compCnt); compCnt = 0;
    shellSort(v[1].begin(), v[1].end(), comp);
    vc.push_back(compCnt); compCnt = 0;
    // quickSort(v[2].begin(), v[2].end(), comp);
    vc.push_back(compCnt); compCnt = 0;
    // mergeSort(v[3].begin(), v[3].end(), comp);
    vc.push_back(compCnt); compCnt = 0;
    // heapSort(v[4].begin(), v[4].end(), comp);
    vc.push_back(compCnt); compCnt = 0;
    for (int i = 0; i < 5; ++i)
      cout << sorts[i] << "交换次数：" << vc[i] << endl;
  }
};
Solution s;
signed main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  s.solve();
}