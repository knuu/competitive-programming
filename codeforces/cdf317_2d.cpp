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

int A[300010];
int dp[5010][5010];
int small_members, large_members;

int group_members(int l, int s) {
  return l * large_members + s * small_members;
}

int main() {
  int n, k;

  scanf("%d %d", &n, &k);
  REP(i, n) scanf("%d", &A[i]);

  sort(A, A+n);

  int large_groups = n % k, small_groups = k - n % k;
  small_members = n / k, large_members = n / k + 1;

  REP(l, large_groups + 1) {
    REP(s, small_groups + 1) {
      if (l == 0 && s == 0) {
	continue;
      } else if (l == 0) {
	dp[0][s] = dp[0][s-1] + abs(A[group_members(0, s-1)] - A[group_members(0, s) - 1]);
      } else if (s == 0) {
	dp[l][0] = dp[l-1][0] + abs(A[group_members(l-1, 0)] - A[group_members(l, 0) - 1]);
      } else {
	  dp[l][s] = min(dp[l][s-1] + abs(A[group_members(l, s-1)] - A[group_members(l, s) - 1]),
			   dp[l-1][s] + abs(A[group_members(l-1, s)] - A[group_members(l, s) - 1]));
      }
    }
  }

  printf("%d\n", dp[large_groups][small_groups]);
  /*  REP(l, large_groups+1) {
    REP(s, small_groups+1) {
      cout << dp[l][s] << ' ';
    }
    cout << endl;
    }//*/
  return 0;
}
