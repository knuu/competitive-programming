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

map<pair<int, int>, int> half_enum(vector<tuple<int, int, int>>& arr) {
  map<pair<int, int>, int> mp;
  REP(state, 1 << arr.size()) {
    int sum_a = 0, sum_b = 0, cost = 0;
    REP(i, arr.size()) {
      if (state >> i & 1) {
        int a, b, c; tie(a, b, c) = arr[i];
        sum_a += a;
        sum_b += b;
        cost += c;
      }
    }
    pair<int, int> p = make_pair(sum_a, sum_b);
    auto it = mp.find(p);
    if (it == mp.end()) {
      mp[p] = cost;
    } else if (cost < it->second){
      it->second = cost;
    }
  }
  return mp;
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int N, Ma, Mb; cin >> N >> Ma >> Mb;
  vector<tuple<int, int, int>> arr(N);
  REP(i, N) {
    int a, b, c; cin >> a >> b >> c;
    arr[i] = make_tuple(a, b, c);
  }

  int N1 = N / 2, N2 = N - N1;
  vector<tuple<int, int, int>> arr1(arr.begin(), arr.begin() + N1);
  vector<tuple<int, int, int>> arr2(arr.begin() + N1, arr.end());

  map<pair<int, int>, int> mp1 = half_enum(arr1), mp2 = half_enum(arr2);
  const int INF = 1e5;
  int cost = INF;
  for (auto p : mp1) {
    int a, b, c = p.second; tie(a, b) = p.first;
    for (int k = 1; k * Ma <= 400 and k * Mb <= 400; k++) {
      int res_a = k * Ma - a, res_b = k * Mb - b;
      pair<int, int> res = make_pair(res_a, res_b);
      auto it = mp2.find(res);
      if (it == mp2.end()) continue;
      cost = min(cost, c + it->second);
    }
  }

  cout << (cost == INF ? -1 : cost) << endl;
  return 0;
}
