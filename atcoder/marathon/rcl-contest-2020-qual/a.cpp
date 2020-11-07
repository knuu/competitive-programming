#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>
#include <random>

int N, W, K, V;
std::vector<int> colors, scores;
const int beam_size = 5;

using std::chrono::system_clock;

int score(std::vector<int> &ans) {
  std::vector<std::vector<int>> board(W, std::vector<int>());
  for (size_t i = 0; i < ans.size(); i++) {
    board[ans[i]].emplace_back(i);
  }

  int score = 0;
  std::vector<int> score_of_color(K);
  for (size_t row = 0; ; row++) {
    std::fill(score_of_color.begin(), score_of_color.end(), 0);
    for (int col = 0; col < W; col++) {
      if (board[col].size() <= row) return score;
      size_t idx = board[col][row];
      score_of_color[colors[idx]] += scores[idx];
    }
    score += *std::max_element(score_of_color.begin(), score_of_color.end());
  }
}

void input() {
  std::cin >> N >> W >> K >> V;
  colors.resize(N);
  scores.resize(N);
  for (int i = 0; i < N; i++) {
    std::cin >> colors[i] >> scores[i];
  }
}

void output(std::vector<int> &ans) {
  for (int col : ans) std::cout << col << '\n';
}

void solve() {
  system_clock::time_point start = system_clock::now();
  std::random_device rnd;
  std::mt19937 mt(rnd());

  std::uniform_int_distribution<> randN(0, N-1);

  /* 横積み */
  std::vector<int> ans(N);
  for (int i = 0; i < N; i++) {
    ans[i] = i % W;
  }
  int ans_score = score(ans);
  int eval_cnt = 0;


  while (true) {
    double diff = std::chrono::duration_cast<std::chrono::milliseconds>(
        system_clock::now() - start).count() / 1000.;
    if (diff > 1.99) break;
    ///*
    int i = randN(mt), j = randN(mt);
    if (ans[i] == ans[j]) continue;
    std::swap(ans[i], ans[j]);
    int cand_score = score(ans);
    if (cand_score > ans_score) {
      ans_score = cand_score;
    } else {
      std::swap(ans[i], ans[j]);
    }
    //*/
    /*
    int cand_max_score = ans_score, cand_i = -1, cand_j = -1;
    for (int i = 0; i < N; i++) {
      std::cerr << i << '\n';
      for (int j = i + 1; j < N; j++) {
        if (ans[i] == ans[j]) continue;
        std::swap(ans[i], ans[j]);
        int cand_score = score(ans);
        if (cand_score > cand_max_score) {
          cand_max_score = cand_score;
          cand_i = i, cand_j = j;
        }
        std::swap(ans[i], ans[j]);
      }
    }
    if (cand_i == -1) {
      break;
    } else {
      ans_score = cand_max_score;
      std::swap(ans[cand_i], ans[cand_j]);
    }
    */
    eval_cnt++;
  }
  std::cerr << ans_score << ' ' << eval_cnt << '\n';
  output(ans);

  /* 縦積み */
  /*
  std::vector<int> tate(N);
  for (int i = 0; i < N; i++) {
    tate[i] = i / (N / W);
  }

  int score_yoko = score(yoko), score_tate = score(tate);
  std::cerr << score(yoko) << ' ' << score(tate) << std::endl;
  if (score_yoko > score_tate) {
    output(yoko);
  } else {
    output(tate);
  }
  */
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(false);
  input();
  solve();

  return 0;
}