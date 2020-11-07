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

// graph by adjacency list
template <typename T>
struct Edge {
  int dst; T weight;
  Edge(int dst, T weight) : dst(dst), weight(weight) { }
  bool operator < (const Edge<T> &e) const {
    return weight > e.weight;
  }
};

template <typename T>
struct Graph {
  int V;
  vector<vector<Edge<T>>> E;
  Graph(int V) : V(V) { E.resize(V); }
  void add_edge(int src, int dst, T weight) {
    E[src].emplace_back(dst, weight);
  }
};


const ll INF = 1e12;

template <typename T>
struct Node {
  int v; T dist;
  Node(int v, T dist) : v(v), dist(dist) { };
  bool operator < (const Node<T> &n) const {
    return dist > n.dist; // reverse
  }
};

template <typename T>
struct ShortestPath {
  const Graph<T> g;
  vector<T> dist;
  vector<int> prev;

  ShortestPath(const Graph<T> &g) : g(g) { dist.resize(g.V), prev.resize(g.V); }

  void run(int start) {
    priority_queue<Node<T>> que;
    dist.assign(g.V, INF);
    dist[start] = 0;
    que.emplace(start, 0);
    prev[0] = -1;

    while (!que.empty()) {
      Node<T> n = que.top(); que.pop();
      int v = n.v; T cost = n.dist;
      if (dist[v] < cost) continue;
      for (Edge<T> e : g.E[v]) {
        if (dist[v] < dist[e.dst] - e.weight) {
          dist[e.dst] = dist[v] + e.weight;
          prev[e.dst] = v;
          que.emplace(e.dst, dist[e.dst]);
        }
      }
    }
  }

  vector<int> build_path(int goal) {
    vector<int> path;
    for (int v = goal; v != -1; v = prev[v]) {
      path.emplace_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
  }
};

/**
 * @brief type for input data
 */
template <typename T>
struct Data {
  using type = T;
  type data;

  /**
   * Constructor for Data
   * @param data Data should be std::array
   */
  Data(type &data) : data(data) {}

  /**
   * Comparing function for data.
   * This function compares two data in lexicographical order.
   *
   * @param data1 First data for comparing
   * @param data2 Second data for comparing
   * @param base Start dimension for comparing.
   *
   * @return If data1 < data1 in lexicographical order, then true, otherwise false.
   */
  static bool compare (const Data<type> &data1, const Data<type> &data2, size_t base = 1) {
    const size_t dim = data1.data.size();
    for (size_t i = 0; i < dim; i++) {
      if (data1.data[(i + base) % dim] != data2.data[(i + base) % dim]) {
        return data1.data[(i + base) % dim] < data2.data[(i + base) % dim];
      }
    }
    return false;
  }
  /**
   * == operator for data
   */
  bool operator==(const Data<type> &data) const {
    return this->data == data.data;
  }
};

/**
 * Orthogonal Region for
 */
template <typename T>
struct Region {
  T low, high;
  /**
   * Constructor for struct Region
   * If d = low.size(), then corresponding orthogonal region R is following.
   * R = [low[0], high[0]] * [low[1], high[1]] * ... * [low[d-1], high[d-1]]
   *
   * @param low lower borders of orthogonal region
   * @param high higher borders of orthogonal region
   */
  Region(T &low, T &high) : low(low), high(high) {};

  /**
   * Checking Function of Inclusion for Data and Region.
   *
   * @param data A data
   * @return If this region include the data, then return true, otherwise return false.
   */
  bool include(T data) const {
    size_t dim = this->low.size();
    for (size_t i = 0; i < dim; i++) {
      if (data[i] < low[i] or high[i] < data[i]) {
        return false;
      }
    }
    return true;
  }

