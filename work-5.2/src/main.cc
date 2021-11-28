#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  enum { maxm = 20, maxn = 100 };
  int n, m, k;
  vector<bitset<maxm>> vb;
  void solve() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
      string str; cin >> str;
      bitset<maxm> t(str);
      if (((m - t.count()) & 1) == (k & 1)) vb.push_back(t);
    }
    sort(vb.begin(), vb.end(), [](const bitset<maxm>& x, const bitset<maxm>& y) { return x.to_string() < y.to_string(); });
    int maxs = 1, len = 1;
    for (unsigned i = 1; i < vb.size(); ++i) {
      if (vb[i - 1] == vb[i]) {
        ++len;
        maxs = max(maxs, len);
      } else len = 1;
    }
    maxs = max(maxs, len);
    cout << maxs << endl;
  }
};
Solution s;
signed main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  s.solve();
}