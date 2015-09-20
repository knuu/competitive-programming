#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <string>

using namespace std;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)

int N;
int dir[5010];
int rot[5010];

int main() {
  scanf("%d", &N);
  REP(i, N) {
    string a;
    cin >> a;
    dir[i] = (a == "B");
  }
  int K = N, M = N;
  FOR(k, 1, N+1) {
    int r = 0, rot_sum = 0;
    fill(rot, rot+N, 0);
    REP(i, N-k+1) {
      if ((dir[i] + rot_sum) % 2 != 0) {
	rot[i]++;
	r++;
      }
      rot_sum += rot[i];
      if (i+1-k >= 0) rot_sum -= rot[i+1-k];
    }

    FOR(i, N-k+1, N) {
      if ((dir[i] + rot_sum) % 2 != 0) {
	r = -1;
	break;
      }
      rot_sum += rot[i];
      if (i+1-k >= 0) rot_sum -= rot[i+1-k];
    }
    
    if (r != -1 && r < M) {
      M = r;
      K = k;
    }
  }

  printf("%d %d\n", K, M);  
  return 0;
}
