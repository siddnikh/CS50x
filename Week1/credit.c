#include<stdio.h>
#include <stdbool.h>
#include<cs50.h>

static int count(long n){
    int c = 0;
    while(n != 0){
        n /= 10;
        c++;
    }
    return c;
}

int main(void){
    int first_sum = 0; //sum of digits, second to last ones
    int second_sum = 0; //sum of the remaining digits
    long n = get_long("Enter the credit card number\n");

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
    if((second_sum + first_sum) % 10 == 0 && count(n3) > 10){
        valid = true;
    }

    while(n3 / 100 != 0) //extracting the first 2 digits to check the credit card type
    {
        n3 /= 10;
    }

    if(valid) {
        if(n3 == 34 || n3 == 37){
            printf("AMEX\n");
        }
        else if(n3 == 51 || n3 == 52 || n3 == 53 || n3 == 54 || n3 == 55){
            printf("MASTERCARD\n");
        }
        else if(n3 / 10 == 4){
            printf("VISA\n");
        }
        else{
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

}
