#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
//typedef tuple<int, int, int> T;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)
#define ALL(c) c.begin(), c.end()
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};
const ll mod = 1e9+7;

/*
Range Sum Query by FenwickTree(Binary Indexed Tree)

total number: n
queries:
    1. add(i, val): bit[i] += val
    2. sum(n): sum(bit[0] + ... + bit[n-1])
time complexity: O(log n)
space complexity: O(N)

Self-balancing binary search tree or Segment Tree can do the same, it takes longer to program and complexity also increases.

Thanks: http://hos.ac/slides/20140319_bit.pdf

used in ARC031 C, indeednow finalB E, DSL2B(AOJ), ARC033 C, yukicoder No.59
*/

template<typename T> struct RangeSumQuery {
  int N;
  vector<T> dat;

  RangeSumQuery(int N) : N(N) {
    assert(N > 0);
    dat.resize(N, 0);
  }

  void add(int k, T val) {
    assert(0 <= k && k < N);
    for (int x = k; x < N; x |= x + 1) {
      dat[x] += val;
      dat[x] %= mod;
    }
  }

  // [0, k)
  T sum(int k) {
    assert(k >= 0);
    T ret = 0;
    for (int x = k - 1; x >= 0; x = (x & (x + 1)) - 1) {
      ret += dat[x];
      ret %= mod;
    }
    return ret;
  }
  // [l, r)
  T sum(int l, int r) {
    assert(0 <= l && l <= r && r <= N);
    return (sum(r) - sum(l) + mod) % mod;
  }

  T index(int k) {
    assert(0 <= k && k < N);
    return (sum(k+1) - sum(k) + mod) % mod;
  }
};

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int N, K; cin >> N >> K;
  RangeSumQuery<ll> fwt(N);
  REP(i, N-1) {
    if (i < K-1) {
      fwt.add(i, 1+fwt.sum(i));
    } else if (i == K-1) {
      fwt.add(i, fwt.sum(i));
    } else {
      fwt.add(i, fwt.sum(i-K, i));
    }
  }
  if (N > K) {
    cout << fwt.sum(N-K-1, N-2) << endl;
  } else {
    cout << fwt.sum(N-2) << endl;
  }
  return 0;
}
