#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)
#define ALL(c) c.begin(), c.end()
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

const int INF = 7368791;

int main() {
  while (true) {
    int M, N; scanf("%d %d", &M, &N);
    if (N == 0 and M == 0) break;
    vector<bool> P(INF + 1, false);

    for (int i = M, cnt = 0; ; i++) {
      if (not P[i]) {
        if (cnt == N) {
          printf("%d\n", i);
          break;
        }
        for (int j = i; j <= INF; j += i) P[j] = 1;
        cnt++;
      }
    }
  }

  return 0;
}
