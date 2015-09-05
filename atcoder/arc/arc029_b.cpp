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

bool check(int A, int B, int C, int D) {
  if (A > B) swap(A, B);
  if (C > D) swap(C, D);

  if (A > C) return false;
  if (B <= D) return true;

  double left = 0.0, right = acos(-1) / 2;
  REP(i, 100) {
    double mid = (left + right) / 2;
    if (A * cos(mid) + B * sin(mid) <= D) {
      left = mid;
    } else {
      right = mid;
    }
  }
  return C - (A * sin(left) + B * cos(left)) >= 0;
}

int main() {
  int A, B, N;
  scanf("%d %d %d", &A, &B, &N);
  REP(i, N) {
    int C, D;
    scanf("%d %d", &C, &D);
    printf(check(A, B, C, D) ? "YES\n" : "NO\n");
  }
    
  return 0;
}
