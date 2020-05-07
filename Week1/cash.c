#include<stdio.h>
#include<math.h>
#include<cs50.h>

int main(void){
    float f = -1.0;
    while(f < 0){
        f = get_float("Enter a positive value");
    }

    int change = round(f * 100);

    const int QUARTER = 25;
    const int DIME = 10; 
    const int NICKEL = 5;
    const int PENNY = 1;

    int n_coins = 0;
    int sum = 0;

    while(sum != change){
        if(sum + QUARTER <= change){
            sum += QUARTER;
        }
        else if(sum + DIME <= change){
            sum += DIME;
        }
        else if(sum + NICKEL <= change){
            sum += NICKEL;
        }
        else if(sum + PENNY <= change){
            sum += PENNY;
        }
        n_coins++;
    }

    printf("%i", n_coins);

}
