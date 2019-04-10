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

  while (true) {
    int N; cin >> N;
    if (not N) break;

    vector<string> eq(N); REP(i, N) cin >> eq[i];
    vector<char> char_set;
    for (string s : eq) for (char c : s) char_set.push_back(c);
    sort(ALL(char_set)); char_set.erase(unique(ALL(char_set)), char_set.end());
    map<char, ll> coef_l, coef_r;
    set<char> top_c;
    REP(i, N) REP(j, eq[i].size()) {
      coef_l[eq[i][j]] += (ll)pow(10, eq[i].size() - j - 1);
      if (i == N - 1) coef_r[eq[i][j]] += (ll)pow(10, eq[i].size() - j - 1);
      if (j == 0 and eq[i].size() > 1) top_c.insert(eq[i][j]);
    }

    int ans = 0;
    vector<int> perm(10); iota(ALL(perm), 0);
    do {
      ll num_l = 0, num_r = 0;
      bool flag = true;
      REP(i, char_set.size()) {
        if (perm[i] == 0) flag = top_c.find(char_set[i]) == top_c.end();
        num_l += (ll)perm[i] * coef_l[char_set[i]];
        num_r += (ll)perm[i] * coef_r[char_set[i]];
      }
      if (flag and num_l == num_r * 2) ans++;
    } while (next_permutation(ALL(perm)));
    REP(i, 10 - char_set.size()) ans /= i + 1;
    cout << ans << endl;
  }

  return 0;
}
