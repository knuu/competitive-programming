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

int N;
double memo[301][301][301];


double rec(int i, int j, int k) {
  if (i < 0 or j < 0 or k < 0) {
    return 0.0;
  }
  if (i + j + k == 0) {
    return 0.0;
  }
  if (memo[i][j][k] >= 0.0) {
    return memo[i][j][k];
  }

  double s = i + j + k;

  return memo[i][j][k] = (i * rec(i-1, j, k) + j * rec(i+1, j-1, k) + k * rec(i, j+1, k-1) + N) / s;
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;
  vector<int> sushi(3, 0);
  REP(i, N+1) REP(j, N+1) REP(k, N+1) memo[i][j][k] = -1.0;
  REP(i, N) {
    int a; cin >> a; a--;
    sushi[a]++;
  }
  cout << setprecision(20) << rec(sushi[0], sushi[1], sushi[2]) << endl;

  return 0;
}
