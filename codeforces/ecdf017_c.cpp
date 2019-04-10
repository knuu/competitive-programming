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

  string a, b; cin >> a >> b;
  int La = a.size(), Lb = b.size();
  vector<int> left, right;
  for (int ia = 0, ib = 0; ia < La and ib < Lb; ia++, ib++) {
    while (ia < La and a[ia] != b[ib]) ia++;
    if (ia < La) left.push_back(ia);
  }
  for (int ia = La - 1, ib = Lb - 1; ia >= 0 and ib >= 0; ia--, ib--) {
    while (ia >= 0 and a[ia] != b[ib]) ia--;
    if (ia >= 0) right.push_back(ia);
  }
  reverse(ALL(right));

  tuple<int, int, int> ans = make_tuple(Lb, 0, Lb);
  if (right.size() > 0) {
    ans = min(ans, make_tuple(Lb - (int)right.size(), 0, Lb - (int)right.size()));
  }
  if (left.size() > 0) {
    ans = min(ans, make_tuple(Lb - (int)left.size(), (int)left.size(), Lb));
  }
  REP(i, left.size()) {
    int ub = upper_bound(ALL(right), left[i]) - right.begin();
    if (ub < right.size()) {
      int r = Lb - (int)right.size() + ub;
      ans = min(ans, make_tuple(r - (i+1), i+1, r));
    }
  }

  int L, l, r; tie(L, l, r) = ans;
  //cout << L << ' ' << l << ' ' << r << endl;
  if (L == Lb) {
    cout << "-" << endl;
  } else {
    REP(i, Lb) if (i < l or r <= i) cout << b[i];
    cout << endl;
  }
  return 0;
}
