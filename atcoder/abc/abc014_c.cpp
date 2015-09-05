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

int color[1000010];

int main() {
  int n;
  cin >> n;
  fill(color, color + 1000010, 0);
  REP(i, n) {
    int a, b;
    cin >> a >> b;
    color[a] += 1;
    color[b+1] -= 1;
  }
  REP(i, 1000000) color[i+1] += color[i];
  cout << *max_element(color, color + 1000001) << endl;

  return 0;
}
