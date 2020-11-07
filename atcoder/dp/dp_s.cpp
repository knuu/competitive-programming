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

int D;
string K;
ll dp[10001][100][2];

ll rec(int idx, int modulo, bool flag) {
  if (idx == K.size()) return modulo == 0;
  if (dp[idx][modulo][flag] != -1) return dp[idx][modulo][flag];

  ll ret = 0;
  if (flag == 1) {
    ret = rec(idx + 1, (modulo + D - (K[idx] - '0')) % D, true);
    REP(i, K[idx] - '0') {
      ret = (ret + rec(idx + 1, (modulo + D - i) % D, false)) % mod;
    }
  } else {
    REP(i, 10) {
      ret = (ret + rec(idx + 1, (modulo + D - i) % D, false)) % mod;
    }
  }
  dp[idx][modulo][flag] = ret;
  return ret;
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> K >> D;
  memset(dp, -1, sizeof(dp));
  cout << (rec(0, 0, true) + mod - 1) % mod << endl;

  return 0;
}
