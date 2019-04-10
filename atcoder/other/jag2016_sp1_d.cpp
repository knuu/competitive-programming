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

int N, M;
vector<int> A, B;
map<P, int> memo[51][51][2];

int dfs(int a, int b, int sa, int sb, int t) {

  //cout << a << ' ' << b << ' ' << sa << ' ' << sb << ' ' << t << endl;
  if (t == 0 and a == N) {
    int ret = sa - sb;
    FOR(i, b, M) if (B[i] != -1) ret -= B[i];
    //cout << a << ' ' << b << ' ' << sa << ' ' << sb << ' ' << t << ':' << ret << endl;
    return ret;
  } else if (t == 1 and b == M) {
    int ret = sa - sb;
    FOR(i, a, N) if (A[i] != -1) ret += A[i];
    //cout << a << ' ' << b << ' ' << sa << ' ' << sb << ' ' << t << ':' << ret << endl;
    return ret;
  }
  if (memo[a][b][t].find(P(sa, sb)) != memo[a][b][t].end()) {
    return memo[a][b][t][P(sa, sb)];
  }
  vector<int> ret;
  if (t == 0) {
    if (sa > 0) ret.push_back((sa - sb) + dfs(a, b, 0, 0, t^1));
    if (a < N) {
      if (A[a] == -1) {
        ret.push_back(dfs(a+1, b, sa, 0, 1));
      } else {
        ret.push_back(dfs(a+1, b, sa+A[a], sb, 1));
      }
    }
    //cout << a << ' ' << b << ' ' << sa << ' ' << sb << ' ' << t << ':' << (ret.size() ? *max_element(ALL(ret)) : 0) << endl;
    int r = ret.size() ? *max_element(ALL(ret)) : 0;
    memo[a][b][t][P(sa, sb)] = r;
    return r;
  } else {
    if (sb > 0) ret.push_back((sa - sb) + dfs(a, b, 0, 0, t^1));
    if (b < M) {
      if (B[b] == -1) {
        ret.push_back(dfs(a, b+1, 0, sb, 0));
      } else {
        ret.push_back(dfs(a, b+1, sa, sb+B[b], 0));
      }
    }
    //cout << a << ' ' << b << ' ' << sa << ' ' << sb << ' ' << t << ':' << (ret.size() ? *max_element(ALL(ret)) : 0) << endl;
    int r = ret.size() ? *min_element(ALL(ret)) : 0;
    memo[a][b][t][P(sa, sb)] = r;
    return r;
  }
  return 0;
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> N >> M;
  A.resize(N), B.resize(M);
  REP(i, N) cin >> A[i];
  REP(i, M) cin >> B[i];

  cout << dfs(0, 0, 0, 0, 0) << endl;

  return 0;
}
