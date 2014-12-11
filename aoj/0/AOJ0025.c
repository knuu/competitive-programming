//
//  AOJ0025.c
//  
//
//  Created by n_knuu on 2014/02/22.
//
//

#include <stdio.h>
int main(void){
    int count=0,a[4],b[4],ans[100][2],hit,blow,i,j;
    while(scanf("%d %d %d %d",&a[0],&a[1],&a[2],&a[3])!=-1) {
        scanf("%d %d %d %d",&b[0],&b[1],&b[2],&b[3]);
        hit=0,blow=0;
        for(i=0;i<4;i++) {
            if(a[i]==b[i]) hit++;
        }
        ans[count][0]=hit;
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                if (b[i]==a[j]) blow++;
            }
        }
        ans[count][1]=blow-hit;
        count++;
    }
    for(i=0;i<count;i++) printf("%d %d\n",ans[i][0],ans[i][1]);
    return 0;
}