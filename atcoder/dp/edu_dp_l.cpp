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

const ll INF = 1e18;


ll rec(int left, int right, vector<ll>& A, vector<vector<ll>>& memo) {
  if (left + right == A.size()) {
    return 0;
  }
  if (memo[left][right] != INF) {
    return memo[left][right];
  }

  if ((left + right) % 2 == 0) {
    memo[left][right] = max(rec(left + 1, right, A, memo) + A[left],
                            rec(left, right + 1, A, memo) + A[A.size()-1-right]);
  } else {
    memo[left][right] = min(rec(left + 1, right, A, memo) - A[left],
                            rec(left, right + 1, A, memo) - A[A.size()-1-right]);
  }
  return memo[left][right];
}


int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int N; cin >> N;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  vector<vector<ll>> memo(N, vector<ll>(N, INF));
  cout << rec(0, 0, A, memo) << endl;
  return 0;
}
