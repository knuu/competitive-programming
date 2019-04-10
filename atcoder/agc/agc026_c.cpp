#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
//typedef tuple<int, int, int> T;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)
#define ALL(c) c.begin(), c.end()
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl
#define UNIQUE(c) sort(ALL(c)), c.erase(unique(ALL(c)), c.end())

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N; cin >> N;
  string S; cin >> S;
  map<pair<string, string>, ll> mp;
  REP(bit, 1 << N) {
    string red = "", blue = "";
    REP(i, N) {
      if (bit >> i & 1) {
        red.push_back(S[i + N]);
      } else {
        blue.push_back(S[i + N]);
      }
    }
    mp[make_pair(red, blue)]++;
  }

  ll ans = 0;
  REP(bit, 1 << N) {
    string red = "", blue = "";
    REP(i, N) {
      if (bit >> i & 1) {
        red.push_back(S[i]);
      } else {
        blue.push_back(S[i]);
      }
    }
    reverse(ALL(red));
    reverse(ALL(blue));
    ans += mp[make_pair(blue, red)];
  }
  cout << ans << endl;

  return 0;
}
