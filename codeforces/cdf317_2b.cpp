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

int stock[2][100010];
bool top_s[2][100010];
int inputs[1024];
char dir[1024];

int main() {
  int N, S;
  cin >> N >> S;

  REP(i, 2) REP(j, 100001) {
    stock[i][j] = 0;
    top_s[i][j] = false;
  }
  
  
  REP(i, N) {
    char d;
    int p, q;
    cin >> d >> p >> q;
    dir[i] = d;
    inputs[i] = p;
    stock[d == 'S'][p] += q;
  }

  int s_tops = 0;
  for (int i = 0; i <= 100000 && s_tops < S; i++) {
    if (stock[1][i] > 0) {
      s_tops++;
      top_s[1][i] = true;
    }
  }

  for (int i = 100000; i >= 0; i--) {
    if (top_s[1][i]) {
      printf("S %d %d\n", i, stock[1][i]);
    }
  }  

  int b_tops = 0;
  for (int i = 100000; i >= 0 && b_tops < S; i--) {
    if (stock[0][i] > 0) {
      b_tops++;
      top_s[0][i] = true;
      printf("B %d %d\n", i, stock[0][i]);
    }
  }

  return 0;
}
