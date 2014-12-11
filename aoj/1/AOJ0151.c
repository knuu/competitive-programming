//
//  AOJ0151.c
//  
//
//  Created by n_knuu on 2014/03/14.
//
//

#include <stdio.h>
int main(void) {
    int grid[255][255],num,i,j,count,max,flag;
    int integer;
    while (1) {
        scanf("%d\n",&num);
        if (num==0) break;
        max=0;
        for (i=0; i<num; i++) {
            for (j=0; j<num; j++) {
            	scanf("%c ",&integer);
            	grid[i][j]=integer-'0';
            }
        }
        for (i=0; i<num; i++) {
            flag=0,count=0;
            for (j=0; j<num; j++) {
                if (flag==0&&grid[i][j]==1) {
                    count=1,flag=1;
                } else if (flag==1&&grid[i][j]==1) {
                    count++;
                } else if (flag==1&&grid[i][j]==0) {
                    if (count>max) max=count;
                    flag=0,count=0;
                }
            }
            if (count>max) max=count;
            if (max==num) break;
            
            flag=0,count=0;
            for (j=0; j<num; j++) {
                if (flag==0&&grid[j][i]==1) {
                    count=1,flag=1;
                } else if (flag==1&&grid[j][i]==1) {
                    count++;
                } else if (flag==1&&grid[j][i]==0) {
                    if (count>max) max=count;
                    flag=0,count=0;
                }
            }
            if (count>max) max=count;
            if (max==num) break;
        }
        if (max==num) {
            printf("%d\n",max);
            continue;
        }
        
        for (i=0; i<=num-1; i++) {
            flag=0,count=0;
            for (j=0; j<=num-1-i; j++) {
                if (flag==0&&grid[num-1-i-j][j]==1) {
                    count=1,flag=1;
                } else if (flag==1&&grid[num-1-i-j][j]==1) {
                    count++;
                } else if (flag==1&&grid[num-1-i-j][j]==0) {
                    if (count>max) max=count;
                    flag=0,count=0;
                }
            }
            if (count>max) max=count;
            if (max==num-i) break;
            
            flag=0,count=0;
            if (i) {
                for (j=num-1; j>=i; j--) {
                    if (flag==0&&grid[j][num-1+i-j]==1) {
                        count=1,flag=1;
                    } else if (flag==1&&grid[j][num-1+i-j]==1) {
                        count++;
                    } else if (flag==1&&grid[j][num-1+i-j]==0) {
                        if (count>max) max=count;
                        flag=0,count=0;
                    }
                }
                if (count>max) max=count;
            }
            if (max==num-i) break;
            
            flag=0,count=0;
            for (j=0; j<=num-1-i; j++) {
                if (flag==0&&grid[j+i][j]==1) {
                    count=1,flag=1;
                } else if (flag==1&&grid[j+i][j]==1) {
                    count++;
                } else if (flag==1&&grid[j+i][j]==0) {
                    if (count>max) max=count;
                    flag=0,count=0;
                }
            }
            if (count>max) max=count;
            if (max==num-i) break;
            
            flag=0,count=0;
            if (i) {
                for (j=0; j<=num-1-i; j++) {
                    if (flag==0&&grid[j][j+i]==1) {
                        count=1,flag=1;
                    } else if (flag==1&&grid[j][j+i]==1) {
                        count++;
                    } else if (flag==1&&grid[j][j+i]==0) {
                        if (count>max) max=count;
                        flag=0,count=0;
                    }
                }
                if (count>max) max=count;
            }
            if (max==num-i) break;
        }
        printf("%d\n",max);
    }
    return 0;
}