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
  int month_day[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  assert(accumulate(month_day, month_day+13, 0) == 366);
  REP(i, 12) {
    month_day[i+1] += month_day[i];
  }

  bool holiday[512];
  fill(holiday, holiday+512, false);

  holiday[0] = true;
  for (int i = 6; i < 366; i += 7) {
    holiday[i] = holiday[i+1] = true;
  }

  int N;
  scanf("%d\n", &N);
  REP(i, N) {
    int m, d;
    scanf("%d/%d\n", &m, &d);
    int year_day = month_day[m-1] + d - 1;
    while (holiday[year_day]) year_day++;
    holiday[year_day] = true;
  }

  int dp[367][2];
  REP(i, 367) dp[i][0] = dp[i][1] = 0;

  REP(i, 366) {
    dp[i+1][1] = (dp[i][1] + 1) * holiday[i];
    dp[i+1][0] = max(dp[i][0], dp[i+1][1]);
  }

  cout << dp[366][0] << endl;
  //  REP(i, 367) cout << dp[i][1] << ' ';
  //  cout << endl;
  return 0;
}
