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

const int N = 50, W = 50, C = 50;
int M = 0;
int B[50][50], board[50][50], used[50][50];
pair<int, int> D[2500];
const string S = ".ox+-";

void dump() {
  REP(i, N) {
    REP(j, N) printf("%c", S[B[i][j]]);
    printf("\n");
  }
}
void drop() {
  REP(c, N) {
    for (int r = N - 1; r >= 0; r--) {
      if (board[r][c] == 0) {
        int now = r;
        while (now >= 0 and board[now][c] == 0) now--;
        if (now < 0) break;
        while (now >= 0 and board[now][c] != 0) {
          board[r][c] = board[now][c];
          board[now][c] = 0;
          now--, r--;
        }
        if (now < 0) break;
        r++;
      }
    }
  }
}

int bfs(int sr, int sc, char s) {
  queue<pair<int, int>> que;
  que.emplace(sr, sc);
  int cnt = 0;
  while (not que.empty()) {
    int r, c; tie(r, c) = que.front(); que.pop();
    if (used[r][c]) continue;
    cnt++;
    used[r][c] = 1;
    REP(i, 4) {
      int nr = r + dr[i], nc = c + dc[i];
      if (0 <= nr and nr < N and 0 <= nc and nc < N and not used[nr][nc] and board[nr][nc] == s) {
        que.emplace(nr, nc);
      }
    }
  }
  return cnt;
}

int evaluate(vector<int> change) {
  REP(i, N) REP(j, N) board[i][j] = B[i][j];

  REP(i, M) {
    int r, c; tie(r, c) = D[i];
    if (change[i] == 1) board[r][c] = 3;
  }

  drop();

  memset(used, 0, sizeof(used));
  int max_o = 0, max_x = 0;
  REP(r, N) REP(c, N) {
    if (used[r][c]) continue;
    if (board[r][c] == 1) max_o = max(max_o, bfs(r, c, 1));
    if (board[r][c] == 2) max_x = max(max_x, bfs(r, c, 2));
  }
  return max_o + max_x;
}

void solve() {
  chrono::system_clock::time_point start = chrono::system_clock::now();

  random_device rnd;
  mt19937 mt(rnd());

  for (int i = N - 1; i >= 0; i--) {
    for (int j = 0; j < N; j++) {
      if (B[i][j] == 0) D[M] = make_pair(i, j), M++;
    }
  }

  vector<int> best_change(M, 0);
  vector<vector<int>> best_changes;
  REP(i, W) best_changes.push_back(best_change);
  vector<int> best_scores(W);
  REP(i, W) best_scores[i] = evaluate(best_changes[i]);

  uniform_int_distribution<> rand2(0, 1), randM(0, M-1);
  int itr = 0;

  while (true) {
    double diff = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count() / 1000.;
    if (diff > 9.5) break;
    vector<vector<int>> changes;
    vector<pair<int, int>> ranks;
    REP(i, W) ranks.emplace_back(-best_scores[i], i), changes.push_back(best_changes[i]);
    REP(i, W) {
      REP(_, C) {
        vector<int> change = best_changes[i];
        int change_num = 5;
        REP(_, change_num) {
          int idx = randM(mt);
          int ns = rand2(mt);
          change[idx] = ns;
        }
        int score = evaluate(change);
        ranks.emplace_back(-score, changes.size());
        changes.push_back(change);
      }
    }
    sort(ALL(ranks));
    REP(i, W) best_changes[i] = changes[ranks[i].second], best_scores[i] = -ranks[i].first;
    //cerr << chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now() - start).count() / 1000. << ' ' << itr << ' ' << best_scores[0] << endl;
    itr++;
  }
  cerr << itr << ' ' << best_scores[0] << endl;
  best_change = best_changes[0];
  REP(i, M) {
    int r, c; tie(r, c) = D[i];
    if (best_change[i] == 1) B[r][c] = 3;
  }

  dump();
}

int main() {
  REP(i, N) {
    string row; cin >> row;
    REP(j, N) {
      if (row[j] == '.') {
        B[i][j] = 0;
      } else if (row[j] == 'o') {
        B[i][j] = 1;
      } else if (row[j] == 'x') {
        B[i][j] = 2;
      }
    }
  }
  solve();

  return 0;
}
