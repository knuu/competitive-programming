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
  vector<pair<int, int>> points;
  REP(i, N) {
    int x, y; cin >> x >> y;
    points.emplace_back(x, y);
  }

  vector<int> count(N, 0);
  const int n_trial = 1e6;
  const double PI = acos(-1);
  const double delta = 2 * PI / n_trial;
  for (double i = 0; i < 2 * PI; i += delta) {
    double x = 1e12 * cos(i), y = 1e12 * sin(i);
    //cout << x << ' ' << y << endl;
    int idx = 0;
    double dist = 1e13;
    REP(i, N) {
      double a, b; tie(a, b) = points[i];
      double cand = hypot(x - a, y - b);
      if (cand < dist) {
        dist = cand;
        idx = i;
      }
    }
    count[idx]++;
  }
  //REP(i, N) cout << count[i] << (i == N - 1 ? '\n' : ' ');
  cout << setprecision(20);
  for (int c : count) cout << 1.0 * c / n_trial << endl;
  return 0;
}
