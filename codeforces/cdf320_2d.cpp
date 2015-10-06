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

ll N, K, X;
ll A[200010];
int bit[100];
int bitbit[100];

int main() {
  int t1, t2, t3;
  scanf("%d %d %d", &t1, &t2, &t3);
  N = (ll)t1, K = (ll)t2, X = (ll)t3;
  REP(i, N) {
    int t;
    scanf("%d", &t);
    A[i] = (ll)t;
    for (int i = 0; t; t>>=1, i++) {
      bit[i] += t&1;
    }      
  }

  ll ans = 0;
  REP(i, N) {
    REP(j, 100) bitbit[j] = bit[j];
    ll t = A[i];
    for (int j = 0; t; t /= 2, j++) {
      bitbit[j] -= t&1;
    }
    ll cand = A[i];
    REP(j, K) cand *= X;
    REP(j, 100) cand |= (1<<j) * (bitbit[j] > 0);
    ans = max(ans, cand);
  }
  cout << ans << endl;

  return 0;
}
