#include <bits/stdc++.h>
#include "RadixSort.hh"
#include "ShellSort.hh"
using namespace std;
#define endl '\n'
class Solution {
public:
  int n;
  uint64_t compCnt;
  vector<int> v[5];
  void solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      int x; cin >> x;
      v[0].push_back(x);
    }
    for (int i = 1; i < 5; ++i)
      v[i] = v[0];
    auto comp = [&](const int& x, const int& y) {
      ++compCnt;
      return x < y;
    };
    radixSort(v[0].begin(), v[0].end(), comp);
    shellSort(v[1].begin(), v[1].end(), comp);
    for (int i = 0; i < 5; ++i) {
      for (const auto& x : v[i])
        cout << x << " ";
      cout << endl;
    }
  }
};
Solution s;
signed main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  s.solve();
}