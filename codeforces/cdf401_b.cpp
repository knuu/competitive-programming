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

  int N; cin >> N;
  vector<int> cards[2];
  REP(i, 2) {
    string S; cin >> S;
    for (char s : S) cards[i].push_back(s - '0');
  }

  REP(i, 2) sort(ALL(cards[i]));
  swap(cards[0], cards[1]);
  int ans = 0, now = N - 1;
  for (int i = N - 1; i >= 0; i--) {
    while (now >= 0 and cards[1][i] < cards[0][now]) now--;
    if (now < 0) break;
    ans++;
    now--;
  }
  cout << N - ans << endl;

  ans = 0, now = 0;
  REP(i, N) {
    while (now < N and cards[0][i] >= cards[1][now]) now++;
    if (now >= N) break;
    ans++;
    now++;
  }
  cout << ans << endl;

  return 0;
}
