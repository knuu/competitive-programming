#include <iostream>
#include <algorithm>
#define INF 1000000
#define MAX_V 1000

using namespace std;

int d[MAX_V][MAX_V]; // d[u][v]は辺e=(u,v)のコスト(存在しない場合はINF,但しd[i][i]=0)
int V,E; // 頂点数,辺数

int new_e[410][3];
int k;

void solve(int s);
void warshall_floyd();

int main()
{
  cin>>V>>E;
  for (int i=0; i<V; i++) {
    fill(d[i], d[i]+V, INF);
    d[i][i]=0;
  }
  for (int i=0; i<E; i++) {
    int f,t,c;
    cin>>f>>t>>c;
    d[f-1][t-1]=c, d[t-1][f-1]=c;
  }
  cin>>k;
  for (int i=0; i<k; i++) {
    int f,t,c;
    cin>>f>>t>>c;
    new_e[i][0]=f-1, new_e[i][1]=t-1, new_e[i][2]=c;
  }
  solve(0);
}

void solve(int s)
{
  warshall_floyd();
  long long ans = 0;
  for (int i=0; i<V; i++) {
    for (int j=i+1; j<V; j++) {
      ans += d[i][j];
    }
  }
  for (int l=0; l<k; l++) {
    int x = new_e[l][0], y = new_e[l][1], z = new_e[l][2];
    for (int i=0; i<V; i++) {
      for (int j=0; j<V; j++) {
	if (i<j) ans -= d[i][j];
	d[i][j] = min(min(d[i][j], d[i][x] + z + d[y][j]),
		      d[i][y] + z + d[x][j]);
	if (i<j) ans += d[i][j];
      }
    }
    cout<<ans<<endl;
  }	  
}

void warshall_floyd()
{
  for (int k=0; k<V; k++) {
    for (int i=0; i<V; i++) {
      for (int j=0; j<V; j++) {
	d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
      }
    }
  }
}
