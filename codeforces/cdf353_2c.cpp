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
  int N; cin >> N;
  ll sum = 0;
  int ans = 0;
  map<ll, int> cnt;
  REP(i, N) {
    ll a; scanf("%lld", &a);
    sum += a;
    ans = max(ans, ++cnt[sum]);
  }
  printf("%d\n", N-ans);
  return 0;
}
