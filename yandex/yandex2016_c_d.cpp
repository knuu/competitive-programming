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
  cout << "? 0" << endl;
  string col; cin >> col;
  vector<ll> pow2;
  pow2.push_back(0);
  REP(i, 63) pow2.push_back(1LL << i);

  int i = 0;
  while (true) {
    cout << "? " << pow2[i] << endl;
    string c; cin >> c;
    if (c != col) break;
    i++;
  }

  ll right = 0;
  for (; i >= 0; i--) {
    cout << "? " << right + pow2[i] << endl;
    string c; cin >> c;
    if (c == col) right += pow2[i];
  }

  i = 0;
  while (true) {
    cout << "? " << -pow2[i] << endl;
    string c; cin >> c;
    if (c != col) break;
    i++;
  }

  ll left = 0;
  for (; i >= 0; i--) {
    cout << "? " << -(left + pow2[i]) << endl;
    string c; cin >> c;
    if (c == col) left += pow2[i];
  }
  cout << "! " << right + left + 1 << endl;
  return 0;
}
