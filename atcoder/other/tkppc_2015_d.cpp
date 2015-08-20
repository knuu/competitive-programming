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

int N, R, C;
vector<vector<string>> board;
vector<P> edge[1000010];
int dist[1000010];
int INF = 1000000;

int enc(int f, int r, int c) {
  return f * R * C + r * C + c;
}

int main() {
  cin >> N >> R >> C;
  REP(i, N) {
    vector<string> vs;
    REP(j, R) {
      string s;
      cin >> s;
      vs.push_back(s);
    }
    board.push_back(vs);
  }

  REP(f, N) REP(r, R) REP(c, C) {
    int now = enc(f, r, c);
    if (board[f][r][c] == 'H') {
      edge[now].push_back(make_pair(enc(f+1, r, c), board[f+1][r][c]-'0'));
    } else {
      if (r < R-1) {
	int next = enc(f, r+1, c), cost;
	if (board[f][r+1][c] == 'H') {
	  cost = 0;
	} else {
	  cost = board[f][r+1][c] - '0';
	}
	edge[now].push_back(make_pair(next, cost));
      }
      if (c < C-1) {
	int next = enc(f, r, c+1), cost;
	if (board[f][r][c+1] == 'H') {
	  cost = 0;
	} else {
	  cost = board[f][r][c+1] - '0';
	}
	edge[now].push_back(make_pair(next, cost));
      }
    }
  }
  REP(i, N*R*C) dist[i] = INF;
  dist[0] = 0;
  priority_queue<P, vector<P>, greater<P>> pque;
  pque.push(make_pair(0, 0));
  while (pque.size()) {
    P p = pque.top(); pque.pop();
    int d = p.fst, fr = p.snd;
    if (dist[fr] < d) continue;
    REP(i, edge[fr].size()) {
      P np = edge[fr][i];
      int to = np.fst, cost = np.snd;
      if (dist[fr] + cost < dist[to]) {
	dist[to] = dist[fr] + cost;
	pque.push(make_pair(dist[to], to));
      }
    }
  }
  cout << dist[N*R*C-1] << endl;
  return 0;
}
