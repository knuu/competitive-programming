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
  int M = (1 << N);
  vector<int> A(M); REP(i, M) cin >> A[i];
  vector<int> ans(M, 0);

  priority_queue<pair<int, int>> pque;
  REP(i, M) {
    pque.emplace(A[i], i);
  }

  pair<int, int> prev = pque.top();
  pque.pop();
  while (not pque.empty()) {
    int a1, idx1; tie(a1, idx1) = prev;
    pair<int, int> now = pque.top();
    pque.pop();
    int a2, idx2; tie(a2, idx2) = now;
    cout << a1 << ' ' << idx1 << ' ' << a2 << ' ' << idx2 << ' ' << (idx1 | idx2) << endl;
    for (int i = (idx1 | idx2); i < (1 << N) and ans[i] == 0; i++) {
      ans[i] = a1 + a2;
    }
    prev = now;
  }

  FOR(i, 1, (1 << N)) {
    cout << ans[i] << endl;
  }



  return 0;
}
