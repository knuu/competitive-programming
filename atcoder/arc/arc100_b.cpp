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

vector<vector<ll>> divide(vector<ll> &A, int left, int right) {
  int low = left, high = right;
  while (low + 1 < high) {
    int mid = (low + high) / 2;
    if (A[mid] - A[left - 1] <= A[right] - A[mid]) {
      low = mid;
    } else {
      high = mid;
    }
  }
  vector<vector<ll>> ret;
  ret.push_back({A[low] - A[left - 1], A[right] - A[low]});
  if (high < right) {
    ret.push_back({A[high] - A[left - 1], A[right] - A[high]});
  }
  return ret;
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N; cin >> N;
  vector<ll> A(N + 1, 0);
  REP(i, N) {
    cin >> A[i + 1];
    A[i + 1] += A[i];
  }
  ll ans = A[N];
  FOR(r_start, 3, N) {
    vector<vector<ll>> left = divide(A, 1, r_start - 1), right = divide(A, r_start, N);
    for (vector<ll> l : left) {
      for (vector<ll> r : right) {
        vector<ll> s = {l[0], l[1], r[0], r[1]};
        /*
        cout << r_start << ':';
        for (ll x : s) cout << x << ' ';
        cout << endl;
        */
        ans = min(ans, *max_element(ALL(s)) - *min_element(ALL(s)));
      }
    }
  }
  cout << ans << endl;

  return 0;
}
