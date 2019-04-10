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
  int N; scanf("%d", &N);

  vector<int> pos(N);
  vector<string> dir(N);
  REP(i, N) cin >> pos[i] >> dir[i];

  REP(i, N) REP(j, N) {
    if (pos[i] < pos[j] and dir[i][0] == '-' and dir[j][0] == '+') {
      cout << 2 << endl;
      return 0;
    }
  }

  cout << 1 << endl;
  return 0;
}
