//
//  AOJ0502.c
//  
//
//  Created by n_knuu on 2014/02/26.
//
//

#include <stdio.h>
int main(void) {
    int o,s,e,w,n,u,c,temp,i,sum;
    char inst[5];
    while(1){
    	scanf("%d\n",&c);
        if (c==0) break;
        o=1,s=2,e=3,w=4,n=5,u=6,sum=1;
    	for (i=0; i<c; i++) {
        	scanf("%s\n",inst);
        	if (inst[0]=='N') {
            	temp = o;
            	o=s;
            	s=u;
            	u=n;
            	n=temp;
            } else if (inst[0]=='E') {
                temp = o;
                o=w;
                w=u;
                u=e;
                e=temp;
            } else if (inst[0]=='W') {
                temp = o;
                o=e;
                e=u;
                u=w;
                w=temp;
            } else if (inst[0]=='S') {
                temp = o;
                o=n;
                n=u;
                u=s;
                s=temp;
            } else if (inst[0]=='R') {
                temp = n;
                n=w;
                w=s;
                s=e;
                e=temp;
            } else {
                temp = n;
                n=e;
                e=s;
                s=w;
                w=temp;
            }
            sum+=o;
        }
        printf("%d\n",sum);
    }
    return 0;
}