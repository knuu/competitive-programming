//
//  ABC012-D.cpp
//  
//
//  Created by knuu on 2014/07/12.
//
//

#include <iostream>
#include <algorithm>
#define INF 300000
#define MAX_V 1000

using namespace std;

int d[MAX_V][MAX_V]; // d[u][v]は辺e=(u,v)のコスト(存在しない場合はINF,但しd[i][i]=0)
int V,E; // 頂点数,辺数

void solve();
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
	solve();
}

void solve()
{
	warshall_floyd();
	
	int ans = INF;
	for (int i=0; i<V; i++) {
		int m = 0;
		for (int j=0; j<V; j++) {
			m = max(m,d[i][j]);
		}
		ans = min(ans, m);
	}
	cout<<m<<endl;
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
