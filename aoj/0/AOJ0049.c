//
//  AOJ0049.c
//  
//
//  Created by n_knuu on 2014/02/25.
//
//

#include <stdio.h>
int main(void) {
    int num,count[4]={0},i;
    char blood[2];
    while(scanf("%d,%s",&num,blood)!=EOF) {
        if (blood[0]=='A'&&blood[1]=='B') {
        	count[2]++;
        } else if (blood[0]=='A') {
        	count[0]++;
        } else if (blood[0]=='B') {
        	count[1]++;
        } else if (blood[0]=='O') {
        	count[3]++;
        }
    }
    for(i=0;i<4;i++) printf("%d\n",count[i]);
    return 0;
}