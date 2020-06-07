#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //checking for correct input
    if(argc != 2){
        printf("Incorrect Usage");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    //checking if file specified can be opened
    if(file == NULL){
        printf("File specified can't be opened");
        return 2;
    }

    FILE *img;
    char filename[4];
    unsigned char *data = malloc(512);
    int serial = 0;

    while(fread(data, 512, 1, file)){

        //checking if the data found corresponds to a jpeg file
        if(data[0] == 0xff && data[1] == 0xd8 && data[2] == 0xff && (data[3] & 0xf0) == 0xe0){
            printf("reached4");
            //checking if a new file needs to be created
            if(serial > 0){
                fclose(img);
            }

            //generating name of the file
            sprintf(filename, "%03d.jpg", serial);

            img = fopen(filename, "w");

            //checking if output creation is successful
            if(img == NULL){
                fclose(file);
                free(data);
                printf("File creation unsuccessful %s", filename);
                return 3;
            }

            serial++;

        }

        //looking for JPEG file already open
        if(serial > 0){
            fwrite(data, 512, 1, img);
        }
    }

    fclose(file);
    fclose(img);
    free(data);
    return 0;
}
