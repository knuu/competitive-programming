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
  string S; cin >> S;

  vector<vector<bool>> ans(3);
  ans[0].resize(10);
  ans[1].resize(100);
  ans[2].resize(1000);

  for (char c : S) {
    int x = c - '0';
    REP(i, 100) {
      if (ans[1][i]) {
        ans[2][i * 10 + x] = true;
      }
    }
    REP(i, 10) {
      if (ans[0][i]) {
        ans[1][i * 10 + x] = true;

      }
    }
    ans[0][x] = true;
  }

  int num = 0;
  REP(i, 1000) num += ans[2][i];
  cout << num << endl;
  return 0;
}
