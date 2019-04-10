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

  int T; cin >> T;
  REP(testcase, T) {
    int N, L; cin >> N >> L;
    vector<bool> is_ceil(N + 1);
    REP(i, N + 1) {
      int x = 1000 * i / N;
      is_ceil[i] = x % 10 >= 5;
    }
    vector<int> cnt(N + 1, 0);
    int sum = 0;
    REP(i, L) {
      int x; cin >> x;
      sum += x;
      cnt[x]++;
    }
    cnt[0] = N - sum;
    vector<int> right_ceil(N + 1, 1e9);
    int right = 1e9;
    for (int i = N; i >= 0; i--) {
      if (is_ceil[i]) {
        right = i;
      }
      right_ceil[i] = right;
    }
    vector<pair<int, int>> dist;
    REP(i, N) {
      REP(j, cnt[i]) {
        dist.emplace_back(right_ceil[i] - i, i);
      }
    }
    sort(ALL(dist));
    /*
    for (auto p : dist) {
      cout << p.first << ' ' << p.second << endl;
    }
    */
    int res = N - sum;
    for (int i = 0; i < N and res > 0; i++) {
      int cost, idx; tie(cost, idx) = dist[i];
      if (cost <= res) {
        res -= cost;
        cnt[idx]--;
        cnt[idx + cost]++;
      } else {
        cnt[1] += res;
        res = 0;
      }
    }
    int ans = 0;
    FOR(i, 1, N + 1) {
      int d = i * 1000 / N;
      if (d % 10 >= 5) {
        ans += (d / 10 + 1) * cnt[i];
      } else {
        ans += d / 10 * cnt[i];
      }
    }

    cout << "Case #" << testcase + 1 << ": " << ans << endl;
  }

  return 0;
}
