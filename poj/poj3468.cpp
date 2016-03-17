// for poj (old g++ version, cannot use bits/stdc++.h)

#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <iostream>
#include <bitset>
#include <algorithm>
#include <complex>
#include <string>
#include <utility>

using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
typedef pair<int, P> T;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)
#define ALL(c) c.begin(), c.end()
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

template <typename T>
struct RangeSumQuery {
  int N, _N;
  vector<T> data, datb;

  RangeSumQuery(int _N) : _N(_N) {
    assert(_N > 0);
    N = 1;
    while (N < _N) N <<= 1;
    data.assign(2 * N - 1, 0);
    datb.assign(2 * N - 1, 0);
  }

  void add(int a, int b, T x) { add(a, b, x, 0, 0, N); }
  void add(int a, int b, T x, int k, int l, int r) {
    if (a <= l and r <= b) {
      data[k] += x;
    } else if (l < b and a < r) {
      datb[k] += (min(r, b) - max(l, a)) * x;
      add(a, b, x, 2 * k + 1, l, (l + r) / 2);
      add(a, b, x, 2 * k + 2, (l + r) / 2, r);
    }
  }

  T sum(int a, int b) { return sum(a, b, 0, 0, N); }
  T sum(int a, int b, int k, int l, int r) {
    if (b <= l or r <= a) {
      return 0;
    } else if (a <= l and r <= b) {
      return data[k] * (r - l) + datb[k];
    } else {
      T res = data[k] * (min(r, b) - max(l, a));
      res += sum(a, b, 2 * k + 1, l, (l + r) / 2);
      res += sum(a, b, 2 * k + 2, (l + r) / 2, r);
      return res;
    }
  }
};
int main() {
  int N, Q;
  scanf("%d %d", &N, &Q);
  RangeSumQuery<ll> segt(N);
  REP(i, N) {
    int a; scanf("%d", &a);
    segt.add(i, i+1, a);
  }
  REP(i, Q) {
    char comm; scanf(" %c", &comm);
    if (comm == 'C') {
      int a, b, c; scanf("%d %d %d", &a, &b, &c); a--, b--;
      segt.add(a, b+1, c);
    } else {
      int a, b; scanf("%d %d", &a, &b); a--, b--;
      printf("%lld\n", segt.sum(a, b+1));
    }
  }
  return 0;
}
