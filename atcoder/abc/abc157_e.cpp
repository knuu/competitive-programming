#include <algorithm>
#include <cassert>
#include <iostream>
#include <limits>
#include <vector>

template <class Monoid>
struct SegmentTree {
  using T = typename Monoid::type;
  int N_, N;
  std::vector<T> dat;

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
      dat[key] =
          Monoid::merge(dat[2 * key + 1], dat[2 * key + 2]);  // rewrite here
    }
  }

  inline const T &operator[](const int k) const { return dat.at(N - 1 + k); }
  inline T &operator[](const int k) { return dat.at(N - 1 + k); }

  T query(int low, int high) const {
    T left_ret = Monoid::identity(), right_ret = Monoid::identity();
    for (low += N, high += N; low < high; low >>= 1, high >>= 1) {
      if (low & 1) {
        left_ret = Monoid::merge(left_ret, dat[low - 1]);
        low++;
      }
      if (high & 1) {
        high--;
        right_ret = Monoid::merge(dat[high - 1], right_ret);
      }
    }
    return Monoid::merge(left_ret, right_ret);
  }
};

template <typename T>
struct RangeSumQuery {
  using type = T;
  static type identity() { return T(0); }
  static type merge(const type &l, const type &r) { return l + r; }
};

template <typename T>
struct RangeMinQuery {
  using type = T;
  static type identity() { return std::numeric_limits<T>::max(); }
  static type merge(const type &l, const type &r) { return std::min(l, r); }
};

template <typename T>
struct RangeMaxQuery {
  using type = T;
  static type identity() { return T(0); }
  static type merge(const type &l, const type &r) { return std::max(l, r); }
};

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);

  int N; std::string S; int Q; std::cin >> N >> S >> Q;
  std::vector<SegmentTree<RangeMaxQuery<short>>> segts(26, SegmentTree<RangeMaxQuery<short>>(N));
  for (int i = 0; i < N; i++) {
    int s = S[i] - 'a';
    segts[s].update(i, 1);
  }

  for (int i = 0; i < Q; i++) {
    int t; std::cin >> t;
    if (t == 1) {
      int idx; char c; std::cin >> idx >> c;
      segts[S[idx-1]-'a'].update(idx-1, 0);
      segts[c-'a'].update(idx-1, 1);
      S[idx-1] = c;
    } else {
      int l, r; std::cin >> l >> r;
      int ans = 0;
      for (int j = 0; j < 26; j++) {
        ans += segts[j].query(l-1, r);
      }
      std::cout << ans << '\n';
    }
  }


  return 0;
}