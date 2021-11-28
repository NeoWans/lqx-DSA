#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  random_device rd;
  mt19937 mt(rd());
  uniform_int_distribution uidist(0, INT32_MAX);
  const int n = 10000;
  cout << n << endl;
  for (int i = 0; i < n; ++i)
    cout << uidist(mt) << " ";
}