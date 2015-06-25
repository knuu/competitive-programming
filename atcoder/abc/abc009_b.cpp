//
//  ABC009-2.cpp
//  
//
//  Created by knuu on 2014/05/26.
//
//

#include <iostream>

using namespace std;

int main()
{
    int first,second,n;
    cin >>n;
    cin>>first>>second;
    if (first<second) {
        swap(first,second);
    }
    for (int i=0; i<n-2; i++) {
        int temp;
        cin>>temp;
        if (temp==first||temp==second) {
            continue;
        } else if (temp>first) {
            second=first;
            first=temp;
        } else if (temp>second) {
            second=temp;
        }
    }
    cout<<second<<endl;
    return 0;
}