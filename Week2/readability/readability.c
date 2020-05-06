#include<stdio.h>
#include<string.h>
#include<cs50.h>
#include<math.h>

int main(void){

    string name = get_string("Enter the paragraph of text\n");

    int white_space_number = 0;
    int number_of_letters = 0;
    int ending_symbol_number = 0;
    int symbol_number = 0;

    for(int i = 0; i < strlen(name); i++){

        if(name[i] == ' '){
            white_space_number++;
        }
        else if(name[i] == '.' || name[i] == '?' || name[i] == '!'){
            ending_symbol_number++;
        }
        else if(name[i] == ',' || name[i] == ';' || name[i] == '"' || name[i] == '\'' || name[i] == ':' || name[i] == '+' || name[i] == '-' || name[i] == '/' || name[i] == '>' || name[i] == '<')
        {
            symbol_number++;
        }

    }
    //no. of words = no. of white spaces + no. of ending symbols
    //no. of sentences = number of ending symbols
    //no. of letters = total letters - (white spaces + ending symbols + symbols)

    int total_words = white_space_number + 1; //1 because of the last full stop
    int total_sentences = ending_symbol_number;
    number_of_letters = strlen(name) - (white_space_number + ending_symbol_number + symbol_number);

    //L = number of letters per 100 words
    //L = number of letters per word * 100
    double L = (number_of_letters / (double) total_words) * 100;

    //S = number of sentences per 100 words
    //S = number of sentences per word * 100
    double S = (total_sentences / (double) total_words) * 100;

    double index = (0.0588 * L) - (0.296 * S) - 15.8;
    int level = round(index);

    if(level >= 16){
        printf("Grade 16+\n");
    }
    else if(level < 1){
        printf("Before Grade 1\n");
    }
    else{
        printf("Grade %i\n", level);
    }
}
