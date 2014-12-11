//
//  AOJ0571.cpp
//  
//
//  Created by knuu on 2014/06/11.
//
//

#include <iostream>
#include <cstring>

#define max(x,y) (x)>(y) ? (x) : (y)

using namespace std;

int main()
{
	int cj,co,ci,level=0;
	char input[1000001];
	cin>>input;
	for (int i=0; i<strlen(input); i++) {
		if (input[i]=='J') {
			cj=1,i++;
			while (input[i]=='J') cj++,i++;
			if (input[i]!='O') {
				i--;
				continue;
			} else {
				co=1,i++;
				while (input[i]=='O') co++,i++;
			}
			if (input[i]!='I') {
				i--;
				continue;
			} else {
				ci=1,i++;
				while (input[i]=='I') ci++,i++;
			}
			if (cj>=co&&co<=ci) level=max(level,co);
			i--;
		}
	}
	cout<<level<<endl;
}
