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
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

bool used[2510][2510];
int roomL[51][51], roomR[51][51];

inline int s_to_i(char c) {
  switch (c) {
  case '#':
    return -1;
  case '.':
    return 0;
  case 'L':
  case 'R':
    return 1;
  case '%':
    return 2;
  }
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  while (true) {
    int R, C;
    cin >> C >> R;
    if (R == 0 && C == 0) break;
    int sl = 0, sr = 0;
    REP(i, R) {
      string rowL, rowR;
      cin >> rowL >> rowR;
      REP(j, C) {
	roomL[i][j] = s_to_i(rowL[j]);
	if (roomL[i][j] == 1) sl = i * C + j;
	roomR[i][j] = s_to_i(rowR[j]);
	if (roomR[i][j] == 1) sr = i * C + j;
      }
    }	  

    //cout << slr << ' ' << slc << ' ' << elr << ' ' << elc << ' ' << srr << ' ' << src << ' ' << err << ' ' << erc << endl;
    REP(i, R*C) REP(j, R*C) used[i][j] = false;
    
    queue<P> que;
    que.push(P(sl, sr));

    bool flag = false;
    while (!que.empty()) {
      P p = que.front(); que.pop();
      int l = p.first, r = p.second, lr = p.first / C, lc = p.first % C, rr = p.second / C, rc = p.second % C;
      //cout << lr << ' ' << lc << ' ' << rr << ' ' << rc << endl;
      if (roomL[lr][lc] == 2 && roomR[rr][rc] == 2) {
	flag = true;
	break;
      } else if (used[l][r] || roomL[lr][lc] == 2 || roomR[rr][rc] == 2) {
	continue;
      }

      used[l][r] = true;
      REP(i, 4) {
	int nlr = lr + dr[i], nlc = lc + dc[i], nrr = rr + dr[(i+2*(i&1))%4], nrc = rc + dc[(i+2*(i&1))%4];
	if (nlr < 0 || nlr >= R || nlc < 0 || nlc >= C || roomL[nlr][nlc] == -1) nlr = lr, nlc = lc;
	if (nrr < 0 || nrr >= R || nrc < 0 || nrc >= C || roomR[nrr][nrc] == -1) nrr = rr, nrc = rc;
	if (!used[nlr * C + nlc][nrr * C + nrc]) que.push(P(nlr * C + nlc, nrr * C + nrc));
      }
    }
    cout << (flag ? "Yes" : "No") << endl;    
  }
  return 0;
}
