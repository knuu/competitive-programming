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
  int N, dist[64];

  cin >> N;
  REP(i, N) {
    cout << "? " << 1 << " " << i+1 << endl;
    cin >> dist[i];
  }

  int diam = max_element(dist, dist + N) - dist;
  REP(i, N) {
    cout << "? " << diam + 1 << " " << i+1 << endl;
    cin >> dist[i];
  }

  cout << "! " << *max_element(dist, dist + N) << endl;  
  return 0;
}

