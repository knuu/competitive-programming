// for poj (old g++ version, cannot use bits/stdc++.h)

#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <iostream>
#include <bitset>
#include <algorithm>
#include <complex>
#include <string>
#include <utility>

using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
typedef pair<int, P> T;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)
#define ALL(c) c.begin(), c.end()
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

#define INF 1<<29

template <typename T>
struct MaxFlow {
  struct Edge {
    int to, rev; T cap;
    Edge(int to, int rev, T cap) : to(to), rev(rev), cap(cap) { }
  };

  typedef vector<Edge> Edges;
  vector<Edges> G;
  int V;
  vector<int> level, iter;

  MaxFlow(int V) : V(V) { G.resize(V); }

  void add_edge(int from, int to, T cap) {
    G[from].push_back(Edge(to, G[to].size(), cap));
    G[to].push_back(Edge(from, (int)G[from].size()-1, 0));
  }

  void bfs(int source) {
    level.assign(V, -1);
    queue<int> que;
    que.push(source);
    level[source] = 0;
    while (!que.empty()) {
      int v = que.front(); que.pop();
      for (int i = 0; i < (int)G[v].size(); i++) {
        Edge &e = G[v][i];
        if (e.cap > 0 && level[e.to] < 0) {
          level[e.to] = level[v] + 1;
          que.push(e.to);
        }
      }
    }
  }

  T dfs(int v, int sink, T flow) {
    if (v == sink) return flow;
    for (int &i = iter[v]; i < (int)G[v].size(); i++) {
      Edge &e = G[v][i];
      if (e.cap > 0 && level[v] < level[e.to]) {
        T d = dfs(e.to, sink, min(e.cap, flow));
        if (d > 0) {
          e.cap -= d;
          G[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }

  T dinic(int source, int sink) {
    T flow = 0;
    while (true) {
      bfs(source);
      if (level[sink] < 0) return flow;
      iter.assign(V, 0);
      T f;
      while ((f = dfs(source, sink, INF)) > 0) flow += f;
    }
  }
};


int main() {
  int N, F, D; scanf("%d %d %d", &N, &F, &D);
  MaxFlow<int> mf(F+D+2*N+2);
  int source = F+D+2*N;
  REP(i, F) mf.add_edge(source, i, 1);
  REP(i, D) mf.add_edge(F+2*N+i, source+1, 1);
  REP(i, N) mf.add_edge(F+i, F+N+i, 1);

  REP(i, N) {
    int cf, cd; scanf("%d %d", &cf, &cd);
    REP(_, cf) {
      int f; scanf("%d", &f); f--;
      mf.add_edge(f, F+i, 1);
    }
    REP(_, cd) {
      int d; scanf("%d", &d); d--;
      mf.add_edge(F+N+i, F+2*N+d, 1);
    }
  }

  printf("%d\n", mf.dinic(source, source+1));
  return 0;
}
