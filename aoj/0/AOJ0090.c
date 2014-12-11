//
//  AOJ0090.c
//
//
//  Created by n_knuu on 2014/02/23.
//
//

#include <stdio.h>
int main(void){
    int n,q,a,v,i,j,max;
    scanf("%d %d",&n,&q);
    int fish[n],ans[q][2];
    for(i=0;i<n;i++) fish[i]=0;
    for(i=0;i<q;i++){
        scanf("%d %d",&a,&v);
        fish[a-1]+=v;
        if(i==0) {
            max=a-1;
        } else if(v>0){
            if (fish[a-1]>fish[max]||(fish[a-1]==fish[max]&&a-1<max)){
                max = a-1;
            }
        } else if (a-1==max){
            for(j=0;j<n;j++) {
                if(fish[j]>fish[max]||(fish[j]==fish[max]&&j<max)){
                    max=j;
                }
            }
        }
        ans[i][0] = max + 1;
        ans[i][1] = fish[max];
    }
    for(i=0;i<q;i++) printf("%d %d\n",ans[i][0],ans[i][1]);
    return 0;
}