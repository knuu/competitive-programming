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

template<class T> istream& operator >> (istream& is, vector<T>& vec){for(T& val: vec) is >> val; return is;}
template<class T> istream& operator , (istream& is, T& val){ return is >> val;}
template<class T> ostream& operator << (ostream& os, vector<T>& vec){for(int i=0; i<(int)vec.size(); i++) os << vec[i] << (i==(int)vec.size()-1?"\n":" ");return os;}
template<class T> ostream& operator , (ostream& os, T& val){ return os << " " << val;}
template<class T> ostream& operator >> (ostream& os, T& val){ return os << " " << val;}

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

int main() {
  // Use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  return 0;
}
