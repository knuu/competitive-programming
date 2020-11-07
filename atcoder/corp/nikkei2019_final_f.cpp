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


template<class Monoid>
struct SegmentTree {
  using T = typename Monoid::type;
  int N_, N;
  std::vector<T> dat;

  SegmentTree() { }
  SegmentTree(const int N_) : N_(N_) {
    assert(N_ > 0);
    N = 1;
    while (N < N_) {
      N <<= 1;
    }
    dat.assign(2 * N - 1, Monoid::identity());
  }

  SegmentTree(const std::vector<T> &dat_) : N_(dat_.size()) {
    assert(N_ > 0);
    N = 1;
    while (N < N_) {
      N <<= 1;
    }
    dat.assign(2 * N - 1, Monoid::identity());
    std::copy(dat_.begin(), dat_.end(), dat.begin() + N - 1);
    for (int i = N - 2; i >= 0; i--) {
      dat[i] = Monoid::merge(dat[2 * i + 1], dat[2 * i + 2]);
    }
  }

  int size() { return N_; }

  void update(int key, T val) {
    assert(0 <= key && key < N_);

    key += N - 1;
    dat[key] = val;

    while (key > 0) {
      key = (key - 1) / 2;
      dat[key] = Monoid::merge(dat[2 * key + 1], dat[2 * key + 2]);  // rewrite here
    }
  }

  // [a, b)
  T query(int low, int high) {
    assert(0 <= low && low <= high && high <= N_);
    return query(low, high, 0, 0, N);
  }

  T query(int low, int high, int key, int left, int right) {
    if (right <= low || high <= left) return Monoid::identity();
    if (low <= left && right <= high) return dat[key];

    int mid = (left + right) / 2;
    return Monoid::merge(query(low, high, 2 * key + 1, left, mid),
                         query(low, high, 2 * key + 2, mid, right));  // rewrite here
  }
};

template <typename T>
struct RangeSumQuery {
  using type = T;
  static type identity() { return 0; }
  static type merge(const type &l, const type &r) {
    return l + r;
  }
};

template <typename T>
struct RangeMinQuery {
  using type = T;
  static type identity() { return INT_MAX; }
  static type merge(const type &l, const type &r) {
    return min(l, r);
  }
};

template <typename T>
struct RangeMaxQuery {
  using type = T;
  static type identity() { return 0; }
  static type merge(const type &l, const type &r) {
    return max(l, r);
  }
};


template <typename T>
struct Point2D {
  T x, y;
  ll val;
  size_t idx;
  Point2D(T x, T y, ll val, size_t idx) : x(x), y(y), val(val), idx(idx) {}
  bool operator<(const Point2D<T> &other) const {
    return this->x < other.x or (this->x == other.x and this->y < other.y);
  }
};

template <typename T>
struct RangeTreeNode {
  T low, high;
  std::vector<T> assoc;
  std::vector<size_t> indices;
  map<size_t, size_t> rev_indices;
  SegmentTree<RangeMinQuery<ll>> *rmq;
  std::vector<ll> vals;
  RangeTreeNode(T inf = std::numeric_limits<T>::max()) : low(inf), high(inf), assoc(), indices() {}
};

template <typename T>
struct RangeTree2D {
  size_t size_;
  std::vector<Point2D<T>> points;
  std::vector<RangeTreeNode<T>> data;
  std::vector<int> rev_idx;
  T inf;
  RangeTree2D(T inf = std::numeric_limits<T>::max()) : inf(inf) {}

  void build(std::vector<Point2D<T>> points) {
    this->points = points;
    std::sort(this->points.begin(), this->points.end());
    rev_idx.resize(points.size());
    this->size_ = 1;
    while (this->size_ < points.size()) {
      this->size_ <<= 1;
    }
    data.assign(2 * this->size_ - 1, RangeTreeNode<T>());
    for (size_t i = 0; i < this->points.size(); i++) {
      size_t idx = this->size_ - 1 + i;
      data[idx].low = data[idx].high = this->points[i].x;
      data[idx].assoc.emplace_back(this->points[i].y);
      data[idx].indices.emplace_back(this->points[i].idx);
      rev_idx[this->points[i].idx] = i;
    }
    for (int i = (int)this->size_ - 2; i >= 0; i--) {
      merge(data[2 * i + 1], data[2 * i + 2], data[i]);
    }
  }

