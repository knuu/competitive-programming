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

  int R, N, M; cin >> R >> N >> M;
  double ans = 0;
  vector<pair<double, int>> cut;
  vector<int> used(N-1, 0);
  if (N % 2 == 0) cut.emplace_back(2.0 * R, N / 2 - 1);
  REP(i, (N-1)/2) {
    double cut_len = 2 * sqrt(R * R - pow(R - 2.0 * R / N * (i + 1), 2));
    cut.emplace_back(cut_len, i);
    cut.emplace_back(cut_len, N - (i+1) - 1);
  }
  assert((int)cut.size() == N-1);
  sort(ALL(cut));
  for (int i = N-2; i >= 0; i--) {
    int idx; double cut_len; tie(cut_len, idx) = cut[i];
    //cout << i << ' ' << ans << ' ' << idx << ' ' << cut_len << ' ' << used[idx] << endl;
    if (used[idx]) continue;
    used[idx] = true;
    ans += cut_len;
    for (int j = i-1; j >= 0; j--) {
      int k; double c; tie(c, k) = cut[j];
      if (not used[k] and abs(k - idx) >= M) {
        used[k] = true;
        break;
      }
    }
  }
  cout << setprecision(20) << ans << endl;
  return 0;
}
