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

const int INF = 1<<30;
#define MAX_V 1000010

// graph by adjacency list
struct Edge {
  int dst, weight;
  Edge(int dst, int weight) :
    dst(dst), weight(weight) { }
  bool operator < (const Edge &e) const {
    return weight > e.weight;
  }
};

vector<Edge> E[1000010];

struct Graph {
  int V;

  Graph(int V) : V(V) { }

  inline void add_edge(int src, int dst, int weight) {
    E[src].push_back(Edge(dst, weight));
  }
};

struct Node {
  int v, dist;
  Node(int v, int dist) :
    v(v), dist(dist) { };
  bool operator < (const Node &n) const {
    return dist > n.dist; // reverse
  }
};

int dist[1000010];

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
      if (dist[v] < cost) continue;
      for (Edge e : E[v]) {
	if (dist[v] + e.weight < dist[e.dst]) {
	  dist[e.dst] = dist[v] + e.weight;
	  if (n.v == goal) return ;
	  que.push(Node(e.dst, dist[e.dst]));
	}
      }
    }
  }
};

int curve[1000010], imos_w[1000010], imos_h[1000010];

int main() {
  int W, H, N, V;
  scanf("%d%d%d", &W, &H, &N); V = W*H;

  REP(i, N) {
    int M, prev; scanf("%d%d", &M, &prev);
    curve[prev] = 1;
    REP(j, M) {
      int b; scanf("%d", &b);
      curve[b] = 1;
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
  REP(i, V-1) dist[i+1] = INF, imos_h[i+1] += imos_h[i], imos_w[i+1] += imos_w[i];

  FOR(i, 1, V-1) {
    int p = (i%W)*H+i/W;
    if ((imos_w[i-1] or imos_w[i]) and (imos_h[p-1] or imos_h[p])) curve[i] = true;
  }
  /*
  REP(i, V) {
    if (curve[i]) cout << i << ' ';
  }
  cout << endl; //*/
  //REP(i, V) cout << curve[i] << (i == V-1 ? '\n' : ' ');


  Graph g(V);
  REP(i, V-1) {
    if (imos_w[i]) {
      int n = i;
      while (imos_w[n] == imos_w[n+1] and not curve[n+1]) n++;
      //cout << i << ' ' << n+1 << endl;
      g.add_edge(i, n+1, n+1-i), g.add_edge(n+1, i, n+1-i);
      i = n;
    }
  }
  REP(i, V-1) {
    if (imos_h[i]) {
      int n = i;
      while (imos_h[n] == imos_h[n+1] and not curve[(n%H)*W+n/H+W]) n++;
      int p1 = (i%H)*W+i/H, p2 = (n%H)*W+n/H;
      //cout << p1 << ' ' << p2+W << endl;
      g.add_edge(p1, p2+W, n+1-i), g.add_edge(p2+W, p1, n+1-i);
      i = n;
    }
  }

  /*
  REP(i, V) {
    if (not g.E[i].size()) continue;
    cout << i << ':';
    for (auto v : g.E[i]) cout << v.dst << ' ';
    cout << endl;
    } // */

  ShortestPath sp(0);
  sp.dijkstra(V-1);
  if (dist[V-1] == INF) {
    printf("Odekakedekinai..\n");
  } else {
    printf("%d\n", dist[V-1]);
  }
  //REP(i, g.V) cout << sp.dist[i] << (i == g.V-1 ? '\n' : ' ');
  return 0;
}
