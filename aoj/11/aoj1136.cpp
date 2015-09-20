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

int get_dir(int x1, int y1, int x2, int y2) {
  if (x1 == x2) {
    return y2 > y1 ? 0 : 2;
  } else {
    return x2 > x1 ? 1 : 3;
  }
}

Vi make_line(int t, int *X, int *Y) {
  Vi ret;
  int x0 = X[0], y0 = Y[0], px = X[1], py = Y[1];
  ret.push_back(abs(x0-px)+abs(y0-py));
  int pd = get_dir(x0, y0, px, py);
  FOR(i, 2, t) {
    int x = X[i], y = Y[i];
    int d = get_dir(px, py, x, y);
    ret.push_back((d+1)%4 == pd ? 1 : -1);
    ret.push_back(abs(x-px)+abs(y-py));
    px = x, py = y, pd = d;
  }
  return ret;
}  

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  while (1) {
    int N;
    cin >> N;
    if (N == 0) break;

    int t, x[16], y[16];
    cin >> t;
    REP(i, t) cin >> x[i] >> y[i];
    Vi target = make_line(t, x, y);
    int T = target.size();
    REP(n, N) {
      int m, mx[16], my[16];
      cin >> m;
      REP(i, m) cin >> mx[i] >> my[i];
      Vi line = make_line(m, mx, my);
      if (T != (int)line.size()) continue;
      bool flag = true;
      REP(i, T) {
	if (target[i] != line[i]) {
	  flag = false;
	}
	if (i%2) line[i] = -line[i];
      }
      if (flag) {
	cout << n+1 << endl;
	continue;
      }

      flag = true;
      REP(i, T) {
	if (target[i] != line[T-i-1]) {
	  flag = false;
	  break;
	}
      }
      if (flag) {
	cout << n+1 << endl;
	continue;
      }      
    }
    cout << "+++++" << endl;
  }  

  return 0;
}
