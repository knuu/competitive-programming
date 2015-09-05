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

int h[100010];
int ope[100010];

int main() {
  int N;
  scanf("%d", &N);
  REP(i, N) scanf("%d", h+i+1);

  REP(i, N) ope[i+1] = min(ope[i] + 1, h[i+1]);
  REP(i, N) ope[N-i] = min(ope[N-i], ope[N-i+1] + 1);

  cout << *max_element(ope + 1, ope + 1 + N) << endl;    
  return 0;
}
