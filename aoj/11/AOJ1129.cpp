//
//  AOJ1129.cpp
//  
//
//  Created by knuu on 2014/05/25.
//
//

#include <iostream>
#define MAX_R 50
#define MAX_N 50

using namespace std;
void solve();

int c[MAX_R],p[MAX_R],n,r;

int main()
{
    while (1) {
        cin>>n>>r;
        if (n==0&&r==0) break;
        for (int i=0; i<r; i++) cin>>p[i]>>c[i];
        solve();
    }
}

void solve()
{
    int card[MAX_N];
    for (int i=n-1; i>=0; i--) card[i]=n-i;
    for (int i=0; i<r; i++) {
        int cut[MAX_N];
        for (int j=0; j<c[i]; j++) cut[j]=card[p[i]+j-1];
        for (int j=p[i]-2; j>=0; j--) card[j+c[i]]=card[j];
        for (int j=0; j<c[i]; j++) card[j]=cut[j];
    }
    cout<<card[0]<<endl;
}
