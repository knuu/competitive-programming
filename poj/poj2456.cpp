#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)

int N, M;
int pos[100010];

bool check(int d) {
  int prev = 0, cow = 1;
  FOR(i, 1, N) {
    if (pos[i] - pos[prev] >= d) {
      cow++;
      prev = i;
    }
  }
  return cow >= M;
}    

int solve() {
  int left = 0, right = pos[N-1]+1;
  while (left + 1 < right) {
    int mid = (left + right) / 2;
    if (check(mid)) {
      left = mid;
    } else {
      right = mid;
    }
  }
  return left;
}

int main() {
  scanf("%d %d", &N, &M);
  REP(i, N) scanf("%d", pos+i);
  sort(pos, pos+N);

  cout << solve() << endl;

  return 0;
}
