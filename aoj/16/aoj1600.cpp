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

  while (true) {
    int m, n1, n2; cin >> m >> n1 >> n2;
    if (m == 0 and n1 == 0 and n2 == 0) break;
    vector<int> P(m); REP(i, m) cin >> P[i];
    sort(ALL(P));
    int max_gap = -1, max_idx = m - n2 + 1;
    FOR(i, m - n2, m - n1 + 1) {
      if (max_gap < P[i] - P[i-1]) max_gap = P[i] - P[i-1], max_idx = i;
    }
    cout << m - max_idx << endl;
  }

  return 0;
}
