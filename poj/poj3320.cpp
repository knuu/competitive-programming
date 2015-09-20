#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)

#define INF (int)1e5

int a[1000010];
map<int, int> read;

int main() {
  int P;
  set<int> book;
  scanf("%d", &P);
  REP(i, P) {
    scanf("%d", a+i);
    book.insert(a[i]);
  }

  int kind = book.size(), ans = P;
  int left = 0, right = 0, now_kind = 0;
  while (right < P) {
    while (right < P && now_kind < kind) {
      if (read[a[right]] == 0) now_kind++;
      read[a[right]]++;
      right++;
    }
    if (now_kind < kind) break;
    while (left < right && now_kind == kind) {
      if (read[a[left]] == 1) now_kind--;
      read[a[left]]--;
      left++;
    }
    ans = min(ans, right - left + 1);
  }
  cout << ans << endl;
  return 0;
}
