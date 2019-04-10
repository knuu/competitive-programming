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
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, K; cin >> N >> K;
  vector<int> knight(N); REP(i, N) cin >> knight[i];
  vector<ll> coin(N); REP(i, N) cin >> coin[i];
  vector<tuple<int, ll, int>> k_c(N); REP(i, N) k_c[i] = make_tuple(knight[i], coin[i], i);
  sort(ALL(k_c));
  vector<ll> ans(N);
  priority_queue<ll, vector<ll>, greater<ll>> pque;
  ll sum = 0;
  for (auto t : k_c) {
    int idx; ll c; tie(ignore, c, idx) = t;
    ans[idx] = sum + c;
    pque.emplace(c);
    sum += c;
    if ((int)pque.size() > K) {
      sum -= pque.top();
      pque.pop();
    }
  }
  REP(i, N) cout << ans[i] << (i == N - 1 ? '\n' : ' ');

  return 0;
}
