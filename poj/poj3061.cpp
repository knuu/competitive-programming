#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)

#define INF (int)1e5

int A[100010];
int main() {
  int N, S, T;
  scanf("%d", &T);

  REP(t, T) {
		 
    scanf("%d %d", &N, &S);
    REP(i, N) scanf("%d", A+i);

    int ans = INF;
    int left = 0, right = 0, sum = 0;
    while (1) {
      while (right < N && sum < S) {
	sum += A[right];
	right++;
      }

      if (sum < S) break;
      while (left < right && sum >= S) {
	sum -= A[left];
	left++;
      }
      ans = min(ans, right - left + 1);
    }

    cout << (ans == INF ? 0 : ans) << endl;
  }
  return 0;
}
