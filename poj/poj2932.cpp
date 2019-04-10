#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
// typedef tuple<int, int, int> T;
#define FOR(i, s, x) for (int i = s; i < (int)(x); i++)
#define REP(i, x) FOR(i, 0, x)
#define ALL(c) c.begin(), c.end()
#define DUMP(x) cerr << #x << " = " << (x) << endl
#define UNIQUE(c) sort(ALL(c)), c.erase(unique(ALL(c)), c.end())

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

int main() {
  int N;
  cin >> N;
  vector<pair<double, int>> events;
  vector<double> X(N), Y(N), R(N);
  for (int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i] >> R[i];
    events.emplace_back(X[i] - R[i], i);
    events.emplace_back(X[i] + R[i], i + N);
  }
  sort(ALL(events));

  set<pair<double, double>> circles;
  vector<int> ans;

  for (auto event : events) {
    int idx;
    tie(ignore, idx) = event;
    if (idx < N) {
      auto interval = make_pair(Y[idx] - R[idx], Y[idx] + R[idx]);
      auto it = circles.lower_bound(interval);
      if (it != circles.begin()) {
        it--;
        double st, ed;
        tie(st, ed) = *it;
        if (st < interval.first and interval.second < ed) {
          continue;
        }
      }
      ans.emplace_back(idx);
      circles.insert(interval);
    } else {
      idx %= N;
      auto interval = make_pair(Y[idx] - R[idx], Y[idx] + R[idx]);
      circles.erase(interval);
    }
  }

  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++)
    cout << ans[i] + 1 << (i == ans.size() - 1 ? "\n" : " ");
  return 0;
}