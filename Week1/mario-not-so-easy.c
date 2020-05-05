#include<stdio.h>
#include<cs50.h>

int main(void){

    int n = -1;
    while(n > 0){
        get_int("Enter the number of rows you want\n");
    }
    
    for(int i = 1; i <= n; i++){
    
        for(int j = 0; j<=n+1+i; j++){
        
            if(j<=n-i || j == n+1){
                printf(" ");
            }
            
            else{
                printf("#");
            }
            
        }
        printf("\n");
    }
}
