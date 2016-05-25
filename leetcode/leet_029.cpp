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

class Solution {
public:
  int divide(int dividend, int divisor) {
    if (dividend == INT_MIN and divisor == -1) {
      return INT_MAX;
    }
    int sign = 1;
    if ((dividend < 0 and divisor > 0) or (dividend > 0 and divisor < 0)) {
      sign = -1;
    }
    if (dividend < 0) dividend = -dividend;
    if (divisor < 0) divisor = -divisor;
    long long ans = 0, now = 0;
    for (long long i =  30; i >= 0; i--) {
      long long p2 = divisor << i;
      if (p2 > 0 and now + p2 <= dividend) {
        ans += 1 << i;
        now += divisor << i;
      }
    }
    return sign == 1 ? ans : (~ans + 1);
  }
};
int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  Solution s;
  cout << s.divide(-5, -3) << ' ' << -5/-3 << endl;
  cout << s.divide(99, 1) << endl;
  cout << s.divide(99, 0) << endl;
  return 0;
}
