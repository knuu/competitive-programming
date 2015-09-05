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

int main() {
  int N, M;
  string S;
  cin >> N >> M;
  cin >> S;

  int i = 0, ans = 0;
  while (i < N) {
    if (S[i] == '.') {
      int start = i;
      while (i < N && S[i] == '.') i++;
      ans += i - start - 1;
    }
    i++;
  }

  REP(i, M) {
    int x;
    char c;
    cin >> x >> c;
    x--;
    if (c == '.' && S[x] != '.') {
      ans += (x < N - 1 && S[x+1] == '.') + (x > 0 && S[x-1] == '.');
    } else if (c != '.' && S[x] == '.') {
      ans -= (x < N - 1 && S[x+1] == '.') + (x > 0 && S[x-1] == '.');
    }
    S[x] = c;
    cout << ans << endl;
  }
  return 0;
}
