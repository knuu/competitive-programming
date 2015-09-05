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
  int N, M, name_bucket[26], kit_bucket[26];
  string name, kit;

  fill(name_bucket, name_bucket + 26, 0);
  fill(kit_bucket, kit_bucket + 26, 0);

  cin >> N >> M;
  cin >> name >> kit;

  REP(i, N) {
    name_bucket[name[i] - 'A'] += 1;
  }

  REP(i, M) {
    kit_bucket[kit[i] - 'A'] += 1;
  }

  int ans = 0;
  REP(i, 26) {
    if (name_bucket[i] == 0) {
      continue;
    } else if (kit_bucket[i] == 0) {
      ans = -1;
      break;
    } else {
      ans = max((int)ceil(1.0 * name_bucket[i] / kit_bucket[i]), ans);
    }
  }
  cout << ans << endl; 
  return 0;
}
