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

int main() {
  int N, M; scanf("%d %d", &N, &M);
  vector<vector<int>> cols(M, vector<int>(N));
  REP(i, N) REP(j, M) {
    scanf("%d", &cols[j][i]);
  }

  REP(i, M) cols[i].emplace_back(-1);

  vector<vector<int>> range(N);
  REP(i, M) {
    int l = 0;
    for (int j = 0; j < N; j++) {
      if (cols[i][j] > cols[i][j + 1]) {
        range[l].emplace_back(j);
        l = j + 1;
      }
    }
  }

  int Q; scanf("%d", &Q);
  vector<vector<pair<int, int>>> query(N);
  REP(i, Q) {
    int l, r; scanf("%d %d", &l, &r), l--, r--;
    query[l].emplace_back(r, i);
  }

  vector<bool> ans(Q);

  set<int> right;
  REP(i, N) {
    for (int r : range[i]) right.insert(r);
    for (pair<int, int> p : query[i]) {
      int r, idx; tie(r, idx) = p;
      if (right.lower_bound(r) != right.end()) {
        ans[idx] = true;
      } else {
        ans[idx] = false;
      }
    }
  }

  REP(i, Q) printf(ans[i] ? "Yes\n" : "No\n");
  return 0;
}
