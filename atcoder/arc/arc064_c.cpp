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

  double xs, ys, gx, gy; cin >> xs >> ys >> gx >> gy;
  int N; cin >> N;
  vector<double> X(N), Y(N), R(N); REP(i, N) cin >> X[i] >> Y[i] >> R[i];
  vector<double> dist(N);
  REP(i, N) dist[i] = max(0.0, hypot(xs - X[i], ys - Y[i]) - R[i]);
  priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pque;
  REP(i, N) pque.emplace(dist[i], i);
  vector<bool> used(N, false);
  int rest = N;
  while (rest > 0) {
    int idx; tie(ignore, idx) = pque.top(); pque.pop();
    if (used[idx]) continue;
    used[idx] = true;
    rest--;
    for (int i = 0; i < N; i++) {
      double d = max(0.0, hypot(X[idx] - X[i], Y[idx] - Y[i]) - R[idx] - R[i]);
      if (dist[i] > dist[idx] + d) {
        dist[i] = dist[idx] + d;
        pque.emplace(dist[i], i);
      }
    }
  }
  double ans = hypot(xs - gx, ys - gy);
  REP(i, N) {
    ans = min(ans, dist[i] + max(0.0, hypot(X[i] - gx, Y[i] - gy) - R[i]));
  }
  cout << setprecision(20) << ans << endl;
  return 0;
}
