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

ll man[100010];
ll N, M;

inline bool check(ll ltime) {
  ll prev = 0;
  REP(i, M) {
    ll left = man[i] - prev;
    if (left > ltime) return false;
    if (left >= 0) {
      prev = max(prev + ltime - left, man[i] + (ltime - left) / 2) + 1;
    } else {
      prev = max(prev, man[i] + ltime + 1);
    }
    if (prev >= N) return true;
  }
  return prev >= N;
}


int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;

  REP(i, M) {
    cin >> man[i];
    man[i]--;
  }

  ll left = -1, right = 2*N+1;
  while (left + 1 < right) {
    //cout << left << ' ' << right << endl;
    int mid = (left + right) / 2;
    if (check(mid)) {
      right = mid;
    } else {
      left = mid;
    }
  }

  cout << right << endl;
  return 0;
}
