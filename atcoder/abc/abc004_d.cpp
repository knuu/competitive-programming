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

int cost(int left, int right) {
  int ret = 0;
  for (int i = left; i <= right; i++) ret += abs(i);
  return ret;
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int R, G, B; cin >> R >> G >> B;
  int ans = INT_MAX;
  for (int g_left = -1000; g_left <= 1000; g_left++) {
    int g_right = g_left + G - 1;
    int r_right = min(-100 + (R - 1) / 2, g_left - 1), r_left = r_right - R + 1;
    int b_left = max(100 - (B - 1) / 2, g_right + 1), b_right = b_left + B - 1;
    ans = min(ans, cost(r_left + 100, r_right + 100) + cost(g_left, g_right) + cost(b_left - 100, b_right - 100));
  }
  cout << ans << endl;
  return 0;
}
