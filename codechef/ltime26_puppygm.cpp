#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
typedef tuple<int, int, int> T;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)
#define ALL(c) c.begin(), c.end()
#define MP make_pair
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl
#define fst first
#define snd second

int memo[10010][10010];

int dfs(int s1, int s2) {
  if (s1 == 1 && s2 == 1) return -1;
  if (memo[s1][s2]) return memo[s1][s2];

  FOR(j, 1, s1/2+1) {
    if (dfs(j, s1-j) == -1) {
      memo[s1][s2] = 1;
      return 1;
    }
  }
  FOR(j, 1, s2/2+1) {
    if (dfs(j, s2-j) == -1) {
      memo[s1][s2] = 1;
      return 1;
    }
  }
  memo[s1][s2] = -1;
  return -1;
}			    

int main() {
  int T;
  cin >> T;
  REP(i, T) {
    int A, B;
    cin >> A >> B;
    if (A > B) swap(A, B);
    if (dfs(A, B) == 1) {
      cout << "Tuzik" << endl;
    } else {
      cout << "Vanka" << endl;
    }
  }
  return 0;
}
