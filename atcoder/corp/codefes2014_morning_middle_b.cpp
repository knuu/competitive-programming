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

int guest[100010][2];

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, M; cin >> N >> M;
  vector<T> time_line(N + M);
  REP(i, N) {
    REP(j, 2) cin >> guest[i][j];
    time_line.push_back(T(guest[i][0], -1, i));
  }
  REP(i, M) {
    int a; cin >> a;
    time_line.push_back(T(a, 0, i));
  }
  sort(ALL(time_line));  
  priority_queue<int> last;
  int ans = 0;
  for (T ts : time_line) {
    int t, p, i; tie(t, p, i) = ts;
    if (p == -1) {
      last.push(-guest[i][1]);
    } else {
      while (not last.empty() and -last.top() < t) last.pop();
      if (not last.empty()) ans++, last.pop();
    }
  }
  cout << ans << endl;  
  return 0;
}
