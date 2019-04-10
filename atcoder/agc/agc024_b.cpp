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
#define UNIQUE(c) sort(ALL(c)), c.erase(unique(ALL(c)), c.end())

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int N; cin >> N;
  vector<int> P(N); REP(i, N) cin >> P[i], P[i]--;
  vector<int> rev_P(N); REP(i, N) rev_P[P[i]] = i;
  int ans = 1, now = 1;
  REP(i, N - 1) {
    if (rev_P[i] < rev_P[i + 1]) {
      now++;
    } else {
      ans = max(ans, now);
      now = 1;
    }
  }
  ans = max(ans, now);
  cout << N - ans << endl;
  return 0;
}
