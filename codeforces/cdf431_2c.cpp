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

  int K; cin >> K;
  if (K == 0) {
    cout << 'a' << endl;
    return 0;
  }

  vector<int> sq;
  REP(i, 448) sq.emplace_back(i * (i - 1) / 2);
  int cnt = 0;

  vector<pair<char, int>> ans;
  int now = 447;
  while (K > 0) {
    while (sq[now] > K) now--;
    K -= sq[now];
    ans.emplace_back('a' + cnt, now);
    cnt++;
    assert(cnt <= 26);
  }
  for (auto p : ans) {
    char k; int v; tie(k, v) = p;
    REP(j, v) cout << k;
  }
  cout << endl;
  return 0;
}
