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

int N;
vector<T> adj;
bool used[1024];
int ans[1024];

int main() {
  scanf("%d", &N);
  fill(used, used+2*N, false);
  

  for (int i = 1; i < 2*N; i++) {
    for (int j = 0; j < i; j++) {
      int c;
      scanf("%d", &c);
      adj.push_back(T(c, i, j));
    }
  }
  sort(ALL(adj));
  for (int t = (int)adj.size()-1; t >= 0; t--) {
    int c, i, j;
    tie(c, i, j) = adj[t];
    if (!used[i] && !used[j]) {
      ans[i] = j;
      ans[j] = i;
      used[i] = used[j] = true;
    }
  }

  REP(i, 2*N) cout << ans[i]+1 << (i==2*N-1 ? '\n' : ' ');

  return 0;
}
