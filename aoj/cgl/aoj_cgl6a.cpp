#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>

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

template <typename T>
struct RangeSumQuery {
  int N;
  std::vector<T> dat;

  RangeSumQuery(int N) : N(N) {
    assert(N > 0);
    dat.resize(N, 0);
  }

  void add(int k, T val) {
    assert(0 <= k && k < N);
    for (int x = k; x < N; x |= x + 1) {
      dat[x] += val;
    }
  }

  // [0, k)
  T sum(int k) {
    assert(k >= 0);
    T ret = 0;
    for (int x = k - 1; x >= 0; x = (x & (x + 1)) - 1) {
      ret += dat[x];
    }
    return ret;
  }
  // [l, r)
  T sum(int l, int r) {
    assert(0 <= l && l <= r && r <= N);
    return sum(r) - sum(l);
  }

  T index(int k) {
    assert(0 <= k && k < N);
    return sum(k + 1) - sum(k);
  }
};

void compress(vector<int> &arr1, vector<int> &arr2) {
  vector<int> tmp;
  for (int x : arr1) tmp.emplace_back(x);
  for (int x : arr2) tmp.emplace_back(x);
  UNIQUE(tmp);
  map<int, int> mp;
  REP(i, tmp.size()) mp[tmp[i]] = i;
  REP(i, arr1.size()) arr1[i] = mp[arr1[i]];
  REP(i, arr2.size()) arr2[i] = mp[arr2[i]];
}

int main() {
  int N;
  cin >> N;
  vector<int> X1(N), X2(N), Y1(N), Y2(N);
  REP(i, N) cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
  compress(Y1, Y2);

  vector<tuple<int, int, int>> events;

  REP(i, N) {
    if (X1[i] > X2[i]) swap(X1[i], X2[i]);
    if (Y1[i] > Y2[i]) swap(Y1[i], Y2[i]);

    if (X1[i] == X2[i]) {
      events.emplace_back(X1[i], 1, i);
    } else {
      events.emplace_back(X1[i], 0, i);
      events.emplace_back(X2[i], 2, i);
    }
  }

  sort(ALL(events));

  ll ans = 0;
  RangeSumQuery<ll> rsq(N);
  for (auto event : events) {
    int t, idx;
    tie(ignore, t, idx) = event;
    if (t == 0) {
      rsq.add(Y1[idx], 1);
    } else if (t == 1) {
      ans += rsq.sum(Y1[idx], min(N, Y2[idx] + 1));
    } else {
      rsq.add(Y1[idx], -1);
    }
  }

  cout << ans << endl;
  return 0;
}