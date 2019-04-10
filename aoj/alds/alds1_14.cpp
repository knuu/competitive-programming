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
    construct();
  }

  void construct() {
    for (int i = 0; i <= N; i++) {
      sa[i] = i;
      rank[i] = i < N ? S[i] : -1;
    }

    function<bool(int, int)> compare = [&](int i, int j) {
      if (rank[i] != rank[j]) {
        return rank[i] < rank[j];
      } else {
        int ri = i + k <= N ? rank[i + k] : -1;
        int rj = j + k <= N ? rank[j + k] : -1;
        return ri < rj;
      }
    };
    for (k = 1; k <= N; k *= 2) {
      sort(sa.begin(), sa.end(), compare);

      tmp[sa[0]] = 0;
      for (int i = 1; i <= N; i++) {
        tmp[sa[i]] = tmp[sa[i-1]] + (compare(sa[i-1], sa[i]) ? 1 : 0);
      }
      for (int i = 0; i <= N; i++) rank[i] = tmp[i];
    }
  }

  bool contain(string T) {
    int left = 0, right = N;
    while (left + 1 < right) {
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


int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  string T; cin >> T;
  SuffixArray sa(T);
  int Q; cin >> Q;
  REP(_, Q) {
    string P; cin >> P;
    cout << sa.contain(P) << endl;
  }

  return 0;
}
