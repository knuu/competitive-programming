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

int mat[100010][2], row[100010], col[100010];

int main() {
  int N;
  scanf("%d", &N);
  REP(i, N) {
    REP(j, 2) scanf("%d", mat[i]+j), mat[i][j]--;
    col[mat[i][0]]++, col[mat[i][1]+1]--;
  }
  int sum = 0;
  REP(i, N) {
    row[i] = mat[i][1] - mat[i][0] + 1;
    sum += row[i];
    col[i+1] += col[i];
  }

  int Q;
  scanf("%d", &Q);
  REP(i, Q) {
    int x, y;
    scanf("%d %d", &x, &y); x--, y--;
    printf("%s\n", ((sum - row[x] - col[y] + (mat[x][0] <= y && y <= mat[x][1])) % 2 ? "O" : "E"));
  }
  return 0;
}