  void update(int k, ll val) {
    int idx = this->size_ - 1 + rev_idx[k];
    while (idx > 0) {
      data[idx].rmq->update(data.rev_indices[k], val);
      idx = (idx - 1) / 2;
    }
  }

  void merge(RangeTreeNode<T> &node1, RangeTreeNode<T> &node2, RangeTreeNode<T> &merged) {
    merged.low = std::min(node1.low, node2.low);
    merged.high = std::max(node1.high, node2.high);
    merged.assoc.resize(node1.assoc.size() + node2.assoc.size());
    merged.indices.resize(merged.assoc.size());
    merged.vals.resize(merged.assoc.size());

    node1.assoc.push_back(this->inf), node2.assoc.push_back(this->inf);
    for (size_t i = 0, l = 0, r = 0; i < merged.assoc.size(); i++) {
      if (node1.assoc[l] < node2.assoc[r] or
          (node1.assoc[l] == node2.assoc[r] and
           points[node1.indices[l]].x < points[node2.indices[r]].x)) {
        merged.assoc[i] = node1.assoc[l];
        merged.indices[i] = node1.indices[l];
        merged.vals[i] = node1.vals[l];
        l++;
      } else {
        merged.assoc[i] = node2.assoc[r];
        merged.indices[i] = node2.indices[r];
        merged.vals[i] = node2.vals[r];
        r++;
      }
      merged.rev_indices[merged.indices[i]] = i;
    }
    node1.assoc.pop_back(), node2.assoc.pop_back();
    merged.rmq = new SegmentTree<RangeMinQuery<ll>>(merged.vals);
  }

  void range_query(T x_low, T x_high, T y_low, T y_high, std::vector<size_t> &output, size_t idx = 0) const {
    if (idx >= 2 * size_ - 1 or x_high < data[idx].low or data[idx].high < x_low) {
      return;
    } else if (x_low <= data[idx].low and data[idx].high <= x_high) {
      size_t lb = std::lower_bound(data[idx].assoc.begin(), data[idx].assoc.end(), y_low) - data[idx].assoc.begin();
      size_t ub = std::lower_bound(data[idx].assoc.begin(), data[idx].assoc.end(), y_high + 1) - data[idx].assoc.begin();
      for (size_t i = lb; i < ub; i++) {
        output.emplace_back(data[idx].indices[i]);
      }
      return ;
    }
    range_query(x_low, x_high, y_low, y_high, output, 2 * idx + 1);
    range_query(x_low, x_high, y_low, y_high, output, 2 * idx + 2);
  }

  ll range_min_query(T x_low, T x_high, T y_low, T y_high, size_t idx = 0) const {
    if (idx >= 2 * size_ - 1 or x_high < data[idx].low or data[idx].high < x_low) {
      return 1e18;
    } else if (x_low <= data[idx].low and data[idx].high <= x_high) {
      size_t lb = std::lower_bound(data[idx].assoc.begin(), data[idx].assoc.end(), y_low) - data[idx].assoc.begin();
      size_t ub = std::lower_bound(data[idx].assoc.begin(), data[idx].assoc.end(), y_high + 1) - data[idx].assoc.begin();
      return data[idx].rmq->query(lb, ub);
    }
    return min(range_query(x_low, x_high, y_low, y_high, 2 * idx + 1),
               range_query(x_low, x_high, y_low, y_high, 2 * idx + 2));
  }
};

int main() {
  int N, S, T; cin >> N >> S >> T;
  std::vector<Point2D<int>> points;
  vector<ll> C;
  REP(i, N) {
    int x, y; ll c; cin >> x >> y >> c;
    points.emplace_back(Point2D<int>(x, y, 1e18, i));
    C.emplace_back(c);
  }
  RangeTree2D<int> rt2d;
  rt2d.build(points);
  sort(ALL(points));
  vector<ll> dp(N);
  for (auto p : points) {
    int x = p.x, y = p.y;
  }
  int Q; scanf("%d", &Q);
  REP(i, Q) {
    int sx, tx, sy, ty; scanf("%d %d %d %d", &sx, &tx, &sy, &ty);
    std::vector<size_t> output;
    rt2d.range_query(sx, tx, sy, ty, output);
    std::sort(output.begin(), output.end());
    for (size_t i : output) printf("%lu\n", i);
    printf("\n");
  }
  return 0;
}
