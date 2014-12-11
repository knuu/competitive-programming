//
//  AOJ1165.c
//  
//
//  Created by n_knuu on 2014/03/22.
//
//

#include <stdio.h>
int main(void) {
    int num,product[200][2],i,n,d,X,x,Y,y;
    while (1) {
        scanf("%d",&num);
        if (num==0) break;
        product[0][0]=0,product[0][1]=0,X=0,x=0,Y=0,y=0;
        for (i=1; i<=num-1; i++) {
            scanf("%d %d",&n,&d);
            switch (d) {
                case 0:
                    product[i][0]=product[n][0]-1;
                    product[i][1]=product[n][1];
                    break;
                    
                case 1:
                    product[i][0]=product[n][0];
                    product[i][1]=product[n][1]-1;
                    break;
                    
                case 2:
                    product[i][0]=product[n][0]+1;
                    product[i][1]=product[n][1];
                    break;
                    
                case 3:
                    product[i][0]=product[n][0];
                    product[i][1]=product[n][1]+1;
                    break;
            }
            if (product[i][0]>X) X=product[i][0];
            if (product[i][1]>Y) Y=product[i][1];
            if (product[i][0]<x) x=product[i][0];
            if (product[i][1]<y) y=product[i][1];
        }
        printf("%d %d\n",X-x+1,Y-y+1);
    }
    return 0;
}