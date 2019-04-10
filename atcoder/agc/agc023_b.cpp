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
  int N; cin >> N;
  vector<string> S(N);
  REP(i, N) cin >> S[i];
  int ans = 0;
  REP(A, N) {
    vector<string> T(N);
    REP(i, N) T[i] = S[i];
    REP(i, N) REP(j, N) T[(i + A) % N][j] = S[i][j];
    bool flag = true;
    REP(i, N) REP(j, N) {
      flag &= T[i][j] == T[j][i];
    }
    if (flag) ans += N;
  }
  cout << ans << endl;


  return 0;
}
