//
//  AOJ0063.cpp
//  
//
//  Created by knuu on 2014/06/18.
//
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char input[101];

int main()
{
	int ans=0;
	while (scanf(" %s",input)!=EOF) {
		bool flag=true;
		for (int i=0; i<strlen(input)/2; i++) {
			if (input[i]!=input[strlen(input)-i-1]) flag = false;
		}
		if (flag) ans++;
	}
	cout<<ans<<endl;
}
