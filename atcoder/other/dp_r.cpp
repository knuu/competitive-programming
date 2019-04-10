#include <bits/stdc++.h>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/multiprecision/cpp_int.hpp>
using mpi = boost::multiprecision::int128_t;
using namespace boost::numeric;
using imatrix = ublas::matrix<mpi>;

using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
//typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
//typedef tuple<int, int, int> T;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)
#define ALL(c) c.begin(), c.end()
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl
#define UNIQUE(c) sort(ALL(c)), c.erase(unique(ALL(c)), c.end())

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};
const ll mod = (int)1e9 + 7;


void modulo(imatrix &mat, mpi mod) {
  for (size_t i = 0; i < mat.size1(); i++) {
    for (size_t j = 0; j < mat.size2(); j++) {
      mat(i, j) %= mod;
    }
  }
}

int main() {
  // use scanf in CodeForces!

  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int N; ll K; cin >> N >> K;
  imatrix mat(N, N);
  REP(i, N) REP(j, N) cin >> mat(i, j);

  imatrix pow2 = mat, ans(N, N);
  REP(i, N) REP(j, N) ans(i, j) = (ll)(i == j);
  while (K) {
    if (K & 1LL) {
      ans = ublas::prod(ans, pow2);
      modulo(ans, mod);
    }
    pow2 = ublas::prod(pow2, pow2);
    modulo(pow2, mod);
    K >>= 1;
  }

  mpi count = 0;
  REP(i, N) REP(j, N) count = (count + ans(i, j)) % mod;
  cout << count << endl;
  return 0;
}
