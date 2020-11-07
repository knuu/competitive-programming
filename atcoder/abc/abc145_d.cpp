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
const ll mod = 1e9 + 7;

map<pair<int, int>, ll> memo;

ll rec(int x, int y) {
  if (x == 0 and y == 0) {
    return 1;
  } else if (x <= 0 or y <= 0) {
    return 0;
  }
  auto it = memo.find(make_pair(x, y));
  if (it != memo.end()) {
    return it->second;
  }

  ll ret = rec(x-1, y-2) + rec(x-2, y-1);
  ret = ret % mod;
  memo[make_pair(x, y)] = ret;
  return ret;
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int X, Y; cin >> X >> Y;


  cout << rec(X, Y) << endl;
  return 0;
}
