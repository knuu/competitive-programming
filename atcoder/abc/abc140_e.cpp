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
  vector<int> P(N), order(N);
  REP(i, N) cin >> P[i], P[i]--, order[P[i]] = i;

  std::multiset<int> bin_tree = {-1, -1, N, N};
  ll ans = 0;
  bin_tree.emplace(order[N-1]);
  for (int i = N-2; i >= 0; i--) {
    ll p = i+1;
    int idx = order[i];

    bin_tree.emplace(idx);
    auto it = bin_tree.lower_bound(idx);
    auto next_it = next(it), next_next_it = next(next_it);
    auto prev_it = prev(it), prev_prev_it = prev(prev_it);

    ll n_left, n_right;
    // it => left, next_it => right
    n_left = *it - *prev_it;
    n_right = *next_next_it - *next_it;
    ans += n_left * n_right * p;
    // prev_it => left, it => right
    n_left = *prev_it - *prev_prev_it;
    n_right = *next_it - *it;
    ans += n_left * n_right * p;
  }
  cout << ans << endl;

  return 0;
}
