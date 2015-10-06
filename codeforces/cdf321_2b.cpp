#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
typedef tuple<int, int, int> T;
#define FOR(i,s,x) for(int i=s;i<(ll)(x);i++)
#define REP(i,x) FOR(i,0,x)
#define ALL(c) c.begin(), c.end()
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl

Pll friends[100010];

int main() {
  // use scanf in CodeForces!

  int tmp1, tmp2;
  scanf("%d %d", &tmp1, &tmp2);
  ll N = (ll)tmp1, D = (ll)tmp2;
  REP(i, N) {
    scanf("%d %d", &tmp1, &tmp2);
    friends[i] = make_pair((ll)tmp1, (ll)tmp2);
  }
  sort(friends, friends + N);

  int left = 0, right = 0;
  ll sum = 0, ans = 0;
  //REP(i, N) cout << friends[i].first << ' ' << friends[i].second << endl;
  while (right < N) {
    //    cout << left << ' ' << right << endl;
    while (right < N && friends[right].first - friends[left].first < D) {
      sum += friends[right].second;
      right++;
    }
    ans = max(ans, sum);
    if (right == N) break;

    while (left < right && friends[right].first - friends[left].first >= D) {
      sum -= friends[left].second;
      left++;
    }
  }
  cout << ans << endl;
  return 0;
}
