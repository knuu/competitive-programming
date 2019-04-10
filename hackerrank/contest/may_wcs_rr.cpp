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

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int N, K; cin >> N >> K;
  string S; cin >> S;
  int L = S.size();
  int cnt = 0;
  for (int i = 0, j = L-1; i < j; i++, j--) cnt += S[i] != S[j];
  if (K < cnt) {
    cout << -1 << endl;
    return 0;
  }
  string ans(L, 0);
  for (int i = 0, j = L-1; i < j; i++, j--) {
    if (S[i] != S[j]) {
      K--;
      ans[i] = ans[j] = max(S[i], S[j]);
    }
  }

  for (int i = 0, j = L-1; i <= j; i++, j--) {
    if (i == j) {
      if (K < 1 or S[i] == '9') continue;
      ans[i] = '9';
      K--;
    } else if (ans[i] == 0) {
      if (K < 2 or S[i] == '9') continue;
      ans[i] = ans[j] = '9';
      K -= 2;
    } else {
      if (K < 1 or ans[i] == '9') continue;
      ans[i] = ans[j] = '9';
      K--;
    }
  }
  REP(i, L) if (ans[i] == 0) ans[i] = S[i];
  cout << ans << endl;
  return 0;
}
