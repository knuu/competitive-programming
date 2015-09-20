#include <iostream>
#include <queue>

using namespace std;
typedef long long int ll;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N;
  priority_queue<ll, vector<ll>, greater<ll> > pque;

  cin >> N;
  REP(i, N) {
    ll p;
    cin >> p;
    pque.push(p);
  }

  ll ans = 0;
  while (pque.size() > 1) {
    ll p1 = pque.top(); pque.pop();
    ll p2 = pque.top(); pque.pop();
    ans += p1 + p2;
    pque.push(p1+p2);
  }
  cout << ans << endl;
  return 0;
}
