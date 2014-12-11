//
//  AOJ0005.c
//
//
//  Created by n_knuu on 2014/02/23.
//
//

#include <stdio.h>
int main(void){
    long int a,b,t1,t2,gcd[100],lcm[100],i=0,j;
    while(scanf("%d %d",&a,&b)!=EOF){
    	t1=a;
    	t2=b;
        while(a!=0&&b!=0){
            if(a>b){
                a-=b;
            } else {
                b-=a;
            }
        }
        if(a==0) {
            gcd[i]=b;
        } else{
            gcd[i]=a;
        }
        lcm[i]=t1*t2/gcd[i];
        i++;
    }
    for(j=0;j<i;j++) printf("%d %d\n",gcd[j],lcm[j]);
    return 0;
}