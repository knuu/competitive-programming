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
#define MP make_pair
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl
#define fst first
#define snd second

string S[128];

int main() {
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  REP(i, N) cin >> S[i];

  int ans = 0;
  REP(r, N) {
    for (int c = N-1; c >= 0; c--) {
      if (S[r][c] == '.') {
	ans++;
	r++;
	if (r == N) break;
      }
    }
  }

  cout << ans << endl;
  
  return 0;
}
