#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //iterating over all the pixels
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){

            //obtaining original rgb values
            int r = image[i][j].rgbtRed;
            int g = image[i][j].rgbtGreen;
            int b = image[i][j].rgbtBlue;

            //calculating avg of the rgb values
            int avg = round((r + g + b) / 3.0);

            //setting each of the values equal to the average for that very pixel
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
     //iterating over all the pixels
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){

            //obtaining original rgb values
            int r = image[i][j].rgbtRed;
            int g = image[i][j].rgbtGreen;
            int b = image[i][j].rgbtBlue;

            //calculating the sepia values
            int sepiaRed = round(.393 * r + .769 * g + .189 * b);
            int sepiaGreen = round(.349 * r + .686 * g + .168 * b);
            int sepiaBlue = round(.272 * r + .534 * g + .131 * b);

            //setting the value equal to 255 if it goes greater than 255
            if (sepiaRed > 255){
                sepiaRed = 255;
            }
            if (sepiaGreen > 255){
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255){
                sepiaBlue = 255;
            }

            //setting the values to the calculated Sepia values
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp; //temp variable to be used later

    //iterating over all pixels
    for(int i = 0; i < height; i++){

        for(int j = 0; j < width/2; j++){

            //we swap the pixels of the right side to the pixels on the left side.
            temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE newImage[height][width];

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){

            int avgR = 0;
            int avgG = 0;
            int avgB = 0;
            float count = 0;
            for(int r = -1; r <= 1; r++){ //rows around current pixel
                for(int c = -1 ; c <= 1; c++){ //columns around current pixel

                    if( i + r >= 0 && i + r < height && j + c >= 0 && j + c < width){
                        avgR += image[i + r][j + c].rgbtRed;
                        avgG += image[i + r][j + c].rgbtGreen;
                        avgB += image[i + r][j + c].rgbtBlue;
                        count++;
                    }
                }
            }
            //putting the obtained averages in place in the newImage
            newImage[i][j].rgbtRed = round(avgR/count);
            newImage[i][j].rgbtGreen = round(avgG/count);
            newImage[i][j].rgbtBlue = round(avgB/count);
        }
    }

    //now we have newImage as our blurred image, we just have to replace the values of images now.
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            image[i][j] = newImage[i][j];
        }
    }
    return;
}
