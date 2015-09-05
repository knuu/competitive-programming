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

int arrayA[100010], arrayB[100010];

int main() {
  int na, nb, k, m;
  cin >> na >> nb >> k >> m;
  REP(i, na) cin >> arrayA[i];
  REP(i, nb) cin >> arrayB[i];
  if (arrayA[k-1] < arrayB[nb-m]) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
