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

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N; ll X; cin >> N >> X;
  vector<ll> garbage(N); REP(i, N) cin >> garbage[i];
  ll ans = 0;
  priority_queue<ll, vector<ll>, greater<ll>> pque;
  ans += garbage[N - 1] * 5 + X * 2;
  pque.push(2);
  for (int i = N - 2; i >= 0; i--) {
    int k = pque.top(); pque.pop();
    if (X - garbage[i] * (2 * k - 4) > 0) {
      ans += garbage[i] * (2 * k + 1) + X;
      pque.push(k + 1);
    } else {
      ans += garbage[i] * 5 + X * 2;
      pque.push(k);
      pque.push(2);
    }
  }
  cout << ans << endl;
  return 0;
}
