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

ll A, B;
int N;
bool is_disjoint[36][36];

int dfs(int i, bitset<36> bs) {
  if (A + i == B + 1) {
    //REP(j, N) cout << bs[j];
    //cout << endl;
    return 1;
  }
  int ret = dfs(i + 1, bs);
  bool flag = true;
  REP(j, N) {
    if (bs[j] and not is_disjoint[i][j]) {
      flag = false;
      break;
    }
  }
  if (flag) {
    bs.set(i);
    ret += dfs(i + 1, bs);
    bs.reset(i);
  }
  return ret;
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> A >> B;
  N = (int)(B - A) + 1;
  bitset<36> bs(0);
  REP(i, N) FOR(j, i, N) {
    is_disjoint[i][j] = is_disjoint[j][i] = (__gcd(A + (ll)i, A + (ll)j) == 1LL);
  }
  cout << dfs(0, bs) << endl;

  return 0;
}
