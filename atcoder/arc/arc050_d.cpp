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

struct SuffixArray {
  int N, k;
  string S;
  vector<int> sa, rank, tmp;
  vector<int> lcp, rank_lcp;
  SuffixArray(string S) : S(S) {
    N = S.size();
    sa.resize(N+1), rank.resize(N+1), tmp.resize(N+1);
    construct_sa();
  }

  bool compare_sa(int i, int j) {
    if (rank[i] != rank[j]) {
      return rank[i] < rank[j];
    } else {
      int ri = i + k <= N ? rank[i + k] : -1;
      int rj = j + k <= N ? rank[j + k] : -1;
      return ri < rj;
    }
  }

  void construct_sa() {
    for (int i = 0; i <= N; i++) {
      sa[i] = i;
      rank[i] = i < N ? S[i] : -1;
    }

    for (k = 1; k <= N; k *= 2) {
      sort(sa.begin(), sa.end(), [&] (const int & i, const int & j) { return compare_sa(i, j); });

      tmp[sa[0]] = 0;
      for (int i = 1; i <= N; i++) {
        tmp[sa[i]] = tmp[sa[i-1]] + (compare_sa(sa[i-1], sa[i]) ? 1 : 0);
      }
      for (int i = 0; i <= N; i++) rank[i] = tmp[i];
    }
  }

  bool contain(string T) {
    int left = 0, right = N;
    while (left - right > 1) {
      int mid = (left + right) / 2;
      (S.compare(sa[mid], T.length(), T) < 0 ? left : right) = mid;
    }
    return S.compare(sa[right], T.length(), T) == 0;
  }

  void construct_lcp() {
    lcp.resize(N), rank_lcp.resize(N+1);
    for (int i = 0; i <= N; i++) rank_lcp[sa[i]] = i;

    int h = 0;
    lcp[0] = 0;
    for (int i = 0; i < N; i++) {
      int j = sa[rank[i] - 1];

      if (h > 0) h--;
      for (; j + h < N and i + h < N; h++) {
        if (S[j + h] != S[i + h]) break;
      }

      lcp[rank[i] - 1] = h;
    }
  }
};


const int INF = 1<<29;

/*
  RangeMinimumQuery by Segment Tree
  query:
  1. update(i, val): update i-th value to val(0-indexrd)
  2. query(low, high): find minimun value in [low, high)
  time complexity: O(log n)
  space complexity: O(2n)
  used in DSL2A(AOJ)
*/
template<typename T> struct RangeMinQuery {
  int N, _N;
  vector<T> dat;

  RangeMinQuery(int _N) : _N(_N) {
    assert(_N > 0);
    N = 1;
    while (N < _N)
      N <<= 1;
    dat.assign(2 * N - 1, 0);
  }

  void update(int k, T val) {
    assert(0 <= k && k < _N);
    k += N - 1;
    dat[k] = val;

    while (k > 0) {
      k = (k - 1) / 2;
      dat[k] = min(dat[2 * k + 1], dat[2 * k + 2]);
    }
  }

  // [a, b)
  T query(int a, int b) {
    return query(a, b, 0, 0, N);
  }
  T query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) return INF;
    if (a <= l && r <= b) return dat[k];

    int mid = (l + r) / 2;
    return min(query(a, b, 2 * k + 1, l, mid),
               query(a, b, 2 * k + 2, mid, r));
  }
};

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N; cin >> N;
  string S; cin >> S;
  SuffixArray sa(S);
  sa.construct_lcp();

  RangeMinQuery<int> lcp(N);
  REP(i, N) lcp.update(i, sa.lcp[i]);

  vector<int> perm(N);
  iota(ALL(perm), 0);

  function<bool(int, int)> compare = [&](int i, int j) {
    if (i > j) return not compare(j, i);
    if (lcp.query(min(sa.rank[i], sa.rank[j]), max(sa.rank[i], sa.rank[j])) < N - j) {
      return sa.rank[i] < sa.rank[j];
    } else if (lcp.query(min(sa.rank[i + (N - j)], sa.rank[i]), max(sa.rank[i + (N - j)], sa.rank[i])) < j - i) {
      return sa.rank[i + (N - j)] < sa.rank[i];
    } else {
      return false;
    }
  };

  sort(ALL(perm), compare);
  REP(i, N) cout << perm[i] + 1 << endl;

  return 0;
}
