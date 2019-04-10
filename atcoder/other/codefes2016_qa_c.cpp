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

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  string S; cin >> S;
  int K; cin >> K;
  int L = S.size();

  REP(i, L) {
    if (i == L-1) {
      S[i] = (S[i] - 'a' + (K % 26)) % 26 + 'a';
    } else if (S[i] != 'a' and 26 - (S[i] - 'a') <= K) {
      K -= 26 - (S[i] - 'a');
      S[i] = 'a';
    }
    assert(K >= 0);
  }

  cout << S << endl;

  return 0;
}
