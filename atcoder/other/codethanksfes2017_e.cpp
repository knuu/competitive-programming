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

const int pow10[5] = {1, 10, 100, 1000, 10000};

int main() {
  int N; cin >> N;
  vector<int> ans(N);
  for (int i = 0; i < N; i += 5) {
    vector<int> q(N, 0);
    FOR(j, i, min(i + 5, N)) q[j] = pow10[j];
    cout << '?'; REP(i, N) cout << ' ' << q[j];
    cout << endl;


  }

  return 0;
}
