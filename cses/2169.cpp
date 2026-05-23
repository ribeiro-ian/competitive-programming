/**
 * Contest : CSES Problem Set
 * Problem : 2169 - Nested Ranges Count
 * Link    : https://cses.fi/problemset/task/2169
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fastio ios::sync_with_stdio(0); cin.tie(0);

struct FenwickTree {
  int n;
  vector<int> bit; // binary indexed tree

    FenwickTree(int n) : n(n), bit(n, 0{}
    
    void reset({
    bit.assign(n, 0);
    }

    int sum(int r{
    int s = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) s += bit[r];
    return s;
    }
    
    int sum(int l, int r{
    return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta{
    for (; idx < n; idx = idx | (idx + 1)) bit[idx] += delta;
    }
};

int main() {
  fastio

  struct Range {
    int l, r, id;
  };

  int n; cin >> n;
  vector<Range> ranges(n);
  vector<int> contains(n), contained(n);

  for (int i = 0; i < n; ++i) {
    cin >> ranges[i].l >> ranges[i].r;
    ranges[i].id = i;
  }

  // === Coordinate Compression
  vector<int> coords;
  for (const auto &i : ranges) coords.push_back(i.r);
  sort(coords.begin(), coords.end());

  coords.erase(unique(coords.begin(), coords.end()), coords.end()); // remove dups

    auto compress = [&](int v{
    return lower_bound(coords.begin(), coords.end(), v) - coords.begin();
    }; // O(logN)

    // === Solve
    FenwickTree bit(coords.size()); // BIT for counting ranges

    // sort by start desc, end asc
    sort(ranges.begin(), ranges.end(), [](Range a, Range b) {
    return a.l != b.l ? a.l > b.l : a.r < b.r;
    });
    
    int minR = INT_MAX;
    for(int i = 0; i < n; ++i) {
    int compressed_r = compress(ranges[i].r);
    contains[ranges[i].id] = bit.sum(compressed_r);

    minR = min(minR, ranges[i].r);
    bit.add(compressed_r, 1);
    }

    // sort by start asc, end desc
    sort(ranges.begin(), ranges.end(), [](Range a, Range b) {
    return a.l != b.l ? a.l < b.l : a.r > b.r;
    });
    
    bit.reset();
    int maxR = 0;
    for(int i = 0; i < n; ++i) {
    int compressed_r = compress(ranges[i].r);
    contained[ranges[i].id] = bit.sum(compressed_r, bit.n - 1);

    maxR = max(maxR, ranges[i].r);
    bit.add(compressed_r, 1);
    }
    
    for(auto i : contains) cout << i << ' ';
    cout << endl;
    for(auto i : contained) cout << i << ' ';
    cout << endl;

	return 0;
}
