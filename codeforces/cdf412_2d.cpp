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

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

int base_score(int x, int n) {
  if (n < 2 * x) {
    return 500;
  } else if (n < 4 * x) {
    return 1000;
  } else if (n < 8 * x) {
    return 1500;
  } else if (n < 16 * x) {
    return 2000;
  } else if (n < 32 * x) {
    return 2500;
  } else {
    return 3000;
  }
}

int calc_score(int x, int n, int t) {
  if (t == -1) {
    return 0;
  } else {
    return base_score(x, n) - base_score(x, n) * t / 250;
  }
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N; cin >> N;
  vector<vector<int>> A(N, vector<int>(5));
  vector<int> ac_count(5, 0);
  REP(i, N) REP(j, 5) {
    cin >> A[i][j];
    if (A[i][j] != -1) ac_count[j]++;
  }

  REP(i, 5000) {
    int p1 = 0, p2 = 0;
    REP(j, 5) {
      if (A[0][j] != -1 and A[1][j] != -1 and A[0][j] > A[1][j]) {
        p1 += calc_score(ac_count[j] + i, N + i, A[0][j]);
        p2 += calc_score(ac_count[j] + i, N + i, A[1][j]);
      } else {
        p1 += calc_score(ac_count[j], N + i, A[0][j]);
        p2 += calc_score(ac_count[j], N + i, A[1][j]);
      }
    }
    if (p1 > p2) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;

  return 0;
}
