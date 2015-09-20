#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)

pair<int, int> fuels[10010];

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, L, tank;
  cin >> N;
  REP(i, N) {
    int pos, oil;
    cin >> pos >> oil;
    fuels[i] = make_pair(pos, oil);
  }
  cin >> L >> tank;

  sort(fuels, fuels+N);
  priority_queue<int> pque;
  int ans = 0, now = L - tank, i = N-1;

  while (now > 0) {

    while (i >= 0 && fuels[i].first >= now) {
      pque.push(fuels[i].second);
      i--;
    }
    if (pque.empty()) {
      cout << -1 << endl;
      return 0;
    }
    now -= pque.top(); pque.pop();
    ans++;
  }
  cout << ans << endl;
  return 0;
}
