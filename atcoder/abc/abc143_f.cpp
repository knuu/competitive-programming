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
  vector<int> A(N); REP(i, N) cin >> A[i];
  map<int, int> mp;
  for (int a : A) mp[a]++;
  map<int, int> cnt;
  for (auto key : mp) cnt[key.second]++;
  int kind = cnt.rbegin()->first;
  //vector<int> ans(cnt.rbegin()->first);
  vector<int> ans(N);
  for (auto key : cnt) {
    REP(i, kind) {
      if (i + 1 < key.first) {
        ans[i] += (i + 1) * key.second;
      } else {
        ans[i] += key.first * key.second;
      }
    }
  }
  FOR(i, kind, N) ans[i] = ans[kind-1];

  REP(i, ans.size()) {
    cout << i+1 << ':' << ans[i] << endl;
  }
  int tmp_size = ans.size();

  vector<int> final_ans(N, 0);

  REP(i, N) {
    int left = 0, right = N;
    while (left + 1 < right) {
      int mid = (left + right) / 2;
      cout << i + 1 << ' ' << left << ' ' << right << ' ' << mid + 1 << ' ' << ans[mid] << endl;
      if (ans[mid] / (mid + 1) >= i + 1) {
        left = mid;
      } else {
        right = mid;
      }
    }
    cout << left + 1 << endl;
  }


  return 0;
}
