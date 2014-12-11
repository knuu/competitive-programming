//
//  ARC20-1.c
//  
//
//  Created by n_knuu on 2014/03/29.
//
//

#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int ant,bug;
    scanf("%d %d",&ant,&bug);
    if (abs(ant)<abs(bug)) {
    	printf("Ant\n");
    } else if (abs(ant)>abs(bug)) {
    	printf("Bug\n");
    } else {
    	printf("Draw\n");
    }
    return 0;
}