  /**
   * Checking Function of Inclusion for Two Regions.
   *
   * @param region A region.
   * @return If this region include the given region, then return true, otherwise return false.
   */
  bool include(const Region<T> &region) const {
    size_t dim = this->low.size();
    for (size_t bit = 0; bit < (1U << dim); bit++) {
      T data;
      for (size_t i = 0; i < dim; i++) {
        if (bit >> i & 1) {
          data[i] = region.low[i];
        } else {
          data[i] = region.high[i];
        }
      }
      if (not this->include(data)) {
        return false;
      }
    }
    return true;
  }

  /**
   * Cheking Function of Overlapping for Two Regions.
   *
   * @param region A region.
   * @return If this region overlaps the given region, then return true, otherwise return false.
   */
  bool overlap(Region<T> &region) const {
    size_t dim = this->low.size();
    for (size_t bit = 0; bit < (1U << dim); bit++) {
      T data;
      for (size_t i = 0; i < dim; i++) {
        if (bit >> i & 1) {
          data[i] = region.low[i];
        } else {
          data[i] = region.high[i];
        }
      }
      if (this->include(data)) {
        return true;
      }
    }
    return false;
  }

  /**
   * overloading of << operator
   */
  friend std::ostream& operator<<(std::ostream& os, const Region<T> &region) {
    for (size_t i = 0; i < region.low.size(); i++) {
      if (i > 0) {
        os << 'x';
      }
      os << '[' << region.low[i] << ',' << region.high[i] << ']';
    }
    return os;
  }
};

struct RangeTreeNode {
  size_t idx;                   /**< Node index */
  int node_count;
  RangeTreeNode *assoc;         /**< Pointer of associated structure */
  RangeTreeNode *left, *right;  /**< Pointer of left & right node */
  RangeTreeNode(size_t idx) : idx(idx), node_count(1), assoc(nullptr), left(nullptr), right(nullptr) {}
  bool is_leaf_node() const {
    return left == nullptr and right == nullptr;
  }
};

template <typename DataType>
struct RangeTree {
  using T = typename DataType::type;
  using VT = typename T::value_type;
  size_t dim;                   /**< Dimension of Data */
  std::vector<DataType> data;   /**< Data in range tree */
  VT min_range, max_range;      /**< Initial Range for range query */
  RangeTreeNode *root;          /**< Root Node */

  RangeTree(size_t dim = 2, VT min_range = std::numeric_limits<VT>::min(), VT max_range = std::numeric_limits<VT>::max()) : dim(dim), min_range(min_range), max_range(max_range) {}

  RangeTreeNode *build_1d(std::vector<size_t> &data, size_t low, size_t high) {
    if (low + 1 == high) {
      return new RangeTreeNode(data[low]);
    }
    size_t median = (low + high) / 2;
    RangeTreeNode *node = new RangeTreeNode(data[median]);
    if (low < median) {
      node->left = build_1d(data, low, median);
      node->node_count += node->left->node_count;
    }
    if (median + 1 < high) {
      node->right = build_1d(data, median + 1, high);
      node->node_count += node->right->node_count;
    }
    return node;
  }

  RangeTreeNode *build(std::vector<std::vector<size_t>> &data, size_t depth) {
    RangeTreeNode *assoc;
    if (depth + 2 ==  this->dim) {
      assoc = build_1d(data[depth + 1], 0, data[0].size());
    } else {
      assoc = build(data, depth + 1);
    }

    if (data[0].size() == 1) {
      RangeTreeNode *node = new RangeTreeNode(data[0][0]);
      node->assoc = new RangeTreeNode(data[0][0]);
      return node;
    }
    std::vector<std::vector<size_t>> left_data(this->dim), right_data(this->dim);
    size_t median_idx = static_cast<size_t>(static_cast<int>(data[0].size()) / 2);
    size_t median = data[depth % this->dim][median_idx];
    for (size_t i = 0; i < this->dim; i++) {
      for (size_t j : data[i]) {
        if (DataType::compare(this->data[j], this->data[median], depth % this->dim)) {
          left_data[i].emplace_back(j);
        } else if (not (this->data[j] == this->data[median])) {
          right_data[i].emplace_back(j);
        }
      }
    }
    RangeTreeNode *node = new RangeTreeNode(median);
    if (left_data[0].size()) {
      node->left = build(left_data, depth);
      node->node_count += node->left->node_count;
    }
    if (right_data[0].size()) {
      node->right = build(right_data, depth);
      node->node_count += node->right->node_count;
    }
    node->assoc = assoc;
    return node;
  }

