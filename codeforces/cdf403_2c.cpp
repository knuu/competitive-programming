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
  int N; scanf("%d", &N);
  vector<vector<int>> edge(N);
  REP(i, N - 1) {
    int s, t; scanf("%d %d", &s, &t), s--, t--;
    edge[s].emplace_back(t), edge[t].emplace_back(s);
  }

  int K = 0;
  REP(i, N) K = max(K, (int)edge[i].size() + 1);

  vector<int> color(N, -1);
  vector<bool> done(N, false);
  queue<int> que;
  que.emplace(0);
  color[0] = 0;
  while (not que.empty()) {
    int v = que.front(); que.pop();
    if (done[v]) continue;
    done[v] = true;

    int d = edge[v].size();
    vector<bool> used(d + 1, false);
    if (0 <= color[v] and color[v] <= d) used[color[v]] = true;
    for (int c : edge[v]) {
      if (0 <= color[c] and color[c] <= d) used[color[c]] = true;
    }
    vector<int> res; REP(i, d + 1) if (not used[i]) res.emplace_back(i);
    for (int c : edge[v]) {
      if (color[c] == -1) color[c] = res.back(), res.pop_back();
      if (not done[c]) que.emplace(c);
    }
  }

  printf("%d\n", K);
  REP(i, N) {
    if (i) printf(" ");
    printf("%d", color[i] + 1);
  }
  printf("\n");


  return 0;
}
