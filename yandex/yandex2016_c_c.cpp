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

int main() {

  ll N, M; scanf("%lld %lld", &N, &M);
  vector<ll> A(N), B(N), C(N); REP(i, N) scanf("%lld %lld %lld", &A[i], &B[i], &C[i]);

  ll now = M, lb = M, cnt = 0;
  REP(i, N) {
    cnt++;
    if (now > A[i]) {
      now += B[i];
    } else {
      now = max<ll>(0, now - C[i]);
      if (now <= lb) {
        printf("-1\n");
        return 0;
      }
      ll diff = now - lb;
      ll left = 0, right = 1e9;
      while (left + 1LL < right) {
        ll mid = (left + right) >> 1;
        (diff * mid + C[i] + now > A[i] ? right : left) = mid;
      }
      cnt += right * (i + 1);
      now += right * diff + C[i];
      lb = now - C[i] - diff;
    }
  }
  cout << cnt << endl;
  return 0;
}
