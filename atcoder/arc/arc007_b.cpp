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
  int N, M, now = 0;
  int cd_case[128];
  
  cin >> N >> M;

  REP(i, N) cd_case[i] = i+1;

  REP(i, M) {
    int disk;
    cin >> disk;
    auto it = find(cd_case, cd_case + N, disk);
    if (it != cd_case + N) {
      swap(now, *it);
    }
  }
  REP(i, N) cout << cd_case[i] << endl;
  return 0;
}
