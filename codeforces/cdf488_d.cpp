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

int deduce(vector<pair<int, int>> A1, vector<pair<int, int>> A2) {
  int ans = -1;
  for (auto p1 : A1) {
    int xa, ya; tie(xa, ya) = p1;
    int cnt1 = 0, cnt2 = 0;
    for (auto p2 : A2) {
      int xb, yb; tie(xb, yb) = p2;
      if (p1 == p2) continue;
      if (xa == xb or xa == yb) cnt1++;
      if (ya == xb or ya == yb) cnt2++;
    }
    if (min(cnt1, cnt2) > 0) {
      return -1;
    }
    if (cnt1 >= 1 and cnt2 == 0) {
      ans = (ans == -1 or ans == xa ? xa : 0);
    }
    if (cnt1 == 0 and cnt2 >= 1) {
      ans = (ans == -1 or ans == ya ? ya : 0);
    }
  }
  return ans;
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int N, M; cin >> N >> M;
  vector<pair<int, int>> A1(N), A2(M);
  REP(i, N) {
    int x, y; cin >> x >> y;
    if (x > y) swap(x, y);
    A1[i] = make_pair(x, y);
  }
  REP(i, M) {
    int x, y; cin >> x >> y;
    if (x > y) swap(x, y);
    A2[i] = make_pair(x, y);
  }

  int ans1 = deduce(A1, A2);
  if (ans1 > 0) {
    cout << ans1 << endl;
    return 0;
  }
  int ans2 = deduce(A2, A1);
  if (ans2 > 0) {
    cout << ans2 << endl;
    return 0;
  }
  cout << min(ans1, ans2) << endl;
  return 0;
}
