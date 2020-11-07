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


struct DisjointSet {
  vector<int> parent, rank;

  DisjointSet(int N) {
    parent.resize(N), rank.resize(N, 0);
    for (int i = 0; i < N; i++) parent[i] = i;
  }

  int find(int x) {
    if (parent[x] == x) {
      return x;
    } else {
      return parent[x] = find(parent[x]);
    }
  }

  void unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return ;
    if (rank[x] < rank[y]) {
      parent[x] = y;
    } else {
      parent[y] = x;
      if (rank[x] == rank[y]) rank[x]++;
    }
  }

  bool same(int x, int y) { return find(x) == find(y); }
};

#define MAX_LOG_V 17

Vi edge[100010];
int root;

int parent[MAX_LOG_V][100010];
int depth[100010];

void dfs(int v, int par, int dep) {
  parent[0][v] = par;
  depth[v] = dep;
  for (auto child : edge[v]) {
    if (child != par) dfs(child, v, dep + 1);
  }
}

void init(int V) {
  dfs(root, -1, 0);
  for (int k = 0; k + 1 < MAX_LOG_V; k++) {
    for (int v = 0; v < V; v++) {
      if (parent[k][v] < 0) {
        parent[k+1][v] = -1;
      } else {
        parent[k+1][v] = parent[k][parent[k][v]];
      }
    }
  }
}

int u_cnt, v_cnt;
int lca(int u, int v) {
  u_cnt = 0, v_cnt = 0;
  if (depth[u] > depth[v]) swap(u, v);
  for (int k = 0; k < MAX_LOG_V; k++) {
    if ((depth[v] - depth[u]) >> k & 1) {
      v = parent[k][v];
      v_cnt += 1 << k;
    }
  }
  if (u == v) return u;
  for (int k = MAX_LOG_V - 1; k >= 0; k--) {
    if (parent[k][u] != parent[k][v]) {
      u = parent[k][u];
      v = parent[k][v];
      u_cnt += 1 << k;
      v_cnt += 1 << k;
    }
  }
  u_cnt++, v_cnt++;
  return parent[0][u];
}

int get_cnt(int v, int cnt) {
  for (int k = MAX_LOG_V - 1; k >= 0; k--) {
    if (cnt >> k & 1) {
      v = parent[k][v];
    }
  }
  return v;
}

int main() {
  // use scanf in CodeForces!
  //cin.tie(0);
  //ios_base::sync_with_stdio(false);

  int N, M; cin >> N >> M;
  DisjointSet uf(N);
  vector<int> q_num(N, -1);
  root = N;

  REP(i, M) {
    int a, b; cin >> a >> b; a--, b--;
    if (not uf.same(a, b)) {
      a = uf.find(a), b = uf.find(b);
      uf.unite(a, b);
      edge[a].emplace_back(b);
      edge[b].emplace_back(a);
      if (uf.find(a) == a) {
        q_num[b] = i + 1;
      } else {
        q_num[a] = i + 1;
      }
    }
  }

  REP(i, N) if (uf.parent[i] == i) edge[N].emplace_back(i);
  init(N + 1);

  /*
  REP(i, N) {
    REP(j, 10) cout << parent[j][i] << ' ';
    cout << endl;
    }
  //*/
  //REP(i, N) cout << q_num[i] << (i == N - 1 ? '\n' : ' ');
  int Q; cin >> Q;
  REP(i, Q) {
    int x, y; cin >> x >> y; x--, y--;
    if (not uf.same(x, y)) {
      cout << -1 << endl;
    } else {
      if (depth[x] > depth[y]) swap(x, y);
      int anc = lca(x, y);
      int v1 = get_cnt(x, max(0, u_cnt - 1));
      int v2 = get_cnt(y, max(0, v_cnt - 1));
      //cout << anc << ':' << u_cnt << ' ' << v_cnt << ':' << v1 << ' ' << v2 << endl;
      if (u_cnt == 0) {
        cout << q_num[v2] << endl;
      } else if (v_cnt == 0) {
        cout << q_num[v1] << endl;
      } else {
        cout << max(q_num[v1], q_num[v2]) << endl;
      }
      //cout << anc << endl;
      //cout << u_cnt << ' ' << v_cnt << endl;
    }
  }

  return 0;
}
