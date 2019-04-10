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

  vector<int> points = {100, 75, 60, 50, 45, 40, 36, 32, 29, 26, 24, 22, 20, 18, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

  vector<int> rank(10); REP(i, 10) cin >> rank[i];
  reverse(ALL(rank));

  //REP(i, 10) cout << rank[i] << (i == 9 ? '\n' : ' ');
  REP(i, 31) {
    vector<int> tmp = rank;
    for (int j = 0, cnt = 0; cnt < 10; j++, cnt++) {
      if (i == j) j++;
      tmp[cnt] += points[j];
    }
    //REP(i, 10) cout << tmp[i] << (i == 9 ? '\n' : ' ');
    bool flag = false;
    REP(j, 10) flag |= points[i] > tmp[j];
    if (not flag) {
      cout << i << endl;
      return 0;
    }
  }
  cout << 1000 << endl;
  return 0;
}
