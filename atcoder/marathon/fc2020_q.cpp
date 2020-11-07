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

using ti = tuple<int, int, int>;
int board[40][40];
int dist[40][40];
int prev_dir[40][40];
bool used[40][40], reached[40][40];
int N, M, B;
int gr, gc;
ti robots[100];
pair<int, int> blocks[300];
vector<int> rs, cs; vector<char> ds;
map<int, vector<int>> panel_to_robots;

bool simulate() {
  REP(i, N) REP(j, N) used[i][j] = false;

  for (auto robot : robots) {
    int r, c, d; tie(r, c, d) = robot;
    int ri = r, ci = c, di = d;
    if (dist[r][c] <= 0) continue;
    REP(i, N) REP(j, N) reached[i][j] = false;
    //if (ri == 0 and ci == 13) {
    //  cout << r << ' ' << c << ' ' << d << endl;
    //}
    while (true) {
      //if (ri == 0 and ci == 13) {
      //  cout << r << ' ' << c << ' ' << d << endl;
      //}
      //cout << r << ' ' << c << endl;
      if (reached[r][c]) return false;
      reached[r][c] = true;
      if (prev_dir[r][c] != -1) {
        if (prev_dir[r][c] != d) {
          used[r][c] = true;
        }
        d = prev_dir[r][c];
      }
      r = (r + dr[d] + N) % N, c = (c + dc[d] + N) % N;
      if (r == gr and c == gc) {
        break;
      } else if (dist[r][c] < 0) {
        return false;
      }
    }
  }
  return true;
}

int remove_panels(vector<bool> &not_removed) {
  int ans_size = not_removed.size();
  //return ans_size;
  while (true) {
    bool changed = false;
    //cout << -1 << endl;
    REP(i, ans_size) {
      //cout << i << ',';
      if (not not_removed[i]) continue;
      int r = rs[i], c = cs[i];
      int tmp = prev_dir[r][c];
      prev_dir[r][c] = -1;
      //cout << r << ' ' << c << endl;
      if (simulate()) {
        not_removed[i] = false;
        changed = true;
        ans_size--;
        break;
      } else {
        prev_dir[r][c] = tmp;
      }
    }
    //cout << endl;
    if (not changed) break;
    //if (changed) return ans_size;
  }
  return ans_size;
}

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
  memset(dist, -1, sizeof(dist));
  memset(prev_dir, -1, sizeof(prev_dir));
  REP(i, B) {
    int r, c; cin >> r >> c;
    dist[r][c] = -2;
    blocks[i] = make_pair(r, c);
  }

  dist[gr][gc] = 0;
  prev_dir[gr][gc] = -1;

  queue<ti> que;

  que.emplace(0, gr, gc);
  while (not que.empty()) {
    int cost, r, c; tie(cost, r, c) = que.front(); que.pop();

    REP(i, 4) {
      int nr = (r + dr[i] + N) % N, nc = (c + dc[i] + N) % N;
      if (dist[nr][nc] == -1) {
        dist[nr][nc] = dist[r][c] + 1;
        prev_dir[nr][nc] = (i + 2) % 4;
        que.emplace(dist[r][c] + 1, nr, nc);
      }
    }
  }

  assert(simulate());

  REP(r, N) REP(c, N) {
    if (not used[r][c]) {
      prev_dir[r][c] = -1;
      continue;
    }
    rs.emplace_back(r);
    cs.emplace_back(c);
    if (prev_dir[r][c] == 0) {
      ds.emplace_back('U');
    } else if (prev_dir[r][c] == 1) {
      ds.emplace_back('R');
    } else if (prev_dir[r][c] == 2) {
      ds.emplace_back('D');
    } else if (prev_dir[r][c] == 3) {
      ds.emplace_back('L');
    } else {
      prev_dir[r][c] = -1;
      rs.pop_back();
      cs.pop_back();
    }
  }

  //REP(i, N) REP(j, N) cout << prev_dir[i][j] << (j == N - 1 ? '\n' : ' ');

  assert(rs.size() == cs.size() and cs.size() == ds.size());
  vector<bool> not_removed(rs.size(), true);
  int ans_size = remove_panels(not_removed);

  cout << ans_size << endl;
  REP(i, rs.size()) {
    if (not_removed[i]) {
      cout << rs[i] << ' ' << cs[i] << ' ' << ds[i] << endl;
    }
  }

  return 0;
}
