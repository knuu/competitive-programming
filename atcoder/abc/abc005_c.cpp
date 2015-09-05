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

int main() {
  int T, N, A[128], M, B[128];;
  scanf("%d %d", &T, &N);
  REP(i, N) scanf("%d", &A[i]);
  scanf("%d", &M);
  REP(i, M) scanf("%d", &B[i]);
  
  int now = 0;
  REP(i, M) {
    while (now < N && B[i] > A[now] + T) now++;
    
    if (now == N || B[i] < A[now]) {
      printf("no\n");
      return 0;
    }
    now++;
  }
  printf("yes\n");

  return 0;
}
