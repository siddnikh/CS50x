#include<stdio.h>
#include <stdbool.h>

int main(void){
    int first_sum = 0; //sum of digits, second to last ones
    int second_sum = 0; //sum of the remaining digits
    long n = 4062901840;
    
    long n2 = n;
    long n3 = n;

    while(n2 != 0){ //finding the sum of the first set of numbers, second-to-last ones.

        int s = 2 * (int)((n2 % 100) / 10);
        n2 = n2 / 100;

        if(s/10 != 0)
        {
            while(s != 0){
                first_sum += s % 10;
                s /= 10;
            }
        }
        else
        {
            first_sum += s;
        }
    } 
//finding the sum of the remaining number
    while(n != 0){ 

        second_sum += n%10;
        n /= 100;
        
    }

    bool valid = false;
    if((second_sum + first_sum) % 10 == 0){
        valid = true;
    }

    while(n3 / 100 != 0) //extracting the first 2 digits to check the credit card type
    {
        n3 /= 10;
    }

    if(valid) {
        if(n3 == 34 || n3 == 37){
            printf("AMEX");
        }
        else if(n3 == 51 || n3 == 52 || n3 == 53 || n3 == 54 || n3 == 55){
            printf("MASTERCARD");
        }
        else if(n3 / 10 == 4){
            printf("VISA");
        }
        else{
            printf("INVALID");
        }
    }
    else
    {
        printf("INVALID");
    }

}
