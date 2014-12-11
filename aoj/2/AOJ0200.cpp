//
//  AOJ0200.cpp
//  
//
//  Created by knuu on 2014/06/24.
//
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

#define MAX_V 100
#define INF 10000000

using namespace std;

typedef pair<int, int> P;

struct edge {
	int to, info;
	edge(int _to, int _info) { to = _to, info = _info; };
};

vector<edge> Gc[MAX_V];
vector<edge> Gt[MAX_V];
int V, E;
int c[MAX_V];
int t[MAX_V];
int cm[MAX_V][MAX_V];
int tm[MAX_V][MAX_V];

void solve();
void dijkstra(int s, int g, int r);

int main()
{
	while (cin>>E>>V, E != 0 && V != 0) {
		for (int i = 0; i < V; i++) {
			fill(cm[i], cm[i] + V, INF);
			fill(tm[i], tm[i] + V, INF);
			cm[i][i] = 0, tm[i][i] = 0;
			Gc[i].clear(), Gt[i].clear();
		}
		for (int i = 0; i < E; i++) {
			int fr, to, co, ti;
			cin>>fr>>to>>co>>ti;
			Gc[fr - 1].push_back(edge(to - 1, co));
			Gc[to - 1].push_back(edge(fr - 1, co));
			Gt[fr - 1].push_back(edge(to - 1, ti));
			Gt[to - 1].push_back(edge(fr - 1, ti));
		}
		solve();
	}
}

void solve()
{
	int k,p,q,r;
	cin>>k;
	for (int i = 0; i < k; i++) {
		cin>>p>>q>>r;
		if (r == 0 && (cm[p-1][q-1] != INF || cm[q-1][p-1] != INF)) {
			cout<<min(cm[p-1][q-1], cm[q-1][p-1])<<endl;
		} else if (r == 1 && (tm[p-1][q-1] != INF || tm[q-1][p-1] != INF)) {
			cout<<min(tm[p-1][q-1], tm[q-1][p-1])<<endl;
		} else {
			dijkstra(p - 1, q - 1, r);
		}
	}
}

void dijkstra(int s, int g, int r)
{
	priority_queue<P, vector<P>, greater<P> > que;
	switch (r) {
			case 0:
			que.push(P(0,s));
			fill(c, c + V, INF);
			c[s] = 0;
			while (!que.empty()) {
				P p = que.top();
				que.pop();
				int v = p.second;
	
				if (c[v] < p.first) continue;
				for (int i = 0; i < Gc[v].size(); i++) {
					edge e = Gc[v][i];
					if (c[e.to] > c[v] + e.info) {
						c[e.to] = c[v] + e.info;
						que.push(P(c[e.to], e.to));
					}
				}
			}
			
			for (int i = 0; i < V; i++) {
				cm[s][i] = c[i];
			}
			cout<<c[g]<<endl;
			
			break;
			
			case 1:
			que.push(P(0,s));
			fill(t, t + V, INF);
			t[s] = 0;
			while (!que.empty()) {
				P p = que.top();
				que.pop();
				int v = p.second;
				
				if (t[v] < p.first) continue;
				for (int i = 0; i < Gt[v].size(); i++) {
					edge e = Gt[v][i];
					if (t[e.to] > t[v] + e.info) {
						t[e.to] = t[v] + e.info;
						que.push(P(t[e.to], e.to));
					}
				}
			}
			
			for (int i = 0; i < V; i++) {
				tm[s][i] = t[i];
			}
			
			cout<<t[g]<<endl;
			
			break;
	}
}



