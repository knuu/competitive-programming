//
//  AOJ2006.c.c
//  
//
//  Created by knuu on 2014/05/13.
//
//

#include <stdio.h>
#include <string.h>
int main(void) {
    int flag,i,j,num,count,maxcount[10]={0,4,2,2,2,2,2,3,2,3};
    char key[10][6]={"",".,!? ","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"},input[1025];
    scanf("%d",&num);
    for (j=0; j<num; j++) {
        scanf(" %s",input);
        flag=0,count=0;
        for (i=0; i<strlen(input); i++) {
            if (flag==0&&input[i]=='0') {
                continue;
            } else if (flag==1&&input[i]=='0') {
            	if (count==0) {
            		count=maxcount[input[i-1]-'0'];
            	} else {
            		count--;
            	}
                printf("%c",key[input[i-1]-'0'][count]);
                count=0;
                flag=0;
            } else {
                flag=1;
                if (count==maxcount[input[i]-'0']) {
                    count=0;
                } else {
                    count++;
                }
            }
        }
        printf("\n");
    }
    return 0;
}