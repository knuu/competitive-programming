//
//  AOJ0077.cpp
//  
//
//  Created by knuu on 2014/06/18.
//
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	char input[101];
	while (scanf(" %s",input)!=EOF) {
		for (int i=0; i<strlen(input); i++) {
			if (input[i]=='@') {
				for (int j=0; j<input[i+1]-'0'; j++) {
					cout<<input[i+2];
				}
				i+=2;
			} else {
				cout<<input[i];
			}
		}
		cout<<endl;
	}
}
