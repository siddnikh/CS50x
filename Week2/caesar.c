#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<ctype.h>

static char new_char(char ch, int k){
    bool lowercase = false;
    if((int) ch <= 90){
        lowercase = true;
    }

    if(lowercase){
        if((int) ch + k > 90){
            return (char)(k - (90 - (int) ch) + 64);
        }

        else{
            return (char)((int)ch + k);
        }
    }

    else
    {
        if((int)ch + k > 122){
            return (char)((((int)ch + k - 97) % 26) + 97);
        }

        else{
            return (char)((int)ch + k);
        }

    }

}

int main(int argc, string argv[]){

    string s;
    bool valid = false;

    if(argc == 2){
        valid = true;
    }

    if(valid){
        string n = argv[1]; //obtaining the key ONLY if it IS there
        for(int i = 0; i < strlen(n); i++){

            if((int)n[i] < 48 || (int)n[i] > 57){
                valid = false;
                break;
            }
            else{
                valid = true;
            }
        }
    }

    if(!valid){
        printf("Usage: ./caesar key");
        return 1;
    }

    int key = atoi(argv[1]);

    s = get_string("plaintext: \n");
    printf("ciphertext: ");
    char e;

    for(int i = 0; i < strlen(s); i++){
        if((int) s[i] >= 65 && (int) s[i] <= 90){
            e = (new_char(s[i], key));
        }
        else if((int) s[i] >= 97 && (int) s[i] <= 122){
            e = (new_char(s[i], key));
        }
        else{
            e = (s[i]);
        }
        printf("%c",e);
    }
    printf("\n");
    return 0;
}
