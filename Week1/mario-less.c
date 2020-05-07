#include<stdio.h>
#include<cs50.h>

int main(void){

    int n=-1;

    while(n <=0 || n>8){
        n = get_int("Enter the number of rows you want\n") ;
    }
    for(int i = 1; i <= n; i++){

        for(int f = 0; f < n; f++){

            if(f < n - i){
                printf(" ");
            }
            else{
                printf("#");
            }
        }
        printf("\n");
    }
}
