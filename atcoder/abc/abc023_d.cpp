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

ll N;
ll H[100010], S[100010];
int over[100010];

bool check(ll height) {
  fill(over, over + N, 0);
  REP(i, N) {
    if (height < H[i]) return false;
    over[min(N-1, (height - H[i]) / S[i])]++;
  }
  int cnt = 0;
  REP(i, N) {
    cnt += over[i];
    if (cnt > i+1) return false;
  }
  return true;
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;
  REP(i, N) cin >> H[i] >> S[i];

  ll left = 0, right = 1000000000000000;
  while (left + 1 < right) {
    ll mid = (left + right) / 2;
    if (check(mid)) {
      right = mid;
    } else {
      left = mid;
    }
  }
  cout << right << endl;    
  return 0;
}
