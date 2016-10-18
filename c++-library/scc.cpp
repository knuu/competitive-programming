struct StronglyConnectedComponents {
  int V;
  vector<vector<int>> G, rG;
  vector<int> vs, cmp;
  vector<bool> used;

  StronglyConnectedComponents(int V) : V(V) {
    used.assign(V, false);
    G.resize(V), rG.resize(V);
    cmp.resize(V);
  }

  void add_edge(int from, int to) {
    G[from].push_back(to);
    rG[to].push_back(from);
  }

  void dfs(int v) {
    used[v] = true;
    for (int c : G[v]) if (not used[c]) dfs(c);
    vs.push_back(v);
  }

  void rdfs(int v, int k) {
    used[v] = true;
    cmp[v] = k;
    for (int c : rG[v]) if (not used[c]) rdfs(c, k);
  }

  int run() {
    fill(used.begin(), used.end(), false);
    vs.clear();
    for (int v = 0; v < V; v++) if (!used[v]) dfs(v);
    fill(used.begin(), used.end(), false);
    int k = 0;
    for (int i = vs.size() - 1; i >= 0; i--) if (!used[vs[i]]) rdfs(vs[i], k++);
    return k;
  }
};
