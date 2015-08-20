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

#define MAX_V 100010

int V;
ll dist[5][MAX_V];
vector<P> edge[MAX_V];

void dfs(int from, int n) {
  
  REP(i, edge[from].size()) {
    P to = edge[from][i];
    if (dist[n][to.fst] == -1) {
      dist[n][to.fst] = dist[n][from] + to.snd;
      dfs(to.fst, n);
    }
  }
  return ;
}

int main() {
  cin >> V;
  REP(i, V-1) {
    ll A, B, C;
    cin >> A >> B >> C;
    edge[A-1].push_back(make_pair(B-1, C));
    edge[B-1].push_back(make_pair(A-1, C));
  }
  REP(i, V) dist[0][i] = dist[1][i] = dist[2][i] = -1;

  
  dist[0][0] = 0;
  dfs(0, 0);
  
  int d1;
  ll d = -1;
  REP(i, V) {
    if (dist[0][i] > d)
      d1 = i, d = dist[0][i];
  }
  
  dist[1][d1] = 0;
  dfs(d1, 1);
  
  int d2;
  d = -1;
  REP(i, V) {
    if (dist[1][i] > d)
      d2 = i, d = dist[1][i];
  }
  dist[2][d2] = 0;
  dfs(d2, 2);

  REP(i, V) {
    if (dist[1][i] > dist[2][i] || (dist[1][i] == dist[2][i] && d1 < d2)) {
      cout << d1+1 << endl;
    } else {
      cout << d2+1 << endl;
    }
  }  
  return 0;
}
