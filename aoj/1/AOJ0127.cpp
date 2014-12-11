//
//  AOJ0127.cpp
//  
//
//  Created by knuu on 2014/06/11.
//
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	char string[6][6],input[201];
	int i;
	for (i=0; i<26; i++) string[i/5][i%5]='a'+i;
	string[5][i++%5]='.',string[5][i++%5]='?';
	string[5][i++%5]='!',string[5][i++%5]=' ';
	while (scanf(" %s",input)!=EOF) {
		if (strlen(input)%2!=0) {
			cout<<"NA"<<endl;
			continue;
		}
		int i;
		for (i=0; i<strlen(input); i++) {
			if (i%2==0&&((input[i]-'0')<1||(input[i]-'0')>6)) {
				break;
			}
			if (i%2!=0&&((input[i]-'0')<1||(input[i]-'0')>5)) {
				break;
			}
		}
		if (i!=strlen(input)) {
			cout<<"NA"<<endl;
			continue;
		}
		
		for (int i=0; i<strlen(input); i+=2) {
			cout<<string[input[i]-1-'0'][input[i+1]-1-'0'];
		}
		cout<<endl;
	}
}
