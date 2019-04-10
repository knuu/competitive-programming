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
  map<int, ll> row, col;
  map<P, ll> points;
  REP(i, N) {
    int x, y; scanf("%d %d", &x, &y);
    row[x]++, col[y]++;
    points[P(x, y)]++;
  }
  ll ans = 0;
  for (auto p : row) {
    ll k = p.second;
    ans += k * (k - 1) / 2;
  }
  for (auto p : col) {
    ll k = p.second;
    ans += k * (k - 1) / 2;
  }
  for (auto p : points) {
    ll k = p.second;
    ans -= k * (k - 1) / 2;
  }
  cout << ans << endl;
  return 0;
}
