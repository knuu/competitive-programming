struct SuffixArray {
  int N, k;
  string S;
  vector<int> sa, rank, tmp;
  vector<int> lpc, rank_lpc;
  SuffixArray(string S) : S(S) {
    N = S.size();
    sa.resize(N+1), rank.resize(N+1), tmp.resize(N+1);
    construct_sa();
  }

  bool compare_sa(int i, int j) {
    if (rank[i] != rank[j]) {
      return rank[i] < rank[j];
    } else {
      int ri = i + k <= N ? rank[i + k] : -1;
      int rj = j + k <= N ? rank[j + k] : -1;
      return ri < rj;
    }
  }

  void construct_sa() {
    for (int i = 0; i <= N; i++) {
      sa[i] = i;
      rank[i] = i < N ? S[i] : -1;
    }

    for (k = 1; k <= N; k *= 2) {
      sort(sa.begin(), sa.end(), [&] (const int & i, const int & j) { return compare_sa(i, j); });

      tmp[sa[0]] = 0;
      for (int i = 1; i <= N; i++) {
        tmp[sa[i]] = tmp[sa[i-1]] + (compare_sa(sa[i-1], sa[i]) ? 1 : 0);
      }
      for (int i = 0; i <= N; i++) rank[i] = tmp[i];
    }
  }

  bool contain(string T) {
    int left = 0, right = N;
    while (left - right > 1) {
      int mid = (left + right) / 2;
      (S.compare(sa[mid], T.length(), T) < 0 ? left : right) = mid;
    }
    return S.compare(sa[right], T.length(), T) == 0;
  }

  void construct_lpc() {
    lpc.resize(N), rank_lpc.resize(N+1);
    for (int i = 0; i <= N; i++) rank_lpc[sa[i]] = i;

    int h = 0;
    lpc[0] = 0;
    for (int i = 0; i < N; i++) {
      int j = sa[rank[i] - 1];

      if (h > 0) h--;
      for (; j + h < N and i + h < N; h++) {
        if (S[j + h] != S[i + h]) break;
      }

      lpc[rank[i] - 1] = h;
    }
  }
};
