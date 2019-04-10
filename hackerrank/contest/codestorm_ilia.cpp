#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> Vi;
#define FOR(i,s,x) for(int i=s;i<(int)(x);i++)
#define REP(i,x) FOR(i,0,x)
#define ALL(c) c.begin(), c.end()
#define DUMP( x ) cerr << #x << " = " << ( x ) << endl

int len_count[10010];
ll A[5010];

int main(){
    int N;
    cin >> N;
    for(int A_i = 0; A_i < N; A_i++){
       cin >> A[A_i];
       len_count[(int)A[A_i]]++;
    }
    REP(i, 10001) len_count[i+1] += len_count[i];
    //REP(i, 16) cout << len_count[i] << (i == 15 ? '\n' : ' ');
    
    int acute = 0, right = 0, obtuse = 0;
    for (int a = N-1; a > 1; a--) {
      for (int b = a-1; b > 0; b--) {
	int max_c = len_count[(int)(A[a] - A[b])];
	// cout << (int)sqrt(A[a]*A[a] - A[b]*A[b]) << endl;
	//int c = (int)sqrt(A[a]*A[a] - A[b]*A[b]);
	int d_a = lower_bound(A, A+N, sqrt(A[a]*A[a] - A[b]*A[b])) - A;
			
	//cout << A[a] << ',' << A[b] << ':' << A[max_c] << ' ' << A[d_a] << endl;
	//if (max_c > d_a || d_a >= b) continue;
	if (d_a > b) {
	  obtuse += max(0, b - max_c);
	} else if (A[a]*A[a] == A[b]*A[b] + A[d_a] * A[d_a]) {
	  //cout << "right" << endl;
	  right++;
	  obtuse += max(d_a - max_c, 0);
	  acute += max(0, b - d_a - 1);
	} else {
	  obtuse += max(d_a - max_c, 0);
	  acute += max(0, b - d_a);
	}
      }
    }
    cout << acute << ' ' << right << ' ' << obtuse << endl;      
    return 0;
}
