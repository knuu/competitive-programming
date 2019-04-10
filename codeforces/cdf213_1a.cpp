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

  int N; cin >> N;
  string s; cin >> s;
  
  int L = s.size();
  vector<int> mat(L+1, 0);
  REP(i, L) mat[i+1] = s[i] - '0', mat[i+1] += mat[i];

  vector<ll> counter(40000, 0);
  REP(i, L+1) FOR(j, i+1, L+1) counter[mat[j]-mat[i]]++;

  ll ans = 0;
  REP(i, 40000) {
    if (N == 0) ans += counter[0] * counter[i];
    if (i != 0 and N % i == 0 and N / i < 40000) ans += counter[i] * counter[N/i];
  }
  cout << ans << endl;
  return 0;
}
