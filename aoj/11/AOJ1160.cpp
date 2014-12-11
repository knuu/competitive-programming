//
//  AOJ1160.cpp
//
//
//  Created by knuu on 2014/05/24.
//
//

#include <iostream>

#define MAX_NM 50

using namespace std;

void solve();
void dfs(int x, int y);

int w,h;
int field[MAX_NM][MAX_NM];

int main()
{
    while (1) {
        cin>>w>>h;
        if (w==0&&h==0) break;
        for (int i=0; i<h; i++) {
            for (int j=0; j<w; j++) {
                cin>>field[i][j];
            }
        }
        solve();
    }
    return 0;
}

void solve()
{
    int count=0;
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (field[i][j]==1) {
                dfs(i,j);
                count++;
            }
        }
    }
    cout<<count<<endl;
}

void dfs(int x, int y)
{
    field[x][y]=0;
    
    for (int dx=-1; dx<=1; dx++) {
        for (int dy=-1; dy<=1; dy++) {
            int nx=x+dx, ny=y+dy;
            
            if (nx>=0&&nx<h&&ny>=0&&ny<w&&field[nx][ny]==1) {
                dfs(nx,ny);
            }
        }
    }
}
