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

Vi edge[100010];
int N, M;
bool cats[100010];

int dfs(int s, int par, int cnt) {
  if (cnt == M && cats[s]) return 0;
  if (edge[s].size() == 1 && edge[s][0] == par) return 1;

  int ret = 0;
  for (int next : edge[s]) {
    if (next != par)
      ret += dfs(next, s, (cats[s] ? cnt + 1 : 0));
  }
  return ret;
}  

int main() {
  // use scanf in CodeForces!

  scanf("%d %d", &N, &M);
  REP(i, N) {
    int c;
    scanf("%d", &c);
    cats[i] = (c ? true : false);
  }
  REP(i, N-1) {
    int s, t;
    scanf("%d %d", &s, &t);
    s--, t--;
    edge[s].push_back(t);
    edge[t].push_back(s);
  }

  printf("%d\n", dfs(0, -1, 0));

  return 0;
}
