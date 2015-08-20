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

int N;
int D[100010];
int mod = 1000000007;
ll memo[100010][4];

int dfs(int dif, int p_num) {
  if (p_num == 4) return 1;
  if (dif == -1) return 0;
  if (memo[dif][p_num] != -1) return memo[dif][p_num];

  ll ret = 0;
  ret += dfs(dif-1, p_num);
  ret += dfs(upper_bound(D, D+N, D[dif] / 2.0) - D - 1, p_num + 1);
  return memo[dif][p_num] = ret % mod;
}

int main() {
  cin >> N;
  REP(i, N) cin >> D[i];
  sort(D, D+N);

  REP(i, N) REP(j, 4) memo[i][j] = -1;
  cout << dfs(N-1, 0) << endl;

  return 0;
}