  void build(std::vector<DataType> &data) {
    assert(data.size() > 0);
    std::vector<std::vector<size_t>> _data(this->dim, std::vector<size_t>(data.size()));
    this->data = std::move(data);
    for (size_t i = 0; i < this->dim; i++) {
      std::iota(_data[i].begin(), _data[i].end(), 0);
      sort(_data[i].begin(), _data[i].end(),
           [&](const size_t &a, const size_t &b) {
             return DataType::compare(this->data[a], this->data[b], i);
           });
    }
    this->root = build(_data, 0);
  }

  void output(bool assoc = true) const {
    output(this->root, assoc);
  }

  void output(RangeTreeNode *node, bool assoc = true) const {
    if (node == nullptr) return ;
    std::cout << "idx: " << node->idx << ", (";
    for (size_t i = 0; i < this->dim; i++) {
      if (i > 0) {
        std::cout << ',';
      }
      std::cout << this->data[node->idx].data[i];
    }
    std::cout << ") ";
    if (not node->is_leaf_node()) {
      std::cout << "(left, right) = (" << (node->left == nullptr ? -1 : (int)node->left->idx) << ',' << (node->right == nullptr ? -1 : (int)node->right->idx) << ')' << std::endl;
      if (node->assoc != nullptr and assoc) {
        std::cout << "assoc start" << std::endl;
        output(node->assoc, assoc);
        std::cout << "assoc end" << std::endl;
      }
      output(node->left, assoc);
      output(node->right, assoc);

    } else {
      std::cout << std::endl;
    }
  }

  RangeTreeNode *find_split_node(RangeTreeNode *node, size_t dim, DataType &low, DataType &high) const {

    while (node != nullptr and (DataType::compare(this->data[node->idx], low, dim) or
                                not DataType::compare(this->data[node->idx], high, dim))) {
      if (DataType::compare(this->data[node->idx], low, dim)) {
        node = node->right;
      } else {
        node = node->left;
      }
    }
    return node;
  }

  void report_subtree(RangeTreeNode *node, std::vector<size_t> &output) const {
    if (node == nullptr) return ;
    output.emplace_back(node->idx);
    report_subtree(node->left, output);
    report_subtree(node->right, output);
  }

  void query(Region<T> &query_region, std::vector<size_t> &output) const {
    query(this->root, query_region, 0, output);
  }

  int count_query(Region<T> &query_region) const {
    return count_query(this->root, query_region, 0);
  }

  void query(RangeTreeNode *node, Region<T> &query_region, size_t dim, std::vector<size_t> &output) const {
    if (node == nullptr) {
      return ;
    }
    T low_, high_;
    low_.fill(this->min_range), high_.fill(this->max_range);
    low_[dim] = query_region.low[dim], high_[dim] = query_region.high[dim];
    DataType low(low_), high(high_);

    RangeTreeNode *split_node = this->find_split_node(node, dim, low, high);

    if (split_node == nullptr) {
      return ;
    }

    //std::cout << "split: " << split_node->idx << ' ' << dim << std::endl;
    if (query_region.include(this->data[split_node->idx].data)) {
      output.emplace_back(split_node->idx);
    }

    node = split_node->left;
    while (node != nullptr) {
      //std::cout << "left: " << node->idx << ' ' << dim << std::endl;
      if (query_region.include(this->data[node->idx].data)) {
        output.emplace_back(node->idx);
      }

      if (DataType::compare(this->data[node->idx], low, dim)) {
        node = node->right;
      } else {
        if (dim + 1 == this->dim) {
          report_subtree(node->right, output);
        } else if (node->right != nullptr) {
          query(node->right->assoc, query_region, dim + 1, output);
        }
        node = node->left;
      }
    }

    node = split_node->right;
    while (node != nullptr) {
      //std::cout << "right: " << node->idx << ' ' << dim << std::endl;
      if (query_region.include(this->data[node->idx].data)) {
        output.emplace_back(node->idx);
      }
      if (DataType::compare(this->data[node->idx], high, dim)) {
        if (dim + 1 == this->dim) {
          report_subtree(node->left, output);
        } else if (node->left != nullptr) {
          query(node->left->assoc, query_region, dim + 1, output);
        }
        node = node->right;
      } else {
        node = node->left;
      }
    }
  }

