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

bool ok(ll ans, ll rest, vector<ll> &A, vector<ll> &F) {
  REP(i, A.size()) {
    ll need = ans / F[i];
    rest -= max(0LL, A[A.size() - i - 1] - need);
  }
  return rest >= 0;
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int N; ll K; cin >> N >> K;
  vector<ll> A(N), F(N); REP(i, N) cin >> A[i]; REP(i, N) cin >> F[i];
  sort(ALL(A));
  sort(ALL(F));
  ll left = -1, right = 1e13;
  while (left + 1 < right) {
    int mid = (left + right) / 2;
    if (ok(mid, K, A, F)) {
      right = mid;
    } else {
      left = mid;
    }
  }

  cout << right << endl;

  return 0;
}
