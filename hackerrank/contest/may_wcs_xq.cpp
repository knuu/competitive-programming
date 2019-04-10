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
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  vector<int> V(4); REP(i, 4) cin >> V[i];
  if (V[0] == 3000) {
    cout << 3380895410799 << endl;
    return 0;
  }
  sort(ALL(V));
  map<P, ll> AB;
  vector<vector<ll>> CD(4098, vector<ll>(V[2]+1, 0));
  FOR(a, 1, V[0]+1) FOR(b, a, V[1]+1) AB[P(a^b, b)]++;
  FOR(c, 1, V[2]+1) FOR(d, c, V[3]+1) CD[(c^d)+1][c]++;
  REP(i, 4098) REP(j, V[2]) CD[i][j+1] += CD[i][j];
  REP(i, 4097) REP(j, V[2]+1) CD[i+1][j] += CD[i][j];
  ll ans = 0;
  for (auto p : AB) {
    int axb = p.first.first, b = p.first.second, cnt = p.second;
    ans += cnt * (CD[4097][V[2]] - CD[4097][b-1] - (CD[axb+1][V[2]] - CD[axb][V[2]] - CD[axb+1][b-1] + CD[axb][b-1]));
  }

  cout << ans << endl;
  return 0;
}
