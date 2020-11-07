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
  vector<int> A(N); REP(i, N) cin >> A[i];
  int max_A = *max_element(ALL(A));
  vector<vector<int>> pos(max_A);
  REP(i, N) pos[A[i]-1].emplace_back(i);

  int now_p = -1, cnt = 0;
  REP(i, max_A) {
    if (pos[i].size() == 0) break;
    int next_p = N;

    for (int p : pos[i]) {
      if (p > now_p and p < next_p) next_p = p;
    }

    if (next_p == N) break;
    cnt++;
    now_p = next_p;
  }
  if (cnt == 0) {
    cout << -1 << endl;
  } else {
    cout << N - cnt << endl;
  }

  return 0;
}
