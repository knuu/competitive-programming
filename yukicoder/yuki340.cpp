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

#define INF 1<<30

// graph by adjacency list
struct Edge {
  int dst, weight;
  Edge(int dst, int weight) :
    dst(dst), weight(weight) { }
  bool operator < (const Edge &e) const {
    return weight > e.weight;
  }
};


int imos_w[1000010], imos_h[1000010];
int V;

struct Node {
  int v, dist;
  Node(int v, int dist) :
    v(v), dist(dist) { };
  bool operator < (const Node &n) const {
    return dist > n.dist; // reverse
  }
};

int dist[1000010], used[1000010];

struct ShortestPath {
  int start;

  ShortestPath(int start) : start(start) { }

  void dijkstra(int goal) {
    std::priority_queue<Node> que;
    dist[start] = 0;
    que.push(Node(start, 0));

    while (!que.empty()) {
      Node n = que.top(); que.pop();
      int v = n.v, cost = n.dist;
      if (v == goal) return ;
      if (dist[v] < cost) continue;
      if (imos_w[v] and (not used[v+1] or dist[v] + 1 < dist[v+1])) {
	dist[v+1] = dist[v] + 1;
	used[v+1] = true;
	que.push(Node(v+1, dist[v+1]));
      }
      if (v > 0 and imos_w[v-1] and (not used[v-1] or dist[v] + 1 < dist[v-1])) {
	dist[v-1] = dist[v] + 1;
	que.push(Node(v-1, dist[v-1]));
	used[v-1] = true;
      }
      int vv = (v%W)*H+v/W;
      if (imos_h[vv] and (not used[vv] or dist[v] + 1 < dist[v+W])) {
	dist[v+W] = dist[v] + 1;
	que.push(Node(v+W, dist[v+W]));
	used[v+W] = true;
      }
    }
  }

};


int main() {
  int W, H, N;
  scanf("%d%d%d", &W, &H, &N);
  V = W * H;

  REP(i, N) {
    int M, prev; scanf("%d%d", &M, &prev);
    REP(i, M) {
      int b; scanf("%d", &b);
      int p1 = prev, p2 = b; if (p1 > p2) swap(p1, p2);
      int r1 = p1 / W, c1 = p1 % W, r2 = p2 / W, c2 = p2 % W;
      //cout << '(' << r1 << ',' << c1 << ')' << ' ' << '(' << r2 << ',' << c2 << ')' << endl;
      if (r1 == r2) {
	imos_w[p1]++, imos_w[p2]--;
      } else if (c1 == c2) {
	imos_h[c1 * H + r1]++, imos_h[c2 * H + r2]--;
      }
      prev = b;
    }
  }
  REP(i, W*H-1) imos_h[i+1] += imos_h[i], imos_w[i+1] += imos_w[i];

  Graph g(H*W);
  REP(i, H*W) {
    if (imos_w[i]) g.add_edge(i, i+1, 1), g.add_edge(i+1, i, 1);
    if (imos_h[i]) {
      int p1 = (i%H)*W+i/H, p2 = p1 + W;
      g.add_edge(p1, p2, 1), g.add_edge(p2, p1, 1);
    }
  }
  /*REP(i, W*H) {
    cout << i << ':';
    for (auto v : g.E[i]) cout << v.dst << ' ';
    cout << endl;
    }*/

  ShortestPath sp(g, 0);
  sp.dijkstra(W*H-1);
  if (dist[W*H-1] == INF) {
    printf("Odekakedekinai..\n");
  } else {
    printf("%d\n", dist[W*H-1]);
  }
  //REP(i, g.V) cout << sp.dist[i] << (i == g.V-1 ? '\n' : ' ');
  return 0;
}
