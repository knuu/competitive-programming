#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)
#define ALL(c) c.begin(), c.end()

struct SuffixArray {
  int n, k;
  string S;
  vector<int> sa, rank, tmp;
  SuffixArray(string S) : S(S) {
    n = S.size();
    sa.resize(n+1), rank.resize(n+1), tmp.resize(n+1);
    construct_sa();
  }

  bool compare_sa(int i, int j) {
    if (rank[i] != rank[j]) {
      return rank[i] < rank[j];
    } else {
      int ri = i + k <= n ? rank[i + k] : -1;
      int rj = j + k <= n ? rank[j + k] : -1;
      return ri < rj;
    }
  }

  void construct_sa() {
    for (int i = 0; i <= n; i++) {
      sa[i] = i;
      rank[i] = i < n ? S[i] : -1;
    }

    for (k = 1; k <= n; k *= 2) {
      sort(sa.begin(), sa.end(), [&] (const int & i, const int & j) { return compare_sa(i, j); });

      tmp[sa[0]] = 0;
      for (int i = 1; i <= n; i++) {
        tmp[sa[i]] = tmp[sa[i-1]] + (compare_sa(sa[i-1], sa[i]) ? 1 : 0);
      }
      for (int i = 0; i <= n; i++) rank[i] = tmp[i];
    }
  }

  bool contain(string T) {
    int left = 0, right = n;
    while (left - right > 1) {
      int mid = (left + right) / 2;
      (S.compare(sa[mid], T.length(), T) < 0 ? left : right) = mid;
    }
    return S.compare(sa[right], T.length(), T) == 0;
  }
};

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N; cin >> N;
  string S(N, '\0');
  REP(i, N) {
    int x; cin >> x;
    S[i] = x;
  }

  string rev_S(N, '\0'); reverse_copy(ALL(S), rev_S.begin());
  SuffixArray sa(rev_S);

  int p1;
  REP(i, N) {
    p1 = N - sa.sa[i];
    if (p1 >= 1 and N - p1 >= 2) break;
  }

  int rest = N - p1;
  string rev_S2(2 * rest, '\0');
  reverse_copy(S.begin() + p1, S.end(), rev_S2.begin());
  reverse_copy(S.begin() + p1, S.end(), rev_S2.begin() + rest);
  SuffixArray sa2(rev_S2);

  int p2;
  REP(i, 2 * rest + 1) {
    p2 = p1 + rest - sa2.sa[i];
    if (p2 - p1 >= 1 and N - p2 >= 1) break;
  }

  reverse(S.begin(), S.begin() + p1);
  reverse(S.begin() + p1, S.begin() + p2);
  reverse(S.begin() + p2, S.end());

  REP(i, N) cout << S[i] - '\0' << endl;
  return 0;
}
