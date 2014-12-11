//
//  ABC012-B.cpp
//  
//
//  Created by knuu on 2014/07/12.
//
//

#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int N;
	cin>>N;
	int h,m,s;
	h = N/3600, N%=3600;
	m = N/60, N%=60;
	s = N;
	printf("%02d:%02d:%02d\n",h,m,s);
}
