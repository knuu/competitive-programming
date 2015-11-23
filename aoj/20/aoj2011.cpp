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
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

int N;
bool s[50][50];

bool check() {
  REP(i, N) {
    bool flag = true;
    REP(j, N) flag &= s[i][j];
    if (flag) return true;
  }
  return false;
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  while (true) {
    cin >> N;
    if (N == 0) break;
    Vi edge[30];
    REP(i, N) {
      int c;
      cin >> c;
      REP(j, c) {
	int k;
	cin >> k; k--;
	edge[k].push_back(i);
      }
    }

    REP(i, N) fill(s[i], s[i] + N, false);
    REP(d, 30) {
      for (int i : edge[d]) {
	for (int j : edge[d]) {
	  s[i][j] = true;
	  REP(k, N) s[i][k] |= s[j][k];
	}
      }
      if (check()) {
	cout << d + 1 << endl;
	break;
      } else if (d == 29) {
	cout << -1 << endl;
	break;
      }
    }	
  }
  return 0;
}
