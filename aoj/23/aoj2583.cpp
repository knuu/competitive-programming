#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
typedef tuple<int, int, int> T;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)
#define ALL(c) c.begin(), c.end()
#define MP make_pair
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl
#define fst first
#define snd second

string tree[1024];

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N;
  while (cin >> N, N) {
    REP(i, N) cin >> tree[i];

    int last_dot = 0;
    FOR(i, 1, N) {
      last_dot = min(last_dot, (int)tree[i].size()-1);
      if (tree[i][last_dot] == '.') {
	if (tree[i][last_dot+1] == '.') last_dot++;
	tree[i][last_dot] = '+';
	for (int j = last_dot-1; j >= 0; j--) tree[i][j] = ' ';
	
      } else {
	while (tree[i][last_dot] != '.') last_dot--;
	for (int j = last_dot-1; j >= 0; j--) tree[i][j] = ' ';
	tree[i][last_dot] = '+';
	for (int j = i-1; j >= 0 && tree[j][last_dot] == ' '; j--) tree[j][last_dot] = '|';
      }
    }
    REP(i, N) cout << tree[i] << endl;
  }
  return 0;
}
