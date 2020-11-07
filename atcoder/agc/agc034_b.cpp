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

  string S; cin >> S;
  int N = S.size();

  ll ans = 0;

  REP(i, N) {
    if (S[i] == 'A') {
      vector<int> A(1), BC(1);
      while (i < N) {
        if (S[i] == 'A') {
          A.emplace_back(1);
          BC.emplace_back(0);
          i++;
        } else if (i < N-1 and S[i] == 'B' and S[i+1] == 'C') {
          A.emplace_back(0);
          BC.emplace_back(1);
          i += 2;
        } else {
          break;
        }
      }
      REP(i, BC.size()-1) BC[i+1] += BC[i];
      REP(i, A.size()) {
        if (A[i] == 1) ans += BC[BC.size()-1] - BC[i];
      }
      i--;
    }
  }
  cout << ans << endl;

  return 0;
}
