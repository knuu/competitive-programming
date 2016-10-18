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
const int MAX_T = 1e6+1;

int main() {
  int N, Q; scanf("%d %d", &N, &Q);

  // [start_day[i], end_day[i])
  vector<int> start_day(N), end_day(N); REP(i, N) scanf("%d %d", &start_day[i], &end_day[i]), end_day[i]++;

  vector<P> interval(N);
  REP(i, N) interval[i] = P(end_day[i], start_day[i]);
  sort(ALL(interval));

  //REP(i, N) cout << interval[i].first << ',' << interval[i].second << (i == N-1 ? '\n' : ' ');

  vector<int> next_start((int)MAX_T+1, -1);
  int now = 0;
  REP(i, MAX_T+1) {
    while (now < N and interval[now].second < i) now++;
    if (now >= N) break;
    next_start[i] = interval[now].first;
  }

  vector<vector<int>> doubling_next(21, vector<int>(MAX_T+1, -1));
  REP(i, MAX_T+1) doubling_next[0][i] = next_start[i];
  REP(i, 20) REP(j, MAX_T+1) {
    doubling_next[i+1][j] = doubling_next[i][j] < 0 ? -1 : doubling_next[i][doubling_next[i][j]];
  }

  REP(q, Q) {
    int s, t; scanf("%d %d", &s, &t); t++;
    int ans = 0;
    for (int i = 20; i >= 0; i--) {
      //cout << doubling_next[i][s] << (i == 0 ? '\n' : ' ');
      if (doubling_next[i][s] != -1 and doubling_next[i][s] <= t) {
        ans += 1 << i;
        s = doubling_next[i][s];
      }
    }
    printf("%d\n", ans);
  }

  //REP(i, 7) REP(k, 3) cout << doubling_next[k][i] << (k == 2 ? '\n' : ' ');

  return 0;
}
