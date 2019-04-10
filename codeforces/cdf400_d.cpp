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


int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, M; cin >> N >> M;
  vector<int> rooms(N); REP(i, N) cin >> rooms[i];
  vector<vector<int>> door2switch(N);

  REP(i, M) {
    int x; cin >> x;
    REP(_, x) {
      int y; cin >> y; y--;
      door2switch[y].emplace_back(i);
    }
  }

  DisjointSet uf(2 * M);
  REP(i, N) {
    int s1 = door2switch[i][0], s2 = door2switch[i][1];
    if (rooms[i] == 1) {
      uf.unite(s1, s2);
      uf.unite(s1 + M, s2 + M);
    } else {
      uf.unite(s1, s2 + M);
      uf.unite(s1 + M, s2);
    }
  }

  REP(i, M) {
    if (uf.same(i, i + M)) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
