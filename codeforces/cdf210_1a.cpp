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

int upper[5010], now[5010], check[5010];
int ope[5010][4];

int main() {

  int N, M; scanf("%d %d", &N, &M);
  fill(upper, upper + N, (int)1e9);
  REP(m, M) {
    int t, l, r, v; scanf("%d %d %d %d", &t, &l, &r, &v); l--, r--;
    ope[m][0] = t, ope[m][1] = l, ope[m][2] = r, ope[m][3] = v;
    if (t == 1) {
      FOR(i, l, r+1) now[i] += v;
    } else {
      FOR(i, l, r+1) upper[i] = min(upper[i], v - now[i]);
    }
  }

  REP(i, N) check[i] = upper[i];
  REP(m, M) {
    int t = ope[m][0], l = ope[m][1], r = ope[m][2], v = ope[m][3];
    if (t == 1) {
      FOR(i, l, r+1) check[i] += v;
    } else {
      int max_val = -(int)1e9;
      FOR(i, l, r+1) {
	max_val = max(max_val, check[i]);
      }
      if (max_val != v) {
	//cout << max_val << ' ' << v << endl;
	printf("NO\n");
	return 0;
      }
    }
  }    
  printf("YES\n");
  REP(i, N) printf("%d%c", upper[i], (i == N-1 ? '\n' : ' '));
  return 0;
}
