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
  int Q; scanf("%d", &Q);
  map<int, int> mult;
  mult[0]++;

  REP(q, Q) {
    string t; cin >> t;
    int x; scanf("%d", &x);
    if (t == "+") {
      mult[x]++;
    } else if (t == "-") {
      mult[x]--;
      if (mult[x] == 0) mult.erase(x);
    } else {
      int left = 0, right = INT_MAX;
      for (int i = 30; i >= 0; i--) {
        int mid = left + (1 << i);
        auto it = mult.lower_bound(mid);
        if (x >> i & 1) {
          auto l_it = mult.lower_bound(left);
          (it == l_it ? left : right) = mid;
        } else {
          auto r_it = mult.lower_bound(right);
          (it != r_it ? left : right) = mid;
        }
      }
      //cout << left << endl;
      printf("%d\n", x^left);
    }

  }


  return 0;
}
