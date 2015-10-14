#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
typedef tuple<int, int, int> T;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)
#define ALL(c) c.begin(), c.end()
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl

#define INF 2147483647
const int MAX_N = 300030;

/*
RangeMinimumQuery by Segment Tree
query:
    1. update(i, val): update i-th value to val(0-indexrd)
    2. query(low, high): find minimun value in [low, high)
time complexity: O(log n)
space complexity: O(2n) 
used in DSL2A(AOJ), ARC045 B
*/
struct RangeMinimumQuery {
  int N;
  Vi dat;

  RangeMinimumQuery(int N_) {
    N = 1;
    while (N < N_)
      N <<= 1;
  
    dat.resize(2*N-1, INF);
  }

  void update(int k, int val) {
    k += N - 1;
    dat[k] = val;

    while (k > 0) {
      k = (k - 1) / 2;
      dat[k] = min(dat[2 * k + 1], dat[2 * k + 2]);
    }  
  }

  int query(int a, int b) {
    return query(a, b, 0, 0, N);
  }
  int query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) return INF;
    if (a <= l && r <= b) return dat[k];

    int mid = (l + r) / 2;
    return min(query(a, b, 2 * k + 1, l, mid),
	       query(a, b, 2 * k + 2, mid, r));
  }
};

int imos[300010];
P query[100010];

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;
  REP(i, M) {
    int s, t;
    cin >> s >> t;
    imos[s-1]++, imos[t]--;
    query[i] = P(s-1, t);
  }
  REP(i, N) {
    imos[i+1] += imos[i];
  }

  RangeMinimumQuery segt(N);
  REP(i, N) segt.update(i, imos[i]);

  Vi ans;
  REP(i, M) {
    P p = query[i];
    int q = segt.query(p.first, p.second);
    if (q > 1) ans.push_back(i);
  }

  cout << ans.size() << endl;
  for (int i : ans) cout << i + 1 << endl;
  return 0;
}
