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

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};


class Solution {
public:
  int strStr(string haystack, string needle) {
    if (needle.size() == 0) {
      return 0;
    } else if (haystack.size() == 0) {
      return -1;
    }
    haystack += '\0';
    needle += '\0';
    for (int i = 0; ; i++) {
      for (int j = 0; ; j++) {
        if (needle[i] == '\0') return i;
        if (haystack[i + j] == '\0') return -1;
        if (haystack[i + j] != needle[j]) break;
      }
    }
  }
};

int main() {
  // use scanf in CodeForces!
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  return 0;
}
