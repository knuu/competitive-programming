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

int b[6];

int main() {
  string a;
  cin >> a;
  REP(i, a.size()) {
    b[a[i] - 'A']++;
  }
  REP(i, 6) cout << b[i] << (i == 5 ? '\n' : ' ');
  return 0;
}
