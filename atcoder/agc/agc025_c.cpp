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

  ll N; cin >> N;
  priority_queue<pair<ll, ll>> left, right;
  vector<pair<ll, ll>> interval(N);
  REP(i, N) {
    ll l, r; cin >> l >> r;
    interval[i] = make_pair(l, r);
    left.emplace(-r, i);
    right.emplace(l, i);
  }
  vector<bool> used(N, false);
  ll now = 0;
  int rest = N;
  ll ans = 0;
  while (rest > 0) {
    int l, li; tie(l, li) = left.top();
    while (used[li]) {
      left.pop();
      tie(l, li) = left.top();
    }
    l = -l;
    int l_ = interval[li].first;
    if (abs(l_ - now) < abs(l - now)) {
      l = l_;
    }
    int r, ri; tie(r, ri) = right.top();
    while (used[ri]) {
      right.pop();
      tie(r, ri) = right.top();
    }
    int r_ = interval[ri].second;
    if (abs(r_ - now) < abs(r - now)) {
      r = r_;
    }

    if (abs(r - now) > abs(l - now)) {
      ans += abs(r - now);
      now = r;
      right.pop();
      used[ri] = true;
      cout << ri << ' ' << ans << endl;
    } else {
      ans += abs(l - now);
      now = l;
      left.pop();
      used[li] = true;
      cout << li << ' ' << ans << endl;
    }
    rest--;
  }
  cout << ans << endl;

  return 0;
}
