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
const ll INF = 1e12;

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, M, K; cin >> N >> M >> K;
  string dir_; cin >> dir_;
  vector<int> dir(2 * K);
  map<char, int> mp = {{'U', 0}, {'D', 2}, {'L', 3}, {'R', 1}};
  REP(i, 2 * K) dir[i] = mp[dir_[i % K]];

  vector<vector<ll>> cost(4, vector<ll>(2 * K, INF));
  REP(i, 4) {
    if (dir[2 * K - 1] == i) cost[i][2 * K - 1] = 1;
    for (int j = 2 * K - 2; j >= 0; j--) {
      if (dir[j] == i) {
        cost[i][j] = 1;
      } else {
        cost[i][j] = cost[i][j + 1] + 1;
      }
    }
  }
  //REP(i, 4) REP(j, K) cout << cost[i][j] << (j == K - 1 ? '\n' : ' ');

  vector<vector<int>> board(N, vector<int>(M));
  int sr, sc, gr, gc;
  REP(i, N) {
    string row; cin >> row;
    REP(j, M) {
      if (row[j] == 'S') {
        sr = i, sc = j;
        board[i][j] = 0;
      } else if (row[j] == 'G') {
        gr = i, gc = j;
        board[i][j] = 0;
      } else if (row[j] == '.') {
        board[i][j] = 0;
      } else {
        board[i][j] = 1;
      }
    }
  }

  vector<vector<ll>> dist(N, vector<ll>(M, INF));
  dist[sr][sc] = 0;
  typedef tuple<ll, int, int> T;
  priority_queue<T, vector<T>, greater<T>> pque;
  pque.emplace(0, sr, sc);
  while (not pque.empty()) {
    ll d; int r, c; tie(d, r, c) = pque.top(); pque.pop();
    //cout << d << ' ' << r << ' ' << c << endl;
    if (d > dist[r][c]) continue;
    if (r == gr and c == gc) break;
    REP(i, 4) {
      int nr = r + dr[i], nc = c + dc[i];
      if (0 <= nr and nr < N and 0 <= nc and nc < M and board[nr][nc] == 0 and d + cost[i][d % K] < dist[nr][nc]) {
        dist[nr][nc] = d + cost[i][d % K];
        pque.emplace(dist[nr][nc], nr, nc);
      }
    }
  }

  cout << (dist[gr][gc] == INF ? -1 : dist[gr][gc]) << endl;



  return 0;
}
