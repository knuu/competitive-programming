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

bool con[7];
ll C[7], E[7];;

void dfs(int v) {
  if (con[v]) return ;
  con[v] = true;
  if (E[v] > 0) dfs((v+1)%7);
  if (E[(v+6)%7] > 0) dfs((v+6)%7);
}

int main() {
  REP(i, 7) cin >> C[i];
  C[0]--;
  ll x = C[0] + C[1] - C[2] + C[3] - C[4] + C[5] - C[6];
  E[0] = x;
  REP(i, 6) E[i+1] = 2 * C[i+1] - E[i];
  REP(i, 7) {
    if (E[i] < 0) {
      cout << "NO" << endl;
      return 0;
    }
  }


  fill(con, con + 7, false);
  dfs(0);

  REP(i, 7) {
    if ((E[i] > 0 || E[(i+6)%7] > 0) && !con[i]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;  
  return 0;
}
