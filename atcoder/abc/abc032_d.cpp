#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)
#define ALL(c) c.begin(), c.end()

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N; cin >> N;
  ll W; cin >> W;
  const ll INF = 1e18;
  vector<ll> v(N), w(N);
  bool f1 = true, f2 = true;
  REP(i, N) {
    cin >> v[i] >> w[i];
    f1 &= v[i] <= 1000;
    f2 &= w[i] <= 1000;
  }
  if (N <= 30) {
    int N2 = N / 2;
    vector<pair<ll, ll>> ps(1 << N2);
    REP(i, 1 << N2) {
      ll sw = 0, sv = 0;
      REP(j, N2) if (i >> j & 1) sw += w[j], sv += v[j];
      ps[i] = make_pair(sw, sv);
    }
    sort(ALL(ps));
    int m = 1;
    for (int i = 1; i < (1 << N2); i++) {
      if (ps[m-1].second < ps[i].second) ps[m++] = ps[i];
    }
    ps.resize(m);

    ll ans = 0;
    for (int i = 0; i < (1 << (N - N2)); i++) {
      ll sw = 0, sv = 0;
      REP(j, N - N2) if (i >> j & 1) sw += w[N2+j], sv += v[N2+j];
      if (sw <= W) {
        ans = max(ans, sv + (lower_bound(ps.begin(), ps.end(), make_pair(W-sw, INF)) - 1) -> second);
      }
    }
    cout << ans << endl;
  } else if (f2) {
    W = min<int>(W, accumulate(w.begin(), w.end(), 0));
    vector<vector<ll>> dp(N+1, vector<ll>(W+1, 0));
    REP(i, N) REP(j, W+1) {
      if (j - w[i] >= 0) {
        dp[i+1][j] = max(dp[i][j], dp[i][j-w[i]] + v[i]);
      } else {
        dp[i+1][j] = dp[i][j];
      }
    }
    cout << *max_element(dp[N].begin(), dp[N].end())  << endl;
  } else if (f1) {
    int V = accumulate(v.begin(), v.end(), 0);
    vector<vector<ll>> dp(N + 1, vector<ll> (V + 1, INF));
    dp[0][0] = 0;
    REP(i, N) REP(j, V + 1) {
      if (j - v[i] >= 0) {
        dp[i+1][j] = min(dp[i][j], dp[i][j-v[i]] + w[i]);
      } else {
        dp[i+1][j] = dp[i][j];
      }
    }
    ll ans = 0;
    REP(i, V + 1) if (dp[N][i] <= W) ans = i;
    cout << ans << endl;
  }
  return 0;
}
