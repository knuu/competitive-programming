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

  ll N, D; cin >> N >> D;
  vector<int> X(N); REP(i, N) cin >> X[i];
  ll ans = N * (N - 1) * (N - 2) / 6;
  for (int i = 0; i < N; i++) {
    ll lb = lower_bound(X.begin(), X.end(), X[i] + D) - X.begin();
    if (lb == N or X[lb] - X[i] > D) lb--;
    ll cnt1 = max<ll>(0, (lb - i - 1) * (lb - i) / 2);
    ans -= cnt1;

    ll lb2 = lower_bound(X.begin(), X.end(), X[i] + D + 1) - X.begin();
    ll cnt2 = 0;
    cnt2 = (N - lb2) * i;
    ans -= cnt2;

    ll lb3 = lower_bound(X.begin(), X.end(), X[i] - D - 1) - X.begin();
    if (X[i] - X[lb3] <= D) lb3--;
    ll cnt3 = 0;
    cnt3 = (lb3 + 1) * (N - 1 - i);
    ans -= cnt3;

    ans += (lb3 + 1) * (N - lb2);
    //cout << i << ' ' << lb << ',' << cnt1 << ' ' << lb2 << ',' << cnt2 << ' ' << lb3 << ',' << cnt3 << endl;
  }
  cout << ans << endl;
  return 0;
}
