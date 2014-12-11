//
//  AOJ0095.c
//  
//
//  Created by n_knuu on 2014/02/23.
//
//

#include <stdio.h>
int main(void) {
    int n,max[2]={0},num,fish,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&num,&fish);
        if(i==0||fish>max[1]||(fish==max[1]&&num<max[0])) {
            max[0]=num;
            max[1]=fish;
        }
    }
    printf("%d %d\n",max[0],max[1]);
    return 0;
}