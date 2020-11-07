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

const int INF = 1e8;

using ti = tuple<int, int, int>;
int board[40][40];
int dist[40][40][4];
int prev_dir[40][40][4];
bool used[40][40], reached[40][40];
int N, M, B;
int gr, gc;
ti robots[100];
bool block[40][40];
int panel[40][40];
vector<int> rs, cs; vector<char> ds;

int main() {
  cin >> N >> M >> B;
  cin >> gr >> gc;
  REP(i, M) {
    int r, c; string d_s; cin >> r >> c >> d_s;
    int d;
    if (d_s == "U") {
      d = 0;
    } else if (d_s == "D") {
      d = 2;
    } else if (d_s == "R") {
      d = 1;
    } else if (d_s == "L") {
      d = 3;
    } else {
      cerr << "invalid" << endl;
    }
    robots[i] = make_tuple(r, c, d);
  }

  REP(i, N) REP(j, N) block[i][j] = false;

  REP(_, B) {
    int r, c; cin >> r >> c;
    block[r][c] = true;
  }

  REP(i, N) REP(j, N) panel[i][j] = -1;

  REP(i, M) {
    //cout << i << endl;
    int ri, ci, di; tie(ri, ci, di) = robots[i];
    priority_queue<ti, vector<ti>, greater<ti>> pque;
    REP(j, N) REP(k, N) REP(l, 4) dist[j][k][l] = INF;
    memset(prev_dir, -1, sizeof(prev_dir));
    dist[ri][ci][di] = 0;
    pque.emplace(0, ri * N + ci, di);

    while (not pque.empty()) {
      int cost, rc, d; tie(cost, rc, d) = pque.top(); pque.pop();
      int r = rc / N, c = rc % N;
      //cout << cost << ' ' << r << ' ' << c << ' ' << d << endl;
      if (r == gr and c == gc) {
        //REP(rrr, N) REP(ccc, N) if (panel[rrr][ccc] >= 0) cout << '(' << rrr << ',' << ccc << ")=" << panel[rrr][ccc] << ',';
        //cout << endl;

        //cout << "back start" << endl;
        while (r != ri or c != ci) {
          assert(d >= 0);
          int nr = (r - dr[d] + N) % N, nc = (c - dc[d] + N) % N;
          //cout << r << ' ' << c << ' ' << d << ' ' << nr << ' ' << nc << ' ' << prev_dir[r][c][d] << ' ' << panel[nr][nc] << endl;
          if (d != prev_dir[r][c][d]) {
            assert(panel[nr][nc] == -1 or panel[nr][nc] == d);
            panel[nr][nc] = d;
          }
          d = prev_dir[r][c][d];
          r = nr, c = nc;
        }
        break;
      }
      if (dist[r][c][d] < cost) continue;

      if (panel[r][c] == -1) {
        REP(i, 4) {
          int nr = (r + dr[i] + N) % N, nc = (c + dc[i] + N) % N;
          if (not block[nr][nc] and dist[nr][nc][i] > cost + (d != i)) {
            //cout << '(' << r << ',' << c << ',' << d << ")=>(" << nr << ',' << nc << ',' << i << ')' << endl;
            dist[nr][nc][i] = cost + (d != i);
            pque.emplace(dist[nr][nc][i], nr * N + nc, i);
            prev_dir[nr][nc][i] = d;
          }
        }
      } else {
        int nd = panel[r][c];
        int nr = (r + dr[nd] + N) % N;
        int nc = (c + dc[nd] + N) % N;
        if (not block[nr][nc] and dist[nr][nc][nd] > cost) {
          //cout << '(' << r << ',' << c << ',' << d << ")=>(" << nr << ',' << nc << ',' << nd << ')' << endl;
          dist[nr][nc][nd] = cost;
          prev_dir[nr][nc][nd] = d;
          pque.emplace(cost, nr * N + nc, nd);
        }
      }
    }
  }

  REP(r, N) REP(c, N) {
    if (panel[r][c] < 0) continue;
    rs.emplace_back(r);
    cs.emplace_back(c);
    if (panel[r][c] == 0) {
      ds.emplace_back('U');
    } else if (panel[r][c] == 1) {
      ds.emplace_back('R');
    } else if (panel[r][c] == 2) {
      ds.emplace_back('D');
    } else if (panel[r][c] == 3) {
      ds.emplace_back('L');
    }
  }

  assert(rs.size() == cs.size() and cs.size() == ds.size());

  cout << rs.size() << endl;
  REP(i, rs.size()) {
    cout << rs[i] << ' ' << cs[i] << ' ' << ds[i] << endl;
  }

  return 0;
}
