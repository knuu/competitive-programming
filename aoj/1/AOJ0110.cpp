//
//  AOJ0110.cpp
//  
//
//  Created by knuu on 2014/05/25.
//
//

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

void solve();
char calc[127];

int main()
{
    while (cin>>calc) {
        solve();
    }
}

void solve()
{
    for (int i=0; i<10; i++) {
        char t[127];
        strcpy(t,calc);
        long long a,b,c;
        for (int j=0; j<strlen(t); j++) {
            if (t[j]=='X') t[j]='0'+i;
        }
        sscanf(t,"%lld+%lld=%lld",&a,&b,&c);
        if (i!=0&&a+b==c) {
            cout<<i<<endl;
            return ;
        } else if (a+b==c) {
            char s[127];
            sprintf(s,"%lld+%lld=%lld",a,b,c);
            if (strlen(calc)==strlen(s)) {
                cout<<i<<endl;
                return ;
            }
        }
    }
    cout<<"NA"<<endl;
}
