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

int main() {
  // Use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int T; cin >> T;
  REP(_, T) {
    int N; cin >> N;
    vector<int> line(N, 0);
    REP(i, N) cin >> line[i];
    if (N % 2 == 1) line.push_back(0), N++;
    sort(ALL(line));
    int nim = 0;
    for (int i = 0; i < N; i += 2) nim ^= line[i+1] - line[i] - 1;
    cout << (nim ? "Georgia will win" : "Bob will win") << endl;
  }

  return 0;
}
