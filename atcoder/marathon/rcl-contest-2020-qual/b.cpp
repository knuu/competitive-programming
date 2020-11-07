#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <tuple>
#include <utility>
#include <queue>
#include <cstdio>
#include <iomanip>


const int dr[4] = {-1, 1, 0, 0};
const int dc[4] = {0, 0, -1, 1};

int N, M;
std::vector<std::vector<int>> board, conn, tunnel;
std::vector<std::vector<bool>> used;
std::vector<int> conn_colors;
int n_conn;
const std::string DIR = "UDLR";
const int colors[4] = {0, 1, 2, 3};

int calc_score(std::vector<std::vector<int>> &ans) {
  int ret = 0;
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      ret += ans[r][c] == board[r][c];
    }
  }
  return ret;
}

void input() {
  std::cin >> N >> M;
  board.resize(N);
  for (int i = 0; i < N; i++) {
    board[i].resize(N);
    for (int j = 0; j < N; j++) std::cin >> board[i][j];
  }
}

void output(const std::vector<std::tuple<int, int, int>> &ans) {
  for (std::tuple<int, int, int> t : ans) {
    int r, c, d; std::tie(r, c, d) = t;
    if (r == -1) {
      std::cout << -1 << '\n';
    } else {
      std::cout << r << ' ' << c << ' ' << DIR[d] << '\n';
    }
  }
}

inline bool in_board(const int r, const int c) {
  return 0 <= r and r < N and 0 <= c and c < N;
}

void dfs(int r, int c, int color) {
  if (board[r][c] == color) {
    conn[r][c] = n_conn;
  }
  used[r][c] = true;
  for (int d = 0; d < 4; d++) {
    int nr = r + dr[d], nc = c + dc[d];
    if (not in_board(nr, nc) or (board[nr][nc] != color and (tunnel[nr][nc] >> color & 1) == 0)) continue;
    if (used[nr][nc]) continue;
    dfs(nr, nc, color);
  }
}

void create_tunnel_sub() {
  conn.assign(N, std::vector<int>(N, -1));
  conn_colors.clear();
  n_conn = 0;

  /* 連結成分の色塗り */
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      if (conn[r][c] == -1) {
        used.assign(N, std::vector<bool>(N, false));
        dfs(r, c, board[r][c]);
        n_conn++;
        conn_colors.emplace_back(board[r][c]);
      }
    }
  }
  if (n_conn == 4) return;

  /*
  for (int r = 0; r < N; r++) {
    for (int c = 0; c < N; c++) {
      std::cerr << std::setw(2) << conn[r][c];
    }
    std::cerr << std::endl;
  }
  */

  /* 各連結成分に対して、同じ色の連結成分が出るまで探索し、
      1 番近い連結成分までトンネルを掘る
   */
  for (int i = 0; i < n_conn; i++) {
    std::queue<std::tuple<int, int, int>> que;
    std::vector<std::vector<int>> dists(N, std::vector<int>(N, N * N)),
                                  prev(N, std::vector<int>(N, -1));
    for (int r = 0; r < N; r++) for (int c = 0; c < N; c++) {
      if (conn[r][c] == i) que.emplace(r, c, 0), dists[r][c] = 0;
    }

    while (not que.empty()) {
      int r, c, dist; std::tie(r, c, dist) = que.front(); que.pop();
      if (dists[r][c] < dist) continue;
      if (conn[r][c] != i and board[r][c] == conn_colors[i]) {
        int nr = prev[r][c] / N, nc = prev[r][c] % N;
        r = nr, c = nc;
        while (prev[r][c] != -1) {
          tunnel[r][c] |= 1 << conn_colors[i];
          nr = prev[r][c] / N, nc = prev[r][c] % N;
          r = nr, c = nc;
        }
        break;
      }
      for (int i = 0; i < 4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if (in_board(nr, nc) and dists[nr][nc] > dist + 1) {
          dists[nr][nc] = dist + 1;
          prev[nr][nc] = r * N + c;
          que.emplace(nr, nc, dist + 1);
        }
      }
    }
  }
}

void create_tunnel() {
  tunnel.assign(N, std::vector<int>(N, 0));
  while (true) {
    create_tunnel_sub();
    if (n_conn == 4) break;
  }
}

void solve() {
  // create tunnnel
  create_tunnel();
  ///*
  for (int i = 0; i < 4; i++) {
    for (int r = 0; r < N; r++) {
      for (int c = 0; c < N; c++) {
        std::cerr << ((tunnel[r][c] >> i & 1) | (board[r][c] == i));
        //for (int i = 0; i < 4; i++) std::cerr << (tunnel[r][c] >> i & 1);
        //std::cerr << ' ';
        //std::cerr << conn[r][c] << ' ';
      }
      std::cerr << '\n';
    }
    std::cerr << '\n';
  }
  //*/

  // coloring greedy
  std::vector<std::vector<int>> colored(N, std::vector<int>(N, -1));
  colored[0][0] = 0, colored[0][N-1] = 1, colored[N-1][0] = 2, colored[N-1][N-1] = 3;

  std::vector<std::tuple<int, int, int>> ans(M);
  for (int m = 0; m < M; m++) {
    int color = colors[m % 4];
    int cr = -1, cc = -1, cd = -1, up_score = -1;
    for (int r = 0; r < N; r++) {
      for (int c = 0; c < N; c++) {
        if (colored[r][c] != color) continue;
        for (int d = 0; d < 4; d++) {
          int cand_score = 0;
          for (int res_cnt = 5, nr = r, nc = c; res_cnt >= 0 and in_board(nr, nc);
               res_cnt--, nr += dr[d], nc += dc[d]) {
            if (board[nr][nc] == color and (m >= M - 41 or tunnel[nr][nc] == 0)) cand_score += 10;
            if (colored[nr][nc] == board[nr][nc] and (m >= M - 41 or tunnel[nr][nc] == 0)) cand_score -= 10;
            if (m < M - 41 and (tunnel[nr][nc] >> color & 1) and colored[nr][nc] != color) cand_score += 3;
            if (colored[nr][nc] == -1) cand_score++;
          }
          if (cand_score > up_score) {
            cr = r, cc = c, cd = d;
            up_score = cand_score;
          }
        }
      }
    }
    if (cr != -1) {
      for (int res_cnt = 5, nr = cr, nc = cc; res_cnt >= 0 and in_board(nr, nc);
           res_cnt--, nr += dr[cd], nc += dc[cd]) {
          colored[nr][nc] = color;
      }
    }
    ans[m] = std::make_tuple(cr, cc, cd);
  }
  std::cerr << calc_score(colored) << '\n';
  output(ans);
}

int main() {
  input();
  n_conn = 0;
  solve();

  return 0;
}