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
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl

int place[10010], next_p[10010];

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int M, L;
  string s;
  cin >> s >> M;
  L = s.size();
  REP(i, L) place[i] = i;
  REP(i, M) {
    int l, r, k;
    cin >> l >> r >> k; l--, r--;
    int loop = r - l + 1;
    REP(j, L) {
      if (l <= j && j <= r) {
	next_p[(j - l + k) % loop + l] = place[j];
      } else {
	next_p[j] = place[j];
      }
    }
    REP(j, L) place[j] = next_p[j];
  }
  string ans = s;
  REP(i, L) ans[i] = s[place[i]];
  cout << ans << endl;    
  return 0;
}
