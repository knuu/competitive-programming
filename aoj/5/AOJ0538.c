//
//  AOJ0538.c
//  
//
//  Created by n_knuu on 2014/03/08.
//
//

#include <stdio.h>
int main(void) {
    int num,len,i,j,count,flag;
    char p[1000000];
    while (1) {
        scanf("%d\n",&num);
        if (num==0) break;
        count=0,flag=0;
        scanf("%d\n%s",&len,p);
        for (i=0; i<=len-(num*2+1); i++) {
            if (p[i]=='I') {
                if (flag==0) {
                    for (j=1; j<num*2+1; j++) {
                        if ((j%2==0&&p[i+j]!='I')||(j%2==1&&p[i+j]!='O')) {
                        	i+=j-1;
                            flag=0;
                            break;
                        }
                        if (j==num*2) {
                            count++;
                            i++;
                            flag=1;
                        }
                    }
                } else {
                    if (p[i+num*2-1]=='O'&&p[i+num*2]=='I') {
                        count++;
                        i++;
                    } else {
                        i+=num*2-2;
                        flag=0;
                    }
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}