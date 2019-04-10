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

  int N, T; cin >> N >> T;
  string S; cin >> S;
  int now = 0, dec = 0;
  while (S[now] != '.') now++;
  dec = now;
  while (now < N and S[now] - '0' < 5) now++;
  int over = now;

  now = dec+1;
  while (now < over) {
    if (S[now] == '4' and T > 1) {
      int cnt = 0;
      while (now < over and S[now] == '4') now++, cnt = min(T-1, cnt+1);
      if (now != N and S[now] - '0' >= 5) {
        over = now - cnt;
        break;
      }
    }
    now++;
  }

  vector<char> ans;
  bool cnt_up = now != N;
  for (int i = over-1; i >= 0; i--) {
    if (S[i] == '.') {
      if (ans.size()) ans.push_back(S[i]);
    } else {
      int d = S[i] - '0';
      if (cnt_up) d++;
      assert(d <= 10);
      if (d == 10) {
        if (ans.size() or i < dec) ans.push_back('0');
      } else {
        ans.push_back(d + '0');
        cnt_up = false;
      }
    }
  }
  if (cnt_up) ans.push_back('1');

  for (int i = (int)ans.size() - 1; i >= 0; i--) cout << ans[i];
  cout << endl;
  return 0;
}
