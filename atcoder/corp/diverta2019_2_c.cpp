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
  sort(ALL(A));
  if (A[0] >= 0) {
    int now = A[0];
    vector<pair<int, int>> ans;
    FOR(i, 1, N-1) {
      ans.push_back(make_pair(now, A[i]));
      now -= A[i];
    }
    ans.push_back(make_pair(A[N-1], now));
    cout << A[N-1] - now << endl;
    for (pair<int, int> p : ans) {
      int x, y; tie(x, y) = p;
      cout << x << ' ' << y << endl;
    }
  } else if (A[N-1] <= 0) {
    int now = A[N-1];
    vector<pair<int, int>> ans;
    REP(i, N-1) {
      ans.push_back(make_pair(now, A[i]));
      now -= A[i];
    }
    cout << now << endl;
    for (pair<int, int> p : ans) {
      int x, y; tie(x, y) = p;
      cout << x << ' ' << y << endl;
    }
  } else {
    vector<int> pos, neg, zero;
    for (int x : A) {
      if (x > 0) {
        pos.emplace_back(x);
      } else if (x < 0) {
        neg.emplace_back(x);
      } else {
        zero.emplace_back(x);
      }
    }

    vector<pair<int, int>> ans;
    int pos_now = pos[0], neg_now = neg[0];
    if (pos.size() > 1) {
      FOR(i, 1, pos.size()) {
        ans.push_back(make_pair(neg_now, pos[i]));
        neg_now -= pos[i];
      }
    }
    if (neg.size() > 1) {
      FOR(i, 1, neg.size()) {
        ans.push_back(make_pair(pos_now, neg[i]));
        pos_now -= neg[i];
      }
    }

    REP(i, zero.size()) ans.push_back(make_pair(pos_now, 0));
    ans.push_back(make_pair(pos_now, neg_now));
    cout << pos_now - neg_now << endl;

    for (pair<int, int> p : ans) {
      int x, y; tie(x, y) = p;
      cout << x << ' ' << y << endl;
    }

  }


  return 0;
}
