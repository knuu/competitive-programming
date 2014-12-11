//
//  AOJ0118.cpp
//  
//
//  Created by knuu on 2014/05/24.
//
//

#include <iostream>

#define MAX_WH 100

using namespace std;

void solve();
void dfs(int x, int y);

int W,H,count;
char field[MAX_WH][MAX_WH+1];

int main()
{
    while (1) {
        cin>>H>>W;
        if (W==0&&H==0) break;
        for (int i=0; i<H; i++) cin>>field[i];
        solve();
    }
    return 0;
}

void solve()
{
    count=0;
    for (int i=0; i<H; i++) {
        for (int j=0; j<W; j++) {
            if (field[i][j]!='.') {
                dfs(i,j);
                count++;
            }
        }
    }
    cout<<count<<endl;
}

void dfs(int x, int y)
{
    char s=field[x][y];
    field[x][y]='.';
    
    if (x-1>=0&&field[x-1][y]==s) dfs(x-1,y);
    if (y-1>=0&&field[x][y-1]==s) dfs(x,y-1);
    if (x+1<H&&field[x+1][y]==s) dfs(x+1,y);
    if (y+1<W&&field[x][y+1]==s) dfs(x,y+1);
}
