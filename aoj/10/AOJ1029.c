//
//  AOJ1029.c
//  
//
//  Created by n_knuu on 2014/03/12.
//
//

#include <stdio.h>
int main(void) {
    int ltime[10000],rtime[10000],diff,temp,before,left,right,i,j;
    while (1) {
        scanf("%d %d",&left,&right);
        if (left==0&&right==0) break;
        diff=0,before=0;
        for (i=0; i<left; i++) scanf("%d",&ltime[i]);
        for (i=0; i<right; i++) scanf("%d",&rtime[i]);
        for (i=0,j=0; i+j<left+right; ) {
            if (i<left&&j<right) {
                if (ltime[i]<rtime[j]) {
                    temp=ltime[i]-before;
                    if (temp>diff) diff=temp;
                    before = ltime[i];
                    i++;
                } else {
                    temp=rtime[j]-before;
                    if (temp>diff) diff=temp;
                    before = rtime[j];
                    j++;
                }
            } else if (i==left) {
                temp=rtime[j]-before;
                if (temp>diff) diff=temp;
                before = rtime[j];
                j++;
            } else {
                temp=ltime[i]-before;
                if (temp>diff) diff=temp;
                before = ltime[i];
                i++;
            }
        }
        printf("%d\n",diff);
    }
    return 0;
}