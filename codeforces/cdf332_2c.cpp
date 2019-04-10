#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
typedef tuple<int, int, int> T;
#define FOR(i,s,x) for(ll i=s;i<(ll)(x);i++)
#define REP(i,x) FOR(i,0,x)
#define ALL(c) c.begin(), c.end()
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

P height[100010];
int H[100010];
ll idx[100010];

int main() {
  int N;
  scanf("%d", &N);
  REP(i, N) {
    scanf("%d", H+i);
    height[i] = P(H[i], i+1);
  }
  sort(height, height + N);
  REP(i, N) idx[i+1] = height[i].second;
  REP(i, N) idx[i+1] += idx[i];

  ll ans = 0;
  FOR(i, 1LL, N+1LL) if (i * (i + 1) / 2LL == idx[i]) ans++;
  cout << ans << endl;    
  return 0;
}
