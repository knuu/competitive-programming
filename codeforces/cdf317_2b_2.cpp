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
  int n, s;
  map<int, int> buy, sell;
  scanf("%d %d\n", &n, &s);
  REP(i, n) {
    char d;
    int p, q;
    scanf("%c %d %d\n", &d, &p, &q);
    if (d == 'B') {
      buy[-p] += q;
    } else if (d == 'S') {
      sell[p] += q;
    }
  }

  int count = 0;
  map<int, int> rev_sell;
  for (auto it = sell.begin(); it != sell.end() && count < s; it++, count++) {
    rev_sell[-(it->first)] = it->second;
  }
  count = 0;
  for (auto it = rev_sell.begin(); it != rev_sell.end() && count < s; it++, count++) {
    printf("S %d %d\n", -(it->first), it->second);
  }

  count = 0;
  for (auto it = buy.begin(); it != buy.end() && count < s; it++, count++) {
    printf("B %d %d\n", -(it->first), it->second);
  }  

  return 0;
}
