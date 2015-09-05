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
#define MP make_pair
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl
#define fst first
#define snd second

vector<P> edge(4010);
bool adj[4010][4010];
int degree[4010];

int main() {
  int N, M;
  scanf("%d %d", &N, &M);
  edge.resize(M);

  REP(i, M) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--; b--;
    edge[i] = make_pair(a, b);
    adj[a][b] = adj[b][a] = true;
    degree[a]++, degree[b]++;
  }

  int ans = 3 * N;
  for (auto e : edge) {
    int a = e.first, b = e.second;
    REP(i, N) {
      if (adj[a][i] && adj[b][i]) {
	ans = min(ans, degree[a] + degree[b] + degree[i] - 6);
      }
    }
  }

  if (ans == 3 * N) {
    printf("-1\n");
  } else {
    printf("%d\n", ans);
  }
  return 0;
}
