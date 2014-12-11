//
//  AOJ10031.cpp
//  
//
//  Created by knuu on 2014/05/24.
//
//

#include <iostream>
#include <algorithm>

#define MAX_N 100000
#define MAX_Q 50000

using namespace std;

int main()
{
    int n,q,num[MAX_N],ques[MAX_Q];
    cin>>n;
    for (int i=0; i<n; i++) cin>>num[i];
    cin>>q;
    for (int i=0; i<q; i++) cin>>ques[i];
    sort(num,num+n);
    int count=0;
    for (int i=0; i<q; i++) {
        if (binary_search(num,num+n,ques[i])) {
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}
