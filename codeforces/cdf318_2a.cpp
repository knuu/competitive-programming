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
  int N, Limak, ans = 0;
  priority_queue<int> pque;

  scanf("%d", &N);
  scanf("%d", &Limak);
  REP(i, N-1) {
    int c;
    scanf("%d", &c);
    pque.push(c);
  }

  while (Limak <= pque.top()) {
    int c = pque.top();
    pque.pop();
    Limak++; c--; ans++;
    pque.push(c);
  }

  printf("%d\n", ans);
  return 0;
}
