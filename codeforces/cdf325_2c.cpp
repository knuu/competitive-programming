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

int V[4096], D[4096], C[4096];
bool run[4096];

int main() {

  int N;
  cin >> N;
  REP(i, N) scanf("%d %d %d", V+i, D+i, C+i);
  Vi ans;

  fill(run, run+N, false);
  REP(i, N) {
    while (i < N && run[i] == true) i++;
    if (i == N) break;
    ans.push_back(i);
    run[i] = true;
    int cnt = V[i], now = i+1;
    queue<int> ready;
    while (now < N && cnt > 0) {
      // cout << now << ' ' << cnt << endl;
      while (now < N && run[now] == true) now++;
      if (now == N) break;
      C[now] -= cnt;
      // cout << 0 << ' ' << now << ' ' << C[now];
      if (C[now] < 0) {
	ready.push(now);
	run[now] = true;
      }
      now++, cnt--;
    }

    while (!ready.empty()) {
      int to_run = ready.front(); ready.pop();
      FOR(j, to_run + 1, N) {
	C[j] -= D[to_run];
	if (!run[j] && C[j] < 0) {
	  ready.push(j);
	  run[j] = true;
	}
      }
    }
    // REP(i, N) cout << run[i] << (i == N-1 ? '\n' : ' ');
    // REP(i, N) cout << C[i] << (i == N-1 ? '\n' : ' ');
  }
  cout << ans.size() << endl;
  REP(i, ans.size()) cout << ans[i] + 1 << (i == (int)ans.size() - 1 ? '\n' : ' ');
  return 0;
}
