#include<stdio.h>
#include<string.h>
#include<cs50.h>
#include<stdbool.h>
#include<ctype.h>

static char changed(char A, string KEY){
    bool lowercase = true;
    if((int)A >= 65 && (int)A <= 90){
        lowercase = false;
    }

    if(lowercase && isalpha(A)){
        return(tolower(KEY[(int)A - 97]));
    }
    else if(isalpha(A)){
        return toupper(KEY[(int) A - 65]);
    }
    else{
        return A;
    }
}

static bool key_check(string KEY){
    int n = strlen(KEY);

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(KEY[i] == KEY[j]){
                return false;
            }
        }
    }
    return true;
}

int main(int argc, string argv[]){
    bool valid = false;

    if(argc == 2){ //first check: the number of arguments
        valid = true;
    }
    else{
        printf("Enter only 2 arguments. \nUsage: ./substitution KEY\n");
        return 1;
    }

    if(valid){
        string n = argv[1];
        for(int i = 0; i < strlen(n); i++){

            if((int) n[i] < 65 || (int) n[i] > 122 || ( (int) n[i] > 90 && (int) n[i] < 97)){
                valid = false; //second check: all the characters in the key should be alphabets
                break;
            }
            else{
                valid = true;
            }
        }
    }

    if(strlen(argv[1]) != 26){ //third check: the key's length should be equal to 26
        valid = false;
    }

    if(!(key_check(argv[1]))){ //fourth check: the key should not have repeating characters
        valid = false;
    }

    if(!valid){
        printf("Enter a key with 26 different alphabets\n");
        return 1;
    }

    string s = get_string("plaintext: ");
    printf("ciphertext: ");
    for(int i = 0; i < strlen(s); i++){
        printf("%c", changed(s[i], argv[1]));
    }
    printf("\n");
    return 0;
}
