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
#define UNIQUE(c) sort(ALL(c)), c.erase(unique(ALL(c)), c.end())

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

using Monster = tuple<int, int, bool>;

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, M; cin >> N >> M;
  vector<Monster> monsters(N + M);
  REP(i, N) {
    int a, b; cin >> a >> b;
    monsters[i] = make_tuple(a, b, false);
  }
  REP(i, M){
    int a, b; cin >> a >> b;
    monsters[N+i] = make_tuple(a, b, true);
  }
  double t = 0.0, fcost, gcost;
  for (;; t = fcost / gcost) {
    sort(monsters.begin(), monsters.end(), [t](Monster m1, Monster m2) {
      return std::get<1>(m1) - t * std::get<0>(m1) > std::get<1>(m2) - t * std::get<0>(m2); });
    bool flag = false;
    int rest = 5;
    fcost = gcost = 0.0;
    for (int i = 0; i < N + M and rest > 0; i++) {
      int a, b; bool c; tie(a, b, c) = monsters[i];
      if (c and flag) continue;
      rest--;
      if (c) flag = true;
      fcost += b;
      gcost += a;
    }

    if (std::abs(fcost - t * gcost) < 1e-7) {
      break;
    }
  }
  printf("%.07f\n", t);
  return 0;
}