  int count_query(RangeTreeNode *node, Region<T> &query_region, size_t dim) const {
    if (node == nullptr) {
      return 0;
    }
    T low_, high_;
    low_.fill(this->min_range), high_.fill(this->max_range);
    low_[dim] = query_region.low[dim], high_[dim] = query_region.high[dim];
    DataType low(low_), high(high_);

    RangeTreeNode *split_node = this->find_split_node(node, dim, low, high);

    if (split_node == nullptr) {
      return 0;
    }

    int node_count = 0;
    //std::cout << "split: " << split_node->idx << ' ' << dim << std::endl;
    if (query_region.include(this->data[split_node->idx].data)) {
      node_count++;
    }

    node = split_node->left;
    while (node != nullptr) {
      //std::cout << "left: " << node->idx << ' ' << dim << std::endl;
      if (query_region.include(this->data[node->idx].data)) {
        node_count++;
      }

      if (DataType::compare(this->data[node->idx], low, dim)) {
        node = node->right;
      } else {
        if (dim + 1 == this->dim) {
          node_count += node->right == nullptr ? 0 : node->right->node_count;
        } else if (node->right != nullptr) {
          node_count += count_query(node->right->assoc, query_region, dim + 1);
        }
        node = node->left;
      }
    }

    node = split_node->right;
    while (node != nullptr) {
      //std::cout << "right: " << node->idx << ' ' << dim << std::endl;
      if (query_region.include(this->data[node->idx].data)) {
        node_count++;
      }
      if (DataType::compare(this->data[node->idx], high, dim)) {
        if (dim + 1 == this->dim) {
          node_count += node->left == nullptr ? 0 : node->left->node_count;
        } else if (node->left != nullptr) {
          node_count += count_query(node->left->assoc, query_region, dim + 1);
        }
        node = node->right;
      } else {
        node = node->left;
      }
    }

    return node_count;
  }

};

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, M; cin >> N >> M;
  Graph<ll> g1(N), g2(N);
  REP(i, M) {
    int a, b; ll c; cin >> a >> b >> c;
    g1.add_edge(a, b, c);
    g1.add_edge(b, a, c);
    g2.add_edge(a, b, c);
    g2.add_edge(b, a, c);
  }

  ShortestPath<ll> sp1(g1), sp2(g2);
  sp1.run(0), sp2.run(N - 1);

  using DataType = Data<std::array<ll, 3>>;
  RangeTree<DataType> range_tree(2, 0);
  std::vector<DataType> points;
  REP(i, N) {
    DataType::type tmp = {sp1.dist[i], sp2.dist[i], i};
    points.emplace_back(DataType(tmp));
  }
  range_tree.build(points);
  int Q; cin >> Q;
  REP(i, Q) {
    ll fs, gs; cin >> fs >> gs;
    DataType::type low = {range_tree.min_range, gs, 0}, high = {fs, range_tree.max_range, N - 1};
    Region<DataType::type> query_region(low, high);
    //std::vector<size_t> out;
    //range_tree.query(query_region, out);
    //std::cout << out.size() << std::endl;
    std::cout << range_tree.count_query(query_region) << std::endl;
  }
  return 0;
}
