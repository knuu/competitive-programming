//
//  AOJ0566.c
//  
//
//  Created by n_knuu on 2014/04/12.
//
//

#include <stdio.h>
int main(void) {
    int team[102][2]={{0}},a,b,c,d,num,i;
    scanf("%d",num);
    for (i=1; i<=num; i++) team[i][1]=i;
    for (i=1; i<=num*(num-1)/2; i++) {
        scanf("%d%d%d%d",&a,%b,&c,&d);
        if (c>d) {
            team[a][0]+=3;
        } else if (c<d) {
            team[b][0]+=3
        } else {
            team[a][0]++,team[b][0]++;
        }
    }
    
}