#include<stdio.h>
#include<cs50.h>

int main(void){
    char c = '#';
    int n=-1; 
    while(n<0 && n>8){
        n = get_int("Enter the number of rows you want\n") + 1;
    }
    for(int i = 0; i < n; i++){

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
