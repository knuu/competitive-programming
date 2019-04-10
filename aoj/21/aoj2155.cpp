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

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  while (1) {
    int N, M; cin >> N >> M;
    if (N == 0 and M == 0) break;
    vector<T> packets(M);
    REP(i, M) {
      int t, s, d; cin >> t >> s >> d; s--, d--;
      packets[i] = T(t, s, d);
    }
    sort(ALL(packets));
    vector<bool> infected(N, false);
    infected[0] = true;
    for (T packet : packets) {
      int t, s, d; tie(t, s, d) = packet;
      infected[d] =  infected[d] | infected[s];
    }
    cout << accumulate(ALL(infected), 0) << endl;
  }

  return 0;
}
