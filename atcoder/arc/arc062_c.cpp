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

inline ll encode(vector<int> &tile) {
  ll now = 0, base = 1000;
  for (int c : tile) {
    now += c;
    now *= base;
  }
  return now;
}

inline void rot(vector<int> &tile) {
  rotate(tile.begin(), tile.begin() + 1, tile.end());
}

inline void rm_tile(vector<int> &tile, map<ll, int> &colors) {
  REP(i, 4) {
    colors[encode(tile)]--;
    rot(tile);
  }
}

inline void add_tile(vector<int> &tile, map<ll, int> &colors) {
  REP(i, 4) {
    colors[encode(tile)]++;
    rot(tile);
  }
}

ll calc_tiles(vector<int> &upper, vector<int> &lower, map<ll, int> &colors) {
  ll ret = 1;
  vector<vector<int>> side_tiles = {{upper[1], lower[0], lower[3], upper[2]},
                                    {upper[3], upper[2], lower[3], lower[2]},
                                    {lower[1], upper[0], upper[3], lower[2]},
                                    {lower[1], lower[0], upper[1], upper[0]}};
  vector<vector<int>> used;
  for (vector<int> &tile : side_tiles) {
    ret *= max(colors[encode(tile)], 0);
    if (ret == 0) break;
    rm_tile(tile, colors);
    used.emplace_back(tile);
  }

  for (vector<int> &tile : used) add_tile(tile, colors);
  return ret;
}

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N; cin >> N;
  vector<vector<int>> tiles(N);
  map<ll, int> colors;
  REP(i, N) {
    int c0, c1, c2, c3; cin >> c0 >> c1 >> c2 >> c3;
    tiles[i] = {c0, c1, c2, c3};
    REP(j, 4) {
      colors[encode(tiles[i])]++;
      rot(tiles[i]);
    }
  }

  ll ans = 0;
  REP(up, N) {
    rm_tile(tiles[up], colors);
    FOR(low, up+1, N) {
      rm_tile(tiles[low], colors);
      REP(k, 4) {
        ans += calc_tiles(tiles[up], tiles[low], colors);
        rot(tiles[low]);
      }
      add_tile(tiles[low], colors);
    }
  }
  cout << ans << endl;

  return 0;
}
