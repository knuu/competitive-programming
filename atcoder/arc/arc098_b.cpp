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
  int left = 0, prev_r = 0, right = 0, now = 0;
  ll ans = 0;
  while (left < N) {
    while(right < N and (A[right] ^ now) == A[right] + now) {
      now ^= A[right];
      right++;
    }
    //cout << left << ' ' << right << ' ' << (ll)(right - left) * (ll)(right - left - 1) / 2 << endl;
    ans += (ll)(right - left) * (ll)(right - left - 1) / 2 - (ll)max(0, prev_r - left) * (ll)max(0, prev_r - left - 1) / 2;
    prev_r = right;
    if (right == N) break;
    while ((A[right] ^ now) != A[right] + now) {
      now ^= A[left];
      left++;
    }
  }
  cout << ans + N << endl;
  return 0;
}
