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

int N, A, B, T;

int solve(string photos) {
  vector<int> imos(N+1, A+1), r_imos(N+1, A+1);
  imos[0] = r_imos[0] = 0;
  imos[1] = r_imos[1] = 1;
  REP(i, N) {
    if (photos[i] == 'w') {
      imos[i+1] += B;
      r_imos[N-i] += B;
    }
  }

  int M = 0;
  REP(i, N) {
    imos[i+1] += imos[i], r_imos[i+1] += r_imos[i];
    if (imos[i+1] <= T) M++;
  }
  //REP(i, N) cout << imos[i+1] << (i == N-1 ? '\n' : ' ');
  //REP(i, N) cout << r_imos[i+1] << (i == N-1 ? '\n' : ' ');

  int ret = M;
  //cout << M << endl;
  for (int i = M; i > 0; i--) {
    int res = T - imos[i] - i * A;
    //cout << res << (i == 1 ? '\n' : ' ');
    if (res <= 0) continue;
    int left = 0, right = N+1;
    while (left + 1 < right) {
      int mid = (left + right) >> 1;
      (r_imos[mid] <= res ? left : right) = mid;
    }
    ret = max(ret, min(N, i + left));
  }
  return ret;
}


int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cin >> N >> A >> B >> T;
  string P; cin >> P;
  string revP = P;
  reverse(revP.begin() + 1, revP.end());
  int ans1 = solve(P);
  int ans2 = solve(revP);
  //cout << ans1 << ' ' << ans2 << endl;
  cout << max(ans1, ans2) << endl;
  return 0;
}
