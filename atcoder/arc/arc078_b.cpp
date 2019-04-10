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

int N;
vector<int> edge[100010];
int path[100010], profits[100010];


pair<int, int> dfs(int v, int p) {
  path[v] = p;
  if (v == N - 1) return make_pair(0, 1);
  int a = 0, b = 0;
  for (int c : edge[v]) {
    if (c != p) {
      pair<int, int> tmp = dfs(c, v);
      a += tmp.first;
      b += tmp.second;
    }
  }

  //cout << v << ':' << a << ' ' << b << endl;
  profits[v] = a + 1;
  if (b > 0) {
    return make_pair(0, 1);
  } else {
    return make_pair(a + 1, 0);
  }
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;
  REP(i, N - 1) {
    int a, b; cin >> a >> b; a--, b--;
    edge[b].emplace_back(a);
    edge[a].emplace_back(b);
  }

  dfs(0, -1);
  vector<int> route;
  int v = N - 1;
  while (v != -1) {
    route.emplace_back(v);
    v = path[v];
  }

  //REP(i, N) cout << profits[i] << (i == N - 1 ? '\n' : ' ');

  vector<bool> used(N, false);
  vector<int> now = {(int)route.size() - 1, 0};
  int money = 0, turn = 0;

  while (true) {
    int v = route[now[turn]];
    //cout << v << ' ' << turn << ' ' << endl;
    if (used[v]) break;
    used[v] = true;
    if (turn == 0) {
      money += profits[v];
      now[turn]--;
    } else {
      now[turn]++;
    }
    turn ^= 1;
  }

  //cout << money << endl;
  cout << (money > N - money ? "Fennec" : "Snuke") << endl;
  return 0;
}
