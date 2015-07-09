#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define PB push_back
#define MP make_pair
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl
#define fst first
#define snd second

int N;
vector<P> point;

bool isLine(P p1, P p2, P p3) {
  int x1 = p1.fst, y1 = p1.snd;
  int x2 = p2.fst, y2 = p2.snd;
  int x3 = p3.fst, y3 = p3.snd;
  double S = abs((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)) / 2.0;
  return S == 0 ? true : false;
}
  
int main() {
  cin >> N;
  REP(i, N) {
    int x, y;
    cin >> x >> y;
    point.PB(MP(x, y));
  }

  int ans = 0;
  REP(i, N) FOR(j, i+1, N) FOR(k, j+1, N) if (!isLine(point[i], point[j], point[k])) ans++;
  cout << ans << endl;
  
  return 0;
}
