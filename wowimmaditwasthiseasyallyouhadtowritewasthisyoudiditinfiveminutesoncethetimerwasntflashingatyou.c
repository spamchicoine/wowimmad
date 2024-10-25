/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int get_ops();

int main()
{
    int n = 9;
    int *items = malloc(n * sizeof(int));
    
    for(int i=0; i<n; i++){
        *(items+i) = (rand()+1)%10;
    }
    
    for(int i=0; i<n; i++){
        printf("%d ",*(items+i));
    }
    
    int ops = get_ops(n, items);
    
    printf("ops: \n%d",ops);
    
    free(items);
}

int get_ops(int n, int *items){
    
    int ops1 = 0;
    int ops2 = 0;
    
    int citems[n];
    
    for(int i=0; i<n; i++){
        *(citems+i) = *(items+i);
    }
    
    for(int i=1; i<n-1; i++){
        if(i%2 == 0){
            while(*(items+i)%2 != 0){
                *(items+i) /= 2;
                ops1++;
            }
            while(*(items+i+1)%2 != 1){
                *(items+i+1) /= 2;
                ops1++;
            }
            while(*(citems+i)%2 != 1){
                *(citems+i) /= 2;
                ops2++;
            }
            while(*(citems+i+1)%2 != 0){
                *(citems+i+1) /= 2;
                ops2++;
            }
        }
    }
    
    if(ops1 <= ops2){
        return ops1;
    }
    return ops2;
}